#include "memlib.h"
// String func;

// memory lib soon..;

int	main(void) {
	char	*c = malloc(0); // struct block leak;
	(void)c;

	infite_malloc();
	return (0);
}