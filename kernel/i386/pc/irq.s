.code32
.altmacro

# Handlers
.macro INTERRUPT_HANDLER id
	.global irq\id\()_handler_entry
	irq\id\()_handler_entry:
# Save registers' state
		pushal
		mov %cr0, %eax
		push %eax
		mov %cr3, %eax
		push %eax
		mov %cr4, %eax
		push %eax
		
		mov $\id, %eax
		push %eax
		call general_interrupt_handler
		pop %eax

# Retreive registers' state
		pop %eax
		mov %eax, %cr4
		pop %eax
		mov %eax, %cr3
		pop %eax
		mov %eax, %cr0
		popal

# Set the segments
		push %ax
		mov $(5 * 8) | 3, %ax
		mov %ax, %ds
		mov %ax, %es
		mov %ax, %fs
		mov %ax, %gs
		pop %ax

		iret 
.endm

.section .text
.set i, 0
.rept 256
	INTERRUPT_HANDLER %i
	.set i, i+1
.endr

# Table
.macro INTERRUPT_ENTRY id
	.long irq\id\()_handler_entry
.endm

.section .data
.global interrupt_table
interrupt_table:
	.set i, 0
	.rept 256
		INTERRUPT_ENTRY %i
		.set i, i+1
	.endr

.global interrupt_table_size
interrupt_table_size: .long . - interrupt_table

.global interrupt_table_ptr
interrupt_table_ptr: .long interrupt_table
