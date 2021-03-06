#ifndef __TSS_H__
#define __TSS_H__

#include <stddef.h>

typedef struct Task_State_Segment Task_State_Segment;

struct Task_State_Segment
{
	uint16_t link;	uint16_t unused_0;
	uint32_t esp0;
	uint16_t ss0;	uint16_t unused_1;
	uint32_t esp1;
	uint16_t ss1;	uint16_t unused_2;
	uint32_t esp2;
	uint16_t ss2;	uint16_t unused_3;
	uint32_t cr3;
	uint32_t eip;
	uint32_t eflags;
	uint32_t eax;
	uint32_t ecx;
	uint32_t edx;
	uint32_t ebx;
	uint32_t esp;
	uint32_t ebp;
	uint32_t esi;
	uint32_t edi;
	uint16_t es;	uint16_t unused_4;
	uint16_t cs;	uint16_t unused_5;
	uint16_t ss;	uint16_t unused_6;
	uint16_t ds;	uint16_t unused_7;
	uint16_t fs;	uint16_t unused_8;
	uint16_t gs;	uint16_t unused_9;
	uint16_t ldtr;	uint16_t unused_10; uint16_t unused_11;
	uint16_t iopb;
} __attribute__ ((packed));


#endif