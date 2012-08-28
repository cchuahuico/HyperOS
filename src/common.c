#include "common.h"

void io_out_byte(unsigned short port, unsigned char data)
{
    asm volatile("outb %1, %0" ::
                 "d" (port), "a" (data));
}
