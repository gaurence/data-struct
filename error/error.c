#include <stdio.h>
#include <stdlib.h>

void
fatal_error(const char s[])
{
	fprintf(stderr, "Fatal errors: %s\n", s);
	exit(-1);  //-1??
}

void
error(const char s[])
{
	fprintf(stderr, "errors: %s\n", s);
	exit(0);
}

