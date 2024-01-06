#ifndef __MEMLIB__
#define __MEMLIB__

#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *String;

#define true 1
#define false 0

typedef struct sfree {
	void	*ptr;
	struct sfree *next;
} sfree;

/* UTILS FUNCTION */
void	exitation(int errorcode);
size_t	fstrlen(const char *s);
void	str_realloc(String *dest, const char *src, size_t len_src);
char	*fstrdup(const char *src);

/* STRUCT FUNCTION */
sfree 	*newnode(void *ptr);
void	freelist(sfree **flist);
void	backnode(sfree **list, sfree *new);

/*

add_end;
add_right; (to an index)
add_left; (to an index)
add_start;
trim(char *); (default whitespace)
*/

// size_t	slen(String sptr);
// void	*salloc(size_t	toalloc);
// void	mfree(...);

#endif