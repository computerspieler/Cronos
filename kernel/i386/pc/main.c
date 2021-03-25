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

#define VIDEO_BASE_ADDRESS (uint8_t*) (0xB8000)

void task_a()
{
	while(true)
		*VIDEO_BASE_ADDRESS = 'A';
}

void task_b()
{
	while(true)
		*VIDEO_BASE_ADDRESS = 'B';
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

	PIC_init();

	enable_interrupt();

	while(true);
}
