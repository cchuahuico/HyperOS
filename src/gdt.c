#include "gdt.h"

#define MAXGDT 5
#define MEMMAX 0xFFFFFFFF

extern void reload_gdt(gdt_ptr_t *);

static segment_descriptor_t gdt[MAXGDT];
static gdt_ptr_t gdt_ptr;

static void set_descriptor(u8int idx, u32int base, 
        u32int limit, u8int access, u8int granularity)
{
    gdt[idx].limit_low = limit & 0x0000FFFF;
    gdt[idx].base_low = base & 0xFFFF;
    gdt[idx].base_mid = base & 0xFF0000;
    gdt[idx].base_high = base & 0xFF000000;
    gdt[idx].access = access;
    gdt[idx].granularity = limit & 0xF0000;
    gdt[idx].granularity |= granularity;
} 

void init_gdt(void)
{
    gdt_ptr.limit = sizeof(segment_descriptor_t) * 5 - 1;
    gdt_ptr.base = &gdt;

    set_descriptor(0, 0, 0, 0, 0);
    set_descriptor(1, 0, MEMMAX, 0x9A, 0xC0);
    set_descriptor(2, 0, MEMMAX, 0x92, 0xC0);
    set_descriptor(3, 0, MEMMAX, 0xFA, 0xC0);
    set_descriptor(4, 0, MEMMAX, 0xF2, 0xC0);

    reload_gdt(&gdt_ptr);
}
