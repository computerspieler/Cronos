#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "multiboot.h"
#include "tss.h"

extern Multiboot_Info* bootloader_info;
extern Task_State kernel_tss;

extern uint32_t KERNEL_BASE_ADDRESS;
extern uint32_t KERNEL_PAGE_SIZE;

#endif