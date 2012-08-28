#include "common.h"

void io_out_byte(u16int port, u8int data)
{
    asm volatile("outb %1, %0" ::
                 "d" (port), "a" (data));
}
