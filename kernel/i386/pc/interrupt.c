#include <stddef.h>

#include "idt.h"
#include "segments.h"

extern uint32_t interrupt_table_size;
extern uint32_t* interrupt_table_ptr;

static IDT_Entry idt_entries[256];

void IDT_initialize_table()
{
	int i;
	IDT_Descriptor descriptor;

	descriptor.offset = idt_entries;
	descriptor.size = sizeof(idt_entries);

	for(i = 0; i < 256; i++)
		idt_entries[i] = IDT_SEGMENT(interrupt_table_ptr[i], KERNEL_CODE_SEGMENT_INT, 0xE, 0b1000);

	asm ("lidt (%0)" : : "r" (&descriptor));
}

void general_interrupt_handler(uint32_t irq_id)
{
}
