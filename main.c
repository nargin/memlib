#include "memlib.h"

void	display_list(sfree *list)
{
	int	i;

	i = 0;
	for (sfree *tmp = list; tmp; tmp = tmp->next, i++)
		printf("%d: %p\n", i, tmp->ptr);
}

int	containe(struct sfree *container, void *ptr)
{
	while (container)
	{
		if (container->ptr == ptr)
			return (1);
		container = container->next;
	}
	return (0);
}

int	pfree(void	*ptr)
{
	static struct sfree	*list;
	
	if (list == NULL && ptr == NULL)
		return (-1);
	else if (list == NULL && ptr != NULL)
		list = newnode(ptr);
	else if (ptr != NULL && containe(list, ptr) == false)
		backnode(&list, newnode(ptr));
	else if (ptr == NULL)
	{
		display_list(list);
		freelist(&list);
	}
	return (0);
}

void	add_str(String *dest, char *src)
{
	size_t	len_src;

	if (*dest == NULL)
		*dest = fstrdup("");
	len_src = fstrlen(src);
	if (len_src > 0)
		str_realloc(dest, src, len_src);
	pfree(*dest);
}

void	norm_str(String *dest, char *src)
{
	*dest = NULL;
	add_str(dest, src);
}

int	main(void) {
	String	msg;

	msg = NULL;
	add_str(&msg, "gnl");
	printf("%s\n", msg);
	add_str(&msg, "hihi");
	printf("%s\n", msg);
	pfree(NULL);
	return (0);
}
