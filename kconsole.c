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


void console_scroll_down()
{
	unsigned int i, j, console_position, next_position;
	char *console_ptr = CONSOLE_ADDR;

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

void console_set_text_color(unsigned int color)
{
	_console_text_color = color;
}

void console_set_background_color(unsigned int color)
{
	_console_background_color = color;
}


void console_put_char(char c)
{
	unsigned int console_position;
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

void console_put_char_at(char c, unsigned int line, unsigned int column)
{
	unsigned int console_line_position;
	unsigned int console_column_position;

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

void console_write_text_at(char *msg, unsigned int line, unsigned int column)
{
	unsigned int console_line_position;
	unsigned int console_column_position;

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