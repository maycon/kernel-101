/**
 * kconsole.c
 */

#include "kconsole.h"

// colors
static uint32 _console_text_color;
static uint32 _console_background_color;

// positions
static uint32 _console_line_position;
static uint32 _console_column_position;

void console_init()
{
	// Set the default text and background color
	console_set_text_color(DEFAULT_TEXT_COLOR);
	console_set_background_color(DEFAULT_BACKGROUND_COLOR);

	// Initial cleaning
	clear_all();

}

void clear_all()
{
	uint32 i, j, console_position;
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


void console_scroll_down()
{
	uint32 i, j, console_position, next_position;
	char *console_ptr = CONSOLE_ADDR;

	// Shift the memory data
	for (i = 0; i < MAX_LINES - 1; i++) {
		for (j = 0; j < MAX_COLUMNS; j++) {
			console_position = (i*MAX_COLUMNS + j) * 2;
			next_position = console_position + 2*MAX_COLUMNS;

			console_ptr[console_position] = console_ptr[next_position];
			console_ptr[console_position + 1] = console_ptr[next_position + 1];
		}
	}

	// Insert a blank line at end of screen
	i = MAX_LINES - 1;
	for (j = 0; j < MAX_COLUMNS; j++) {
		console_position = (i*MAX_COLUMNS + j) * 2;
		next_position = console_position + 2*MAX_COLUMNS;

		console_ptr[console_position] = ' ';
		console_ptr[console_position + 1] = C(_console_text_color, _console_background_color);
	}
}

void console_set_text_color(uint32 color)
{
	_console_text_color = color;
}

void console_set_background_color(uint32 color)
{
	_console_background_color = color;
}


void console_put_char(char c)
{
	uint32 console_position;
	char *console_ptr = CONSOLE_ADDR;

	switch (c) {
		// Process the '\n' as the new line char
		case '\n':
			_console_column_position = 0;
			_console_line_position++;

			// Scroll at end of screen
			if (_console_line_position == MAX_LINES) {
				console_scroll_down();
				_console_line_position--;
			}
		break;

		default:
			// Calcule the memory position
			console_position = (_console_line_position*MAX_COLUMNS + _console_column_position) * 2;

			// Write the byte respecting the color
			console_ptr[console_position] = c;
			console_ptr[console_position + 1] = C(_console_text_color, _console_background_color);

			// Move the reference pointer to next position
			_console_column_position++;
			if (_console_column_position == MAX_COLUMNS) {
				console_put_char('\n');
			}
		break;
	}
}

void console_put_char_at(char c, uint32 line, uint32 column)
{
	uint32 console_line_position;
	uint32 console_column_position;

	// Save the current position
	console_line_position = _console_line_position;
	console_column_position = _console_column_position;

	// Write the char at position
	_console_line_position = line;
	_console_column_position = column;
	console_put_char(c);	

	// Restore
	_console_line_position = console_line_position;
	_console_column_position = console_column_position;
}


void console_write_text(char *msg)
{
	char *ptr = msg;

	// Put byte-to-byte
	while (*ptr != '\0') {
		console_put_char(*ptr++);
	}
}

void console_write_text_at(char *msg, uint32 line, uint32 column)
{
	uint32 console_line_position;
	uint32 console_column_position;

	// Save the current position
	console_line_position = _console_line_position;
	console_column_position = _console_column_position;

	// Write the message at position
	_console_line_position = line;
	_console_column_position = column;
	console_write_text(msg);	

	// Restore
	_console_line_position = console_line_position;
	_console_column_position = console_column_position;

}

void console_write_dec(uint32 num)
{
#define MAX_DIG_32 10

	unsigned int dec[MAX_DIG_32 + 1], i, pos, dig;

	dec[0] = 0; dec[1] = 1;

	for (i = 2; i <= MAX_DIG_32; i++) {
		dec[i] = dec[i - 1]*10;
	}

	i = MAX_DIG_32;
	while (num < dec[i]) i--;

	for (; i > 0; i--) {
		if (num >= dec[i]) {
			dig = num / dec[i];
			num = num % dec[i];
			console_put_char('0' + dig);
		} else {
			console_put_char('0');
		}
	}

#undef MAX_DIG_32
}

void console_write_hex(uint32 num)
{
	int32 i, val;

	console_write_text("0x");
	for (i = 28; i >= 0; i -= 4) {
		val = (num >> i) & 0xF;
		console_put_char(val < 0xA ? '0' + val : 'A' + val - 0xA);
	}
}