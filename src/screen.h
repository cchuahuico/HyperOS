#ifndef SCREEN_H
#define SCREEN_H

#include "common.h"

void screen_putc(u8int character);
void screen_puts(const char *string);
void screen_clear(void);

#endif
