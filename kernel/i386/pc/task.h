#ifndef __TASK_H__
#define __TASK_H__

#include <stdint.h>

typedef enum Task_State Task_State;
enum Task_State
{
	NONE,
	RUNNING,
	READY,
	BLOCKED,
	SUSPENDED
};

typedef struct Task_Register_State Task_Register_State;
struct Task_Register_State
{
	uint32_t cr4;
	uint32_t cr3;
	uint32_t cr0;
	uint32_t eflags;
	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
	uint32_t esp;
	uint32_t ebx;
	uint32_t edx;
	uint32_t ecx;
	uint32_t eax;
	uint32_t eip;
} __attribute__((packed));

typedef struct Task Task;
struct Task
{
	Task_Register_State cpu_state;
	Task_State state;
};

#define MAX_TASKS 256
#define PAGES_PER_STACK 1


#endif