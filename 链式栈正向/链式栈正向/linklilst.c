
#define _CRT_SECURE_NO_WARNINGS
#include "starck.h"


void tow2(int num)
{
	if (num == 0)
	{
		return;
	}
	else
	{
		tow2(num / 2);
		printf("%d", num % 2);
			
	}


}


void main6()
{
	PNODE phead = NULL;
	phead = init(phead);//初始化
	int num=1000;
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
		phead = push(phead ,num % 2, 0);
		node nd;
		phead = pop(phead, &nd);
		printf("\n弹出 %d , %d", nd.id, nd.data);
		num /= 2;
	}
	phead = clear(phead);

	system("pause");

}




void main1()
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