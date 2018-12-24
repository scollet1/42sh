#include "../incl/42sh.h"

char		**parser(const char *input) {
	char **parsed;

	parsed = strsplit(input, ' ');
	return (parsed ? parsed : NULL);
}