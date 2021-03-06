/**
 *	src/io.c
 *	Author: Martin "tiphedor" STEFFEN <mail@tiph.io>
 *
 *	Distributed under the terms of the MIT licence, see the LICENCE
 *	file for more details.
 */

#include "io.h"

/**
 *	Writes an error message onto stderr
 */
int		puterror(const char* err) {
	write(2, err, strlen(err));
	return (0);
}

/**
 *	Writes a single character onto stdout
 */
void	writechar(char c) {
	write(1, &c, 1);
}

/**
 *	Reads a single character from stdin
 */
void	readchar(char *c) {
	read(1, c, 1);
}

/**
 *	Reads the contents the file located at filename into destination.
 *	destination is allocated by chunks of 64 bytes, and \0 terminated.
 */
int		readfile(char* filename, char** destination) {
	int file = open(filename, O_RDONLY);
	int current_size = 0;
	int current_used_size = 0;
	char current_char = 0;

	if(file == -1) {
		puterror("Error, could not open specified file: ");
		puterror(strerror(errno));
		puterror(".\n");
		return (0);
	}

	/* Allocating the first 64 bytes */
	*destination = (char*)malloc(sizeof(char)*64);
	if (*destination == 0) {
		puterror("Memory error.\n");
		return (0);
	}
	current_size = 64;

	/* Iterate all charcters */
	while (read(file, &current_char, 1)) {
		if(current_size == current_used_size) {
			/* Buffer size exceeded, reallocating 64 more bytes */
			current_size += 64;
			*destination = (char*)realloc(*destination, current_size);
			if (*destination == 0) {
				puterror("Memory error.\n");
				return (0);
			}
		}
		/* Actual copy */
		(*destination)[current_used_size] = current_char;
		current_used_size++;
	}
	/* Is there still enough room for the \0 ? */
	if(current_size == current_used_size)
		*destination = (char*)realloc(*destination, current_size + 1);
	(*destination)[current_used_size] = 0;
	return (1);
}
