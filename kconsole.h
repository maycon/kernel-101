#ifndef _KCONSOLE_H_
#define _KCONSOLE_H_

/**
 * kconsole.h
 */

#include "types.h"

// Start of console memory addres in P-Mode
#define CONSOLE_ADDR (char *)0xb8000


// console colors
#define COLOR_BLACK 0x0
#define COLOR_BLUE 0x1
#define COLOR_GREEN 0x2
#define COLOR_CYAN 0x3
#define COLOR_RED 0x4
#define COLOR_MAGENTA 0x5
#define COLOR_BROW 0x6
#define COLOR_LIGHT_GREY 0x7
#define COLOR_DARK_GREY 0x8
#define COLOR_LIGHT_BLUE 0x9
#define COLOR_LIGHT_GREEN 0xa
#define COLOR_LIGHT_CYAN 0xb
#define COLOR_LIGHT_RED 0xc
#define COLOR_LIGHT_MAGENTA 0xd
#define COLOR_LIGHT_BROWN 0xe
#define COLOR_WHITE 0xf

#define DEFAULT_TEXT_COLOR COLOR_LIGHT_GREY
#define DEFAULT_BACKGROUND_COLOR COLOR_BLACK

#define MAX_LINES 25
#define MAX_COLUMNS 80

#define C(t,b) ((b << 0x4) | t)

void console_init();

void clear_all();

void console_scroll_down();

void console_set_text_color(uint32 color);
void console_set_background_color(uint32 color);

void console_put_char(char c);
void console_put_char_at(char c, uint32 line, uint32 column);

void console_write_text(char *ptr);
void console_write_text_at(char *msg, uint32 line, uint32 column);

void console_write_hex(uint32 num);

#endif