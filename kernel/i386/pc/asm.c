#include "asm.h"

void outb(uint16_t port, uint8_t data)
{
	asm volatile (
		"mov %0, %%dx \n \
		 mov %1, %%al"
		:
		: "r"(port), "r"(data)
		: "%dx", "%al");

	asm ("out %al, %dx");
}