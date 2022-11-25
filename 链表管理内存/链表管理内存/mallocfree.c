
#define _CRT_SECURE_NO_WARNINGS
#include "mem.h"

#define malloc mymalloc
#define free  myfree
#define realloc myrealloc



void main()
{
	void* p1 = malloc(1024*1024*100);
	void* p2 = malloc(1024*1024*100);
	void* p3 = malloc(1024 * 1024 * 100);
	void* p4 = malloc(1024 * 1024 * 100);
	/*free(p1);*/

	getinfo(phead);
	printf("\n\n");
	realloc(p2, 20);
	getinfo(phead);

	free(p1);
	printf("\n\n");
	
	free(p3);
	printf("\n\n");
	getinfo(phead);

	delall(phead);
	
	
	//system("pause");
}