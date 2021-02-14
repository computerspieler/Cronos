#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "multiboot.h"
#include "tss.h"

static Multiboot_Info* bootloader_info;
extern Task_State kernel_tss;

#endif