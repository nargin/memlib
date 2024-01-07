#include "memlib.h"

int	add_start(String *dest, const char *src)
{
	String	copy;
	size_t	len_d;
	size_t	len_src;

	if (src == NULL)
		return (ERROR);
	if (*dest == NULL)
	{
		*dest = fstrdup(src);
		return (SUCCESS);
	}
	len_src = fstrlen(src);
	if (len_src > 0)
	{
		len_d = fstrlen(*dest);
		copy = fstrdup(*dest);
		if (strrealloc(dest, len_d, len_src) == ERROR)
			return (ERROR);
		fmemcpy(*dest, src, len_src);
		fmemcpy((*dest + len_src), copy, len_d);
		free(copy);
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_end(String *dest, const char *src)
{
	String	copy;
	size_t	len_d;
	size_t	len_src;

	if (src == NULL)
		return (ERROR);
	if (*dest == NULL)
	{
		*dest = fstrdup(src);
		return (SUCCESS);
	}
	len_src = fstrlen(src);
	if (len_src > 0)
	{
		len_d = fstrlen(*dest);
		copy = fstrdup(*dest);
		if (strrealloc(dest, len_d, len_src) == ERROR)
			return (ERROR);
		fmemcpy(*dest, copy, len_d);
		fmemcpy((*dest + len_d), src, len_src);
		free(copy);
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_left(String *dest, const char *src, size_t index)
{
	String	copy;
	size_t	len_d;
	size_t	len_src;
	size_t	moved;

	if (src == NULL)
		return (ERROR);
	if (*dest == NULL)
	{
		*dest = fstrdup(src);
		return (SUCCESS);
	}
	len_src = fstrlen(src);
	len_d = fstrlen(*dest);
	if (len_src > 0 && index <= len_d)
	{
		copy = fstrdup(*dest);
		if (strrealloc(dest, len_d, len_src) == ERROR)
			return (ERROR);
		fmemcpy(*dest, copy, index);
		fmemcpy((*dest + index), src, len_src);
		moved = len_src + index;
		fmemcpy((*dest + moved), (copy + index), (len_d - index));
		free(copy);
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_right(String *dest, const char *src, size_t index)
{
	size_t	len_d;

	if (src == NULL)
		return (ERROR);
	if (*dest == NULL)
	{
		*dest = fstrdup(src);
		return (SUCCESS);
	}
	len_d = fstrlen(*dest);
	if (index + 1 < len_d)
		return add_left(dest, src, (index + 1));
	else if (index + 1 == len_d)
		return add_end(dest, src);
	else
		return (ERROR);
}

