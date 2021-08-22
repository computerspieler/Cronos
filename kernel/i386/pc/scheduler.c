#include <string.h>

#include "task.h"
#include "pagination.h"
#include "segments.h"

static Task tasks[MAX_TASKS];
static int task_pointer;

void scheduler_init ()
{
	int i;

	task_pointer = -1;

	for(i = 0; i < MAX_TASKS; i++)
		memset(&tasks[i], 0, sizeof(Task));
}

Task* look_for_available_task()
{
	int i;

	for(i = 0; i < MAX_TASKS; i++)
		if(tasks[i].state == NONE)
			return &tasks[i];
	
	return NULL;
}

int scheduler_add_task(void* code_entry, int code_segment_size)
{
	Task* task = look_for_available_task();
	void* stack_page;

	if(!task)
		return -1;
	
	stack_page = Page_Allocator_allocate_pages(PAGES_PER_STACK);
	if(!stack_page)
		return -1;

	task->state = RUNNING;

	memset(&task->cpu_state, 0, sizeof(Task_Register_State));
	task->cpu_state.cs = USERLAND_CODE_SEGMENT_INT | 3;
	task->cpu_state.eip = code_entry;	
	
	task->cpu_state.cr0 = 0b1;
	task->cpu_state.eflags = 0b1000000010;

	task->cpu_state.esp = stack_page;
	task->cpu_state.ss = USERLAND_DATA_SEGMENT_INT | 3;

	return 0;
}

void scheduler_switch_task()
{
	task_pointer ++;

	if(tasks[task_pointer].state == NONE)
		task_pointer = 0;
}

Task* scheduler_retrieve_actual_task()
{
	if(task_pointer >= 0)
		return &tasks[task_pointer];

	return NULL;
}
