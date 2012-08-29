#include "screen.h"
#include "gdt.h"

int main(void)
{
    init_gdt();
    screen_clear();
    screen_puts("hello, world!");
    return 0;
}
