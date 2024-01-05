#include "memlib.h"

void	*fmemcpy (void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	s = src;
	d = dest;
	while (len--)
		*d++ = *s++;
	return dest;
}

void	str_realloc(String *dest, char *src, size_t len_src)
{
	String	copy;
	size_t	len_d;
	size_t	new_len;

	len_d = fstrlen(*dest);
	new_len = len_d + len_src;
	 // TODO: My malloc
}