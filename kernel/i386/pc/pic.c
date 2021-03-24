#include <stdint.h>

#include "asm.h"
#include "pic.h"

void PIC_init()
{
	uint8_t mask_master, mask_slave;

	inb(PIC_PORT_MASTER_DATA, mask_master);
	inb(PIC_PORT_SLAVE_DATA,  mask_slave);

	outb(PIC_PORT_MASTER_COMMAND, PIC_ICW1_INIT | PIC_ICW1_ICW4);
	outb(PIC_PORT_SLAVE_COMMAND,  PIC_ICW1_INIT | PIC_ICW1_ICW4);

	outb(PIC_PORT_MASTER_DATA, PIC_INTERRUPT_OFFSET);
	outb(PIC_PORT_SLAVE_DATA,  PIC_INTERRUPT_OFFSET + 8);

	outb(PIC_PORT_MASTER_DATA, 4);
	outb(PIC_PORT_SLAVE_DATA,  2);

	outb(PIC_PORT_MASTER_DATA, PIC_ICW4_8086);
	outb(PIC_PORT_SLAVE_DATA,  PIC_ICW4_8086);

	outb(PIC_PORT_MASTER_DATA, mask_master);
	outb(PIC_PORT_SLAVE_DATA,  mask_slave);
}

void PIC_send_EOI(int irq_id)
{
	if(irq_id >= PIC_INTERRUPT_OFFSET && irq_id <= PIC_INTERRUPT_OFFSET + 15)
	{
		if(irq_id >= PIC_INTERRUPT_OFFSET + 8)
			outb(PIC_PORT_SLAVE_COMMAND, PIC_EOI);

		outb(PIC_PORT_MASTER_COMMAND, PIC_EOI);
	}
}