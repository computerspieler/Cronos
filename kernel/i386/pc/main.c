#include <stdint.h>
#include <string.h>

#include "asm.h"
#include "globals.h"
#include "interrupt.h"
#include "multiboot.h"
#include "pagination.h"
#include "pic.h"
#include "scheduler.h"
#include "segments.h"

Multiboot_Info* bootloader_info;

void task_a()
{
	while(true)
		outb(0xE9, 'A');
}

void task_b()
{
	while(true)
		outb(0xE9, 'B');
}

void kmain(Multiboot_Info* info, uint32_t magic)
{
	disable_interrupt();

	bootloader_info = info;

	GDT_initialize_table();
	IDT_initialize_table();
	Page_Allocator_init();

	scheduler_init();
	scheduler_add_task(task_a, 100);
	scheduler_add_task(task_b, 100);

	// Disable the PIC
	outb(PIC_PORT_MASTER_DATA, PIC_COMMAND_DISABLE);
	outb(PIC_PORT_SLAVE_DATA, PIC_COMMAND_DISABLE);

	enable_interrupt();

	while(true);
}
