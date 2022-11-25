
#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

void main4()
{

	//tow2(10);
	PNODE phead = NULL;
	phead = init(phead);//初始化
	for (int i = 0; i < 10; i++)
	{
		phead = push(phead, i, i + 1);
	}

	while (phead != NULL)
	{
		node nd;
		phead = pop(phead, &nd);
		printf("\n弹出 %d , %d", nd.id, nd.data);
	}




	system("pause");
}
void main()
{
	PNODE phead = NULL;
	phead = init(phead);//初始化
	int num = 1000;
	while (num)
	{
		phead = push(phead, num % 2, 0);
		num /= 2;
	}
	while (phead != NULL)
	{
		node nd;
		phead = pop(phead, &nd);
		printf("\n弹出 %d , %d", nd.id, nd.data);
	}
	phead = clear(phead);
	printf("\n\n");
	num = 1000;
	while (num)
	{
		phead = push(phead, num % 2, 0);
		node nd;
		phead = pop(phead, &nd);
		printf("\n弹出 %d , %d", nd.id, nd.data);
		num /= 2;
	}
	phead = clear(phead);

	system("pause");

}