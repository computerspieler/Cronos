#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "task.h"

void scheduler_init ();

int scheduler_add_task(void* code_entry, int code_segment_size);

void  scheduler_switch_task();
Task* scheduler_retrieve_actual_task();

#endif