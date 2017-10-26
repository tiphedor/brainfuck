/**
 *	src/brainfuck.h
 *	Author: Martin "tiphedor" STEFFEN <mail@tiph.io>
 *
 *	Distributed under the terms of the MIT licence, see the LICENCE
 *	file for more details.
 */


#ifndef BRAINFUCK_H
# define BRAINFUCK_H

# include "io.h"

int bf_find_matching_endwhile(char *bf, int i);
int bf_find_matching_startwhile(char *bf, int i);
int is_bfchar(char c);
int bf_runcode(char *bf_array, char *code, int bf_array_len);

#endif
