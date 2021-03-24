#ifndef __PIC_H__
#define __PIC_H__

#define PIC_PORT_MASTER_COMMAND 0x20
#define PIC_PORT_MASTER_DATA 0x21

#define PIC_PORT_SLAVE_COMMAND 0xA0
#define PIC_PORT_SLAVE_DATA 0xA1

#define PIC_INTERRUPT_OFFSET 0x20


#define PIC_COMMAND_DISABLE 0xFF
#define PIC_EOI 0x20

#define PIC_ICW1_ICW4		0x01
#define PIC_ICW1_SINGLE		0x02
#define PIC_ICW1_INTERVAL	0x04
#define PIC_ICW1_LEVEL4		0x08
#define PIC_ICW1_INIT		0x10

#define PIC_ICW4_8086		0x01
#define PIC_ICW4_AUTO		0x02
#define PIC_ICW4_BUF_SLAVE	0x08
#define PIC_ICW4_BUF_MASTER	0x0C
#define PIC_ICW4_SFNM		0x10

void PIC_init();
void PIC_send_EOI(int irq);

#endif