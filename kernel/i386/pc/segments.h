#ifndef __SEGMENTS_H__
#define __SEGMENTS_H__

#include "gdt.h"

#define KERNEL_CODE_SEGMENT_STR "$0x08"
#define KERNEL_CODE_SEGMENT_INT 0x08
#define KERNEL_DATA_SEGMENT_STR "$0x10"
#define KERNEL_DATA_SEGMENT_INT 0x10

#define USERLAND_CODE_SEGMENT_STR "$0x20"
#define USERLAND_CODE_SEGMENT_INT 0x20
#define USERLAND_DATA_SEGMENT_STR "$0x28"
#define USERLAND_DATA_SEGMENT_INT 0x28

void GDT_initialize_table();

#endif
