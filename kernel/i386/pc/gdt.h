#ifndef __GDT_H__
#define __GDT_H__

#include <stdint.h>

typedef struct GDT_Entry GDT_Entry;
struct GDT_Entry
{
	int low_limit : 16;
	int low_base : 24;
	int access : 8;
	int high_limit : 4;
	int flags : 4;
	int high_base : 8;
} __attribute__((packed));

typedef struct GDT_Descriptor GDT_Descriptor;
struct GDT_Descriptor
{
	uint16_t size;
	uint32_t offset;
} __attribute__((packed));

#define GDT_SEGMENT(base, limit, access, flags) \
	(GDT_Entry) {								\
		(uint32_t)(limit) & 0xFFFF,				\
		(uint32_t)(base) & 0xFFFFFF, 			\
		access,									\
		(uint32_t)(limit) >> 16 & 0xF,			\
		flags,									\
		(uint32_t)(base) >> 24 & 0xFF			\
	}

void GDT_initialize_table();

#endif