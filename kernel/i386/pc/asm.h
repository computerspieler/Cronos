#ifndef __ASM_H__
#define __ASM_H__

#include <stdint.h>

#define enable_interrupt()	\
	asm("sti");

#define disable_interrupt()	\
	asm("cli");

void	outb(uint16_t port, uint8_t data);

#endif