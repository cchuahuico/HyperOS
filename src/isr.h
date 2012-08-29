#ifndef ISR_H
#define ISR_H

#include "common.h"

typedef struct
{
    u16int handler_low;
    u16int selector;
    u8int reserved;
    u8int flags;
    u16int handler_high;
}__attribute__((packed)) interrupt_gate_t;

typedef struct
{
    u32int base;
    u16int limit;
}__attribute__((packed)) idt_ptr_t; 

typedef struct
{
    u32int interrupt_number;
    u32int error_code;
    u32int eip;
    u32int cs;
    u32int eflags;
    u32int esp;
    u32int ss;
} handler_context_t;

void init_idt(void);
void isr_handler(handler_context_t ctx);

#endif
