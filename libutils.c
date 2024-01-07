#include "memlib.h"

int	add_str(String *dest, const char *src)
{
	return (add_end(dest, src));
}

int	null_str(String *dest, const char *src)
{
	*dest = NULL;
	return (add_end(dest, src));
}
