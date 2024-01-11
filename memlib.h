#ifndef __MEMLIB__
#define __MEMLIB__

#include <sys/mman.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *String;

typedef int bool;

#define szch sizeof(char)

#define true 1
#define false 0

#define SUCCESS 0
#define ERROR -1

// typedef struct sfree {
// 	void	*ptr;
// 	struct sfree *next;
// }	sfree;



#ifdef INTERCEPT
	#define malloc(xs) infite_malloc(xs)
#endif

void	infite_malloc(void);

/* UTILS FUNCTION: str_utils.c */
size_t	fstrlen(const char *s);
char	*fstrdup(const char *src);
void	*fmemset(void *src, int value, size_t count);
void	*fmemcpy(void *dest, const void *src, size_t len);
int		strrealloc(String *d, size_t len_dest, size_t size);

/* String manipulation: libstring.c */
int		add_end(String *dest, const char *src);
int		add_start(String *dest, const char *src);
int		add_left(String *dest, const char *src, size_t index);
int		add_right(String *dest, const char *src, size_t index);
// trim(char *); (default whitespace)

/* Basic string function: libutils.c */
int		add_str(String *dest, const char *src);
int		null_str(String *dest, const char *src);

#endif