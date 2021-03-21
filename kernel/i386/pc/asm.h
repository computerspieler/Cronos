#ifndef __ASM_H__
#define __ASM_H__

#include <stdint.h>

#define enable_interrupt()	\
	asm("sti");

#define disable_interrupt()	\
	asm("cli");

#define outb(port, data) 							\
	asm volatile (									\
		"mov %0, %%dx\n								\
		 mov %1, %%al\n								\
		 out %%al, %%dx"							\
		:											\
		: "r"((uint16_t) port), "r"((uint8_t) data)	\
		: "%dx", "%al");

#endif