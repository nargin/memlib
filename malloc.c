#include "memlib.h"

/*
	#include <sys/mman.h>

	void *mmap(void *addr, size_t length, int prot, int flags,
		int fd, off_t offset);
	
	int munmap(void *addr, size_t length);
	void	*malloc(size_t size);
	test purpose: void malloc(void);
*/



#define HEAP_LEN 1024

void	infite_malloc(void) {
	// printf("%d\n", PROT_EXEC | PROT_READ | PROT_WRITE);
	// printf("%d\n", PROT_EXEC);
	// printf("%d\n", PROT_READ);
	// printf("%d\n", PROT_WRITE);

	void	*heap;
	char	*test;
	int		prot;
	int		flag;

	prot = PROT_EXEC | PROT_READ | PROT_WRITE;
	flag = MAP_PRIVATE | MAP_ANONYMOUS; // fd: -1 cause of map anon
	heap = mmap(NULL, HEAP_LEN, prot, flag, -1, 0);
	if (heap == MAP_FAILED)
	{
		return ;
	}
	memset(heap, 97, HEAP_LEN - 1);
	test = (char *)heap;
	for (size_t i = 0; i < HEAP_LEN * 2; i++) {
		printf("%ld: %c\t", i, i[test]);
	}
	printf("\n");
}