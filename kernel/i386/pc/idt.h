#ifndef __IDT_H__
#define __IDT_H__

typedef struct IDT_Entry IDT_Entry;
struct IDT_Entry
{
	int low_offset : 16;
	int selector : 16;
	int unused : 8;
	int gate_type : 4;
	int flags : 4;
	int high_offset : 16;
} __attribute__((packed));

typedef struct IDT_Descriptor IDT_Descriptor;
struct IDT_Descriptor
{
	uint16_t size;
	uint32_t offset;
} __attribute__((packed));

#define IDT_SEGMENT(offset, selector, gate_type, flags) \
	(IDT_Entry) {										\
		(uint32_t) (offset) & 0xFFFF,					\
		(uint16_t) (selector),							\
		0,												\
		gate_type,										\
		flags,											\
		(uint32_t) (offset) >> 16 & 0xFFFF,				\
	}

#endif