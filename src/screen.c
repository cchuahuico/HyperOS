#include "screen.h"

#define FRAMEWIDTH 80
#define FRAMEHEIGHT 25
#define FRAMESIZE (FRAMEWIDTH * FRAMEHEIGHT)
#define FRAMEADDR 0xB8000

#define VGACTRLREG 0x3D4
#define VGADATAREG 0x3D5

#define CALCOFFSET(x, y) ((y) * FRAMEWIDTH + (x))

static u16int *frame_buffer = FRAMEADDR;
static u8int cur_x;
static u8int cur_y;

static void update_cursor(void)
{
    u16int loc = CALCOFFSET(cur_x, cur_y);
    io_out_byte(VGACTRLREG, 14);
    io_out_byte(VGADATAREG, loc >> 8);
    io_out_byte(VGACTRLREG, 15);
    io_out_byte(VGADATAREG, loc);
}

void screen_putc(u8int character)
{
    u16int data = character;
    data &= 0x0FFF; /* black background */
    data |= 0x0F00; /* white foreground */

    frame_buffer[CALCOFFSET(cur_x, cur_y)] = data;

    /* go to next line if whole line is taken */
    if (++cur_x == FRAMEWIDTH)
    {
        cur_x = 0;
        ++cur_y;
    }

    update_cursor();
}

void screen_puts(const char *str)
{
    int i;

    for (i = 0; str[i]; ++i)
        screen_putc(str[i]);
}

void screen_clear(void)
{
    int i;

    for (i = 0; i < FRAMESIZE; ++i)
        frame_buffer[i] = 0;
}

void screen_puti(u32int num)
{
    char stack[10];
    char *sptr = stack;

    if (num == 0)
    {
        screen_putc(48);
        return;
    }

    while (num != 0)
    {
        *sptr++ = num % 10 + 48;
        num = num / 10;
    }

    while ((sptr - stack) > 0)
    {
        screen_putc(*(--sptr));
    }
}
