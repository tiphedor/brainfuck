/**
 *	src/main.c
 *	Author: Martin "tiphedor" STEFFEN <mail@tiph.io>
 *
 *	Distributed under the terms of the MIT licence, see the LICENCE
 *	file for more details.
 */

#include "main.h"

int main(int ac, char **av) {
	char *bf_array;
	char *bf_code = 0;

	int bf_len = 256;

	if (ac != 2)
		return (puterror("Error: no input file.\n"));

	bf_array = (char*)malloc(sizeof(char) * bf_len);
	memset(bf_array, 0, bf_len);

	if (!readfile(av[1], &bf_code))
		return (1);
	bf_runcode(bf_array, bf_code, bf_len);

	free(bf_array);
	free(bf_code);
	return 0;
}
