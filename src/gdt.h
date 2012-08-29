#ifndef GDT_H
#define GDT_H

#include "common.h"

typedef struct 
{
    u16int limit_low;
    u16int base_low;
    u8int base_mid;
    u8int access;
    u8int granularity;
    u8int base_high;
}__attribute__((packed)) segment_descriptor_t;

typedef struct
{
    u16int limit;
    u32int base;
}__attribute__((packed)) gdt_ptr_t;

void init_gdt(void);

#endif
