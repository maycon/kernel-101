/**
 * kconsole.c
 */

#include "kconsole.h"

// colors
static unsigned int _console_text_color;
static unsigned int _console_background_color;

// positions
static unsigned int _console_line_position;
static unsigned int _console_column_position;


void console_set_text_color(unsigned int color)
{
	_console_text_color = color;
}

void console_set_background_color(unsigned int color)
{
	_console_background_color = color;
}

void clear_all()
{
	unsigned int i, j, console_position;
	char *console_ptr = CONSOLE_ADDR;

	for (i = 0; i < MAX_LINES; i++) {
		for (j = 0; j < MAX_COLUMNS; j++) {
			console_position = (i*MAX_LINES + j) * 2;
			console_ptr[console_position] = ' ';
			console_ptr[console_position + 1] = C(_console_text_color, _console_background_color);
		}
	}
}

void console_init()
{
	console_set_text_color(DEFAULT_TEXT_COLOR);
	console_set_background_color(DEFAULT_BACKGROUND_COLOR);
	clear_all();	
}

void console_write_text(char *ptr)
{

}