#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "malloc.h"

void *_malloc(size_t size);

#define LOWER 0
#define UPPER 99
#define ITERATIONS 100
#define SIZE 100


int main(int argc, char *argv[])
{
	FILE *f;
	size_t arr[SIZE] = {16,24, 16}, i, s;
	char *addr[SIZE];

	if (argc < 2)
		return (1);
	f = fopen(argv[argc - 1], "r");
	for (i = 0; i < SIZE; ++i) {
		fscanf(f, "%lu\n", &arr[i]);
	}
	for (i = 0; i < ITERATIONS; i++)
	{
		/* void *chunk; */
		addr[i] = _malloc(arr[i]);
		/* strcpy(str, "Holberton"); */
		/* str[21] = '\0'; */
		printf("Iteration: %lu %p", i,(void *)addr[i]);
		/* chunk = (void *)(str - sizeof(size_t)); */
		/* printf("chunk addr: %p, ", (void *)chunk); */
		/* printf("size: %lu, ", *((size_t *)chunk)); */
		printf("  break: %p\n", sbrk(0));
	}

	for (i = 0; i < 40; i++)
	{
		/* void *chunk; */
		s = LOWER + (rand() % (UPPER - LOWER + 1));
		_free(addr[s]);
		/* strcpy(str, "Holberton"); */
		/* str[21] = '\0'; */
		printf("Iteration: %lu %p", i,(void *)addr[i]);
		/* chunk = (void *)(str - sizeof(size_t)); */
		/* printf("chunk addr: %p, ", (void *)chunk); */
		/* printf("size: %lu, ", *((size_t *)chunk)); */
		printf("  break: %p\n", sbrk(0));
	}
	print_heap();
	return 0;
}
