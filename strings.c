#include "memlib.h"

char	*fstrdup(const char *src)
{
	char	*ret;
	char	*tmp;

	ret = malloc((fstrlen(src) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	tmp = ret;
	while (*src && src)
		*ret++ = *src++;
	*ret = 0;
	return (tmp);
}

size_t	fstrlen(const char *s)
{
	const char	*t;

	t = s;
	while (*s && s)
		s++;
	return (s - t);
}

void	*fmemcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	s = src;
	d = dest;
	while (len--)
		*d++ = *s++;
	return dest;
}

void	str_realloc(String *dest, const char *src, size_t len_src)
{
	String	copy;
	size_t	len_d;

	printf("%s\n", *dest);
	len_d = fstrlen(*dest);
	copy = fstrdup(*dest);
	*dest = realloc(*dest, (len_src + len_d + 1));
	fmemcpy(*dest, copy, len_d);
	fmemcpy((*dest + len_d), src, len_src);
}