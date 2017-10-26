/**
 *	src/io.h
 *	Author: Martin "tiphedor" STEFFEN <mail@tiph.io>
 *
 *	Distributed under the terms of the MIT licence, see the LICENCE
 *	file for more details.
 */

#ifndef IO_H
# define IO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>


int		puterror(const char* err);
void	writechar(char c);
void	readchar(char *c);
int		readfile(char* filename, char** destination);

#endif
