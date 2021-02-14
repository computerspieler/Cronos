#include <stdint.h>

#include "asm.h"
#include "globals.h"
#include "interrupt.h"
#include "multiboot.h"
#include "pic.h"
#include "segments.h"

void kmain(Multiboot_Info* info, uint32_t magic)
{
	disable_interrupt();

	bootloader_info = info;

	GDT_initialize_table ();
	IDT_initialize_table ();

	// Disable the PIC
	outb(PIC_PORT_MASTER_DATA, PIC_COMMAND_DISABLE);
	outb(PIC_PORT_SLAVE_DATA, PIC_COMMAND_DISABLE);

	enable_interrupt();
	while(true);
}
