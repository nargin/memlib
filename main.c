#include "memlib.h"

int	main(void)
{
	String	msg;

	null_str(&msg, "hihi");
	add_left(&msg, "parsing", 6);
	printf("%ld: %s\n", fstrlen(msg), msg);
	free(msg);
	return (0);
}
