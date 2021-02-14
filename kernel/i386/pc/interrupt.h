#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include "idt.h"

void IDT_initialize_table();
void general_interrupt_handler(uint32_t irq_id);

#endif