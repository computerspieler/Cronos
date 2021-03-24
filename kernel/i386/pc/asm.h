#ifndef __ASM_H__
#define __ASM_H__

#include <stdint.h>

#define enable_interrupt()	\
	asm("sti");

#define disable_interrupt()	\
	asm("cli");

#define outb(port, data) 								\
	asm volatile (										\
		"mov %0, %%dx\n									\
		 mov %1, %%al\n									\
		 out %%al, %%dx"								\
		:												\
		: "r"((uint16_t) (port)), "r"((uint8_t) (data))	\
		: "%dx", "%al");

#define inb(port, data) 							\
	asm volatile (									\
		"mov %1, %%dx\n								\
		 in %%dx, %%al\n							\
		 mov %%al, %0"								\
		: "=r"((uint8_t) (data))					\
		: "r"((uint16_t) (port))					\
		: "%dx", "%al");

#endif