#include <stddef.h>

#include "globals.h"
#include "pagination.h"

static void* heap_pointer;

void Page_Allocator_init()
{
	int i;

	heap_pointer  = (uint32_t) (&KERNEL_BASE_ADDRESS);
	heap_pointer += (uint32_t) (&KERNEL_PAGE_SIZE) * PAGE_SIZE;
}

void* Page_Allocator_allocate_pages(int count)
{
	void* output = NULL;
	Multiboot_Memory_Map_Entry* entry;

	if(count <= 0)
		return NULL;

	for(entry = (Multiboot_Memory_Map_Entry*) (bootloader_info->mmap_address);
		entry < (Multiboot_Memory_Map_Entry*) (bootloader_info->mmap_address + bootloader_info->mmap_length);
		entry = (Multiboot_Memory_Map_Entry*) ((uint32_t) entry + entry->size + sizeof(entry->size)))
	{
		if(entry->type != Available_Memory)
			continue;

		if(entry->length < (count * PAGE_SIZE))
			continue;

		if((entry->address + entry->length) > (heap_pointer + count * PAGE_SIZE))
		{
			if(entry->address > heap_pointer)
				heap_pointer = entry->address;

			output = heap_pointer;
			heap_pointer += count * PAGE_SIZE;
			return output;
		}
	}

	return NULL;
}