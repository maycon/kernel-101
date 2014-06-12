/**
 * string.c
 */

#include "string.h"


void *memset(void *src, uint8 c, size_t n)
{
	uint32 i;

	for (i = 0; i < n; i++) {
		src[i] = (char)c;
	}

	return src;
}