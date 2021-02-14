#include "gdt.h"
#include "tss.h"

#define KERNEL_CODE_SEGMENT "$0x08"
#define KERNEL_DATA_SEGMENT "$0x10"

#define USERLAND_CODE_SEGMENT "$0x20"
#define USERLAND_DATA_SEGMENT "$0x28"

static Task_State kernel_tss;

static GDT_Entry gdt_entries[6];

void GDT_initialize_table()
{
	gdt_entries[0] = GDT_SEGMENT(0, 0, 0, 0);
	gdt_entries[1] = GDT_SEGMENT(0, 0xFFFFF, 0b10011010, 0b1100);	// Kernel code segment
	gdt_entries[2] = GDT_SEGMENT(0, 0xFFFFF, 0b10010010, 0b1100);	// Kernel data segment
	gdt_entries[3] = GDT_SEGMENT(&kernel_tss, sizeof(kernel_tss), 0b10001001, 0b100);	// Kernel TSS
	gdt_entries[4] = GDT_SEGMENT(0, 0xFFFFF, 0b11111010, 0b1100);	// Userland code segment
	gdt_entries[5] = GDT_SEGMENT(0, 0xFFFFF, 0b11110010, 0b1100);	// Userland data segment

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

	asm ("ljmp " KERNEL_CODE_SEGMENT ", $next");
	asm ("next:");
}