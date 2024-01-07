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

void	*fmemset(void	*src, int value, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)src;
	while (count--)
		*ptr++ = value;
	return (src);
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

int	strrealloc(String *d, size_t ld, size_t size)
{
	free(*d);
	*d = malloc((ld + size + 1) * szch);
	if ((*d) == NULL)
		return (ERROR);
	*d = fmemset(*d, 0, (ld + size + 1) * szch);
	return (SUCCESS);
}