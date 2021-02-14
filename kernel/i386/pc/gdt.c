#include "gdt.h"

#define KERNEL_CODE_SEGMENT "$0x08"
#define KERNEL_DATA_SEGMENT "$0x10"

static GDT_Entry gdt_entries[] = {
	GDT_SEGMENT(0, 0, 0, 0),
	GDT_SEGMENT(0, 0xFFFFF, 0b10011010, 0b1100),	// Kernel code segment
	GDT_SEGMENT(0, 0xFFFFF, 0b10010010, 0b1100),	// Kernel data segment
	GDT_SEGMENT(0, 0xFFFFF, 0b11111010, 0b1100),	// Userland code segment
	GDT_SEGMENT(0, 0xFFFFF, 0b11110010, 0b1100),	// Userland data segment
};

void GDT_initialize_table()
{
	GDT_Descriptor descriptor;
	descriptor.offset = gdt_entries;
	descriptor.size = sizeof(gdt_entries);

	asm ("lgdt (%0)" : : "r" (&descriptor));

	// Set segments
	asm ("mov " KERNEL_DATA_SEGMENT ", %ax");
	asm ("mov %ax, %ds");
	asm ("mov %ax, %es");
	asm ("mov %ax, %fs");
	asm ("mov %ax, %gs");
	asm ("mov %ax, %ss");

	asm ("xchg %bx, %bx");
	asm ("ljmp " KERNEL_CODE_SEGMENT ", $next");
	asm ("next:");
	asm ("xchg %bx, %bx ");
}