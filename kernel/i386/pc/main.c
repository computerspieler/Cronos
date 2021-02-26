#include <stdint.h>
#include <string.h>

#include "asm.h"
#include "globals.h"
#include "interrupt.h"
#include "multiboot.h"
#include "pagination.h"
#include "pic.h"
#include "segments.h"

Multiboot_Info* bootloader_info;

void kmain(Multiboot_Info* info, uint32_t magic)
{
	disable_interrupt();

	bootloader_info = info;

	GDT_initialize_table ();
	IDT_initialize_table ();
	Page_Allocator_init ();

	// Disable the PIC
	outb (PIC_PORT_MASTER_DATA, PIC_COMMAND_DISABLE);
	outb (PIC_PORT_SLAVE_DATA, PIC_COMMAND_DISABLE);

	enable_interrupt();
	while(true);
}
