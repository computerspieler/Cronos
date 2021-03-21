#include "gdt.h"
#include "segments.h"
#include "tss.h"

static Task_State_Segment kernel_tss;

static GDT_Entry gdt_entries[6];

void GDT_initialize_table()
{
	GDT_Descriptor descriptor;
	descriptor.offset = gdt_entries;
	descriptor.size = sizeof(gdt_entries);

	gdt_entries[0] = GDT_SEGMENT(0, 0, 0, 0);
	gdt_entries[1] = GDT_SEGMENT(0, 0xFFFFF, 0b10011010, 0b1100);	// Kernel code segment
	gdt_entries[2] = GDT_SEGMENT(0, 0xFFFFF, 0b10010010, 0b1100);	// Kernel data segment
	gdt_entries[3] = GDT_SEGMENT(&kernel_tss, sizeof(kernel_tss), 0b10001001, 0b100);	// Kernel TSS
	gdt_entries[4] = GDT_SEGMENT(0, 0xFFFFF, 0b11111010, 0b1100);	// Userland code segment
	gdt_entries[5] = GDT_SEGMENT(0, 0xFFFFF, 0b11110010, 0b1100);	// Userland data segment

	asm ("lgdt (%0)" : : "r" (&descriptor));

	// Set segments
	asm ("mov " KERNEL_DATA_SEGMENT_STR ", %ax");
	asm ("mov %ax, %ds");
	asm ("mov %ax, %es");
	asm ("mov %ax, %fs");
	asm ("mov %ax, %gs");
	asm ("mov %ax, %ss");

	asm ("ljmp " KERNEL_CODE_SEGMENT_STR ", $next");
	asm ("next:");
}