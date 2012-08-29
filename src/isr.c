#include "isr.h"

#define MAXINTERRUPTGATES 256
#define CSSELECTOR 0x08

extern void reload_idt(void);

interrupt_gate_t idt[MAXINTERRUPTGATES];
idt_ptr_t idt_ptr;

static void set_interrupt_gate(u8int int_no, u32int hanlder, u16int selector, u8int flags)
{
    idt[int_no].handler_low = handler & 0xFFFF;
    idt[int_no].selector = selector;
    idt[int_no].reserved = 0;
    idt[int_no].flags = flags;
    idt[int_no].handler_high = handler >> 16;
}

void init_idt(void)
{
    idt_ptr.base = &idt;
    idt_ptr.limit = sizeof(interrupt_gate_t) * MAXINTERRUPTGATES - 1;

    memset(idt, 0, MAXINTERRUPTGATES);

    set_interrupt_gate(0, isr0, CSSELECTOR, 0x8E);
    set_interrupt_gate(1, isr1, CSSELECTOR, 0x8E);
    set_interrupt_gate(2, isr2, CSSELECTOR, 0x8E);
    set_interrupt_gate(3, isr3, CSSELECTOR, 0x8E);
    set_interrupt_gate(4, isr4, CSSELECTOR, 0x8E);
    set_interrupt_gate(5, isr5, CSSELECTOR, 0x8E);
    set_interrupt_gate(6, isr6, CSSELECTOR, 0x8E);
    set_interrupt_gate(7, isr7, CSSELECTOR, 0x8E);
    set_interrupt_gate(8, isr8, CSSELECTOR, 0x8E);
    set_interrupt_gate(9, isr9, CSSELECTOR, 0x8E);
    set_interrupt_gate(10, isr10, CSSELECTOR, 0x8E);
    set_interrupt_gate(11, isr11, CSSELECTOR, 0x8E);
    set_interrupt_gate(12, isr12, CSSELECTOR, 0x8E);
    set_interrupt_gate(13, isr13, CSSELECTOR, 0x8E);
    set_interrupt_gate(14, isr14, CSSELECTOR, 0x8E);
    set_interrupt_gate(15, isr15, CSSELECTOR, 0x8E);
    set_interrupt_gate(16, isr16, CSSELECTOR, 0x8E);
    set_interrupt_gate(17, isr17, CSSELECTOR, 0x8E);
    set_interrupt_gate(18, isr18, CSSELECTOR, 0x8E);
    set_interrupt_gate(19, isr19, CSSELECTOR, 0x8E);
    set_interrupt_gate(20, isr20, CSSELECTOR, 0x8E);
    set_interrupt_gate(21, isr21, CSSELECTOR, 0x8E);
    set_interrupt_gate(22, isr22, CSSELECTOR, 0x8E);
    set_interrupt_gate(23, isr23, CSSELECTOR, 0x8E);
    set_interrupt_gate(24, isr24, CSSELECTOR, 0x8E);
    set_interrupt_gate(25, isr25, CSSELECTOR, 0x8E);
    set_interrupt_gate(26, isr26, CSSELECTOR, 0x8E);
    set_interrupt_gate(27, isr27, CSSELECTOR, 0x8E);
    set_interrupt_gate(28, isr28, CSSELECTOR, 0x8E);
    set_interrupt_gate(29, isr29, CSSELECTOR, 0x8E);
    set_interrupt_gate(30, isr30, CSSELECTOR, 0x8E);
    set_interrupt_gate(31, isr31, CSSELECTOR, 0x8E);
}
