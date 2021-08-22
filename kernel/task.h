#ifndef __TASK_H__
#define __TASK_H__

#include <stdint.h>

#include "task_state.h"

typedef enum Task_State Task_State;
enum Task_State
{
	NONE,
	RUNNING,
	READY,
	BLOCKED,
	SUSPENDED
};

typedef struct Task Task;
struct Task
{
	Task_Register_State cpu_state;
	Task_State state;
};

#define MAX_TASKS 256
#define PAGES_PER_STACK 1

#endif
