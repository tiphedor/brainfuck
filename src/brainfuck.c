/**
 *	src/brainfuck.c
 *	Author: Martin "tiphedor" STEFFEN <mail@tiph.io>
 *
 *	Distributed under the terms of the MIT licence, see the LICENCE
 *	file for more details.
 */

#include "brainfuck.h"

/**
 * 	When a '[' is encountered, this function will look for the corresponding ']'
 *	in order to complete the loop.
 */
int bf_find_matching_endwhile(char *bf, int i)
{
	int search = 0;
	while(bf[++i])
	{
		if( bf[i] == '[' )
			search++;
		if ( bf[i] == ']' && search == 0)
			return i;
		if (bf[i] == ']' && search > 0)
			search--;
	}

	return (-1);
}

/**
 * 	At the end of a loop, if we need to loop back, this function will locate
 *	the start '[' tag.
 */
int bf_find_matching_startwhile(char *bf, int i)
{
	int search = 0;
	while(bf[--i])
	{
		if( bf[i] == ']' )
			search++;
		if ( bf[i] == '[' && search == 0)
			return i;
		if (bf[i] == '[' && search > 0)
			search--;
	}

	return (-1);
}

/**
 * 	Detects if a char is a valid brainfuck token
 */
int is_bfchar(char c) {
	return (c == '>' || c == '<' || c == '+' || c == '-' || c == '.' || c == ',' || c == '[' || c == ']');
}

/**
 * 	Runs the code located in the `code` string, using the `bf_array`.
 * 	`bf_array` and `code` must be valid strings, with actual data, as
 * 	no checks will be made.
 */
int bf_runcode(char *bf_array, char *code, int bf_array_len) {
	int i = 0;
	int ptr = 0;

	while(code[i]) {
		char instruction = code[i];
		/* Yeah, a lot of IFs statement is sub-optimal, but come on... for one line of action, who cares ? */
		if (instruction == '<') { /* ptr-- */
			if (ptr == 0)
				return (puterror("Runtime error: pointer reached a negative value.\n"));
			ptr--;
		} else if (instruction == '>') { /* ptr++ */
			if(ptr == bf_array_len - 1)
				return (puterror("Runtime error: pointer exceeded maximal value.\n"));
			ptr++;
		} else if (instruction == '+') /* arr[ptr]++ */
			bf_array[ptr]++;
		else if (instruction == '-') /* arr[ptr]-- */
			bf_array[ptr]--;
		else if (instruction == '.') /* write(arr[ptr]) */
			writechar(bf_array[ptr]);
		else if (instruction == ',') /* read(arr[ptr]) */
			readchar(&(bf_array[ptr]));
		else if (instruction == '[' && bf_array[ptr] == 0 ) {
			/* Found [ but the pointed byte is null, skipping branch & jumping to matchng ] */
			i = bf_find_matching_endwhile(code, i);
		} else if (instruction == '[' && bf_array[ptr] != 0 ) {
			/* Found [ - pointed byte is non-null - entering branch */
		} else if (instruction == ']' && bf_array[ptr] != 0 ) {
			/* Found ] and byte is non null - looping back to matching ] */
			i = bf_find_matching_startwhile(code, i);
		}
		i++;
	}

	return (1);
}
