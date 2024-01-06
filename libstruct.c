#include "memlib.h"

void	exitation(int errorcode)
{
	asm(
		"movl %0, %%edi\n\t"
		"movl $60, %%eax\n\t"
		"syscall"
		:
		: "r"(errorcode)
		);
}

sfree	*newnode(void *ptr)
{
	sfree	*node;

	node = malloc(sizeof(sfree));
	if (node == NULL)
		return (NULL);
	node->ptr = ptr;
	node->next = NULL;
	return (node);
}

void	backnode(sfree **list, sfree *new)
{
	sfree	*iter;

	if (new == NULL)
		return ;
	iter = *list;
	while (iter->next)
		iter = iter->next;
	iter->next = new;
}

void	freelist(sfree **flist)
{
	sfree	*tp;

	if (flist == NULL && *flist == NULL)
		return ;
	while (*flist)
	{
		if ((*flist)->ptr)
			free((*flist)->ptr);
		tp = (*flist);
		(*flist) = (*flist)->next;
		free(tp);
	}
}
