#include "memlib.h"

void	display_list(sfree *list)
{
	int	i;

	i = 0;
	for (sfree *tmp = list; tmp; tmp = tmp->next, i++)
		printf("%d: %p\n", i, tmp->ptr);
}

int	pfree(void	*ptr)
{
	static struct sfree	*list;

	if (list == NULL && ptr == NULL)
		return (-1);
	if (list == NULL && ptr != NULL)
		list = newnode(ptr);
	else if (ptr != NULL)
		backnode(&list, newnode(ptr));
	if (ptr == NULL)
	{
		display_list(list);
		// TODO : freecontent -> free all String;
		freelist(&list);
	}
	return (0);
}

void	add_str(String *dest, char *src)
{
	size_t	len_src;

	if (*dest == NULL)
		*dest = malloc(1);
	len_src = fstrlen(src);
	printf("%ld\n", len_src);
	pfree(*dest);
}

int	main(void) {
	String	msg;

	add_str(&msg, "gnl");
	pfree(NULL);
	return (0);
}
