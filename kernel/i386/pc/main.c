#include <stdint.h>

#include "gdt.h"
#include "globals.h"
#include "multiboot.h"

void kmain(Multiboot_Info* info, uint32_t magic)
{
	bootloader_info = info;

	GDT_initialize_table ();

	while(true);
}
