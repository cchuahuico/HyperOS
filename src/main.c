#include "screen.h"
#include "gdt.h"
#include "isr.h"

int main(void)
{
    init_gdt();
    init_idt();
    screen_clear();
    screen_puts("hello, world!\n");
    asm  volatile ("int $0x10");
    return 0;
}
