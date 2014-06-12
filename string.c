/**
 * string.c
 */

#include "string.h"


void *memset(void *ptr, uint8 c, size_t n)
{
	uint32 i;

	for (i = 0; i < n; i++) {
		((char *)ptr)[i] = (char)c;
	}

	return ptr;
}