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

	// Starting
	_console_column_position = 0;
	_console_line_position = 0;

	// Just put a lot of spaces (' ')
	for (i = 0; i < MAX_LINES; i++) {
		for (j = 0; j < MAX_COLUMNS; j++) {
			console_put_char(' ');
		}
	}

	// Position: (0, 0)
	_console_column_position = 0;
	_console_line_position = 0;
}

void console_init()
{
	// Set the default text and background color
	console_set_text_color(DEFAULT_TEXT_COLOR);
	console_set_background_color(DEFAULT_BACKGROUND_COLOR);

	// Initial cleaning
	clear_all();

}

void console_scroll_down()
{
	unsigned int i;
	char *console_ptr = CONSOLE_ADDR;

	for (i = 0; i < MAX_LINES * (MAX_COLUMNS - 1) * 2; i++) {
		console_ptr[i] = console_ptr[i + MAX_COLUMNS];
		console_ptr[i + 1] = console_ptr[i + MAX_COLUMNS + 1];
	}


}

void console_put_char(char c)
{
	unsigned int console_position;
	char *console_ptr = CONSOLE_ADDR;

	if (c == '\n') {
		_console_column_position = 0;
		_console_line_position++;
		return;
	}
	// Calcule the memory position
	console_position = (_console_line_position*MAX_COLUMNS + _console_column_position) * 2;

	// Write the byte respecting the color
	console_ptr[console_position] = c;
	console_ptr[console_position + 1] = C(_console_text_color, _console_background_color);

	// Move the reference pointer to next position
	_console_column_position++;
	if (_console_column_position == MAX_COLUMNS) {
		_console_column_position = 0;
		_console_line_position++;

		// TODO: implement console scrolling
		if (_console_line_position == MAX_LINES) {
			_console_line_position = 0;
		}
	}
}

void console_write_text(char *msg)
{
	char *ptr = msg;

	// Put byte-to-byte
	while (*ptr != '\0') {
		console_put_char(*ptr++);
	}
}