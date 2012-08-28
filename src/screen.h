#ifndef SCREEN_H
#define SCREEN_H

#define FRAMEWIDTH 80
#define FRAMEHEIGHT 25
#define FRAMESIZE (80 * 25)
#define FRAMEADDR 0xB8000

void screen_putc(unsigned char character);
void screen_puts(const char *string);
void screen_clear(void);

#endif
