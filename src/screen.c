#include "screen.h"
#include "common.h"

#define CALCOFFSET(x, y) ((y) * 80 + (x))
#define FRAMEWIDTH 80
#define FRAMEHEIGHT 25
#define FRAMESIZE (80 * 25)
#define FRAMEADDR 0xB8000
#define VGACTRLREG 0x3D4
#define VGADATAREG 0x3D5

static unsigned short *frame_buffer = FRAMEADDR;
static unsigned char cur_x;
static unsigned char cur_y;

static void update_cursor(void)
{
    unsigned short loc = CALCOFFSET(cur_x, cur_y);
    io_out_byte(VGACTRLREG, 14);
    io_out_byte(VGADATAREG, loc >> 8);
    io_out_byte(VGACTRLREG, 15);
    io_out_byte(VGADATAREG, loc);
}

void screen_putc(unsigned char character)
{
    unsigned short data = character;
    data &= 0x0FFF; /* black background */
    data |= 0x0F00; /* white foreground */

    frame_buffer[CALCOFFSET(cur_x, cur_y)] = data;

    /* go to next line if whole line is taken */
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
