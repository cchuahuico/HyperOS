#include "screen.h"
#include "common.h"

#define CALCOFFSET(x, y) ((y) * 80 + (x))

static unsigned short *frame_buffer = FRAMEADDR;
static unsigned char cur_x;
static unsigned char cur_y;

static void update_cursor(void)
{
    unsigned short loc = CALCOFFSET(cur_x, cur_y);
    io_out_byte(0x3D4, 14);
    io_out_byte(0x3D5, loc >> 8);
    io_out_byte(0x3D4, 15);
    io_out_byte(0x3D5, loc);
}

void screen_putc(unsigned char character)
{
    unsigned short data = character;
    data &= 0x0FFF;
    data |= 0x0F00;

    frame_buffer[CALCOFFSET(cur_x, cur_y)] = data;

    if (++cur_x == 80)
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
