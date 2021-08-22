#ifndef __TASK_STATE_H__
#define __TASK_STATE_H__

typedef struct Task_Register_State Task_Register_State;
struct Task_Register_State
{
	uint32_t cr4;
	uint32_t cr3;
	uint32_t cr0;
	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
	uint32_t _unused;
	uint32_t ebx;
	uint32_t edx;
	uint32_t ecx;
	uint32_t eax;
	uint32_t eip;
	uint16_t cs;
	uint16_t _unused_1;
	uint32_t eflags;
	uint32_t esp;
	uint16_t ss;
} __attribute__((packed));


#endif
