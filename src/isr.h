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


void init_idt(void);

#endif
