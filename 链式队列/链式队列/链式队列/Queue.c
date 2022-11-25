#include "Queue.h"




void  init(Pqueue* phead)//初始化
{
	*phead = NULL;
}

Pqueue Enqueue(Pqueue phead, typedata data)//入队
{
	Pqueue pnew = malloc(sizeof(Queue));
	pnew->data = data;
	pnew->pNext = NULL;
	if (phead == NULL)
	{
		phead = pnew;

	}
	else
	{
		Pqueue ptemp = phead;
		while (ptemp->pNext != NULL)
		{
			ptemp = ptemp->pNext;
		}

		ptemp->pNext = pnew; //尾部插入

	}

	return phead;
}
Pqueue Dequeue(Pqueue phead,typedata *pdata)//出队
{
	if (phead == NULL)
	{
		return NULL;
	}
	else
	{

		*pdata = phead->data;//弹出的数据
		Pqueue ptemp = phead;
		phead = phead->pNext;
		free(ptemp);


	}
	return phead;

}
void show(Pqueue phead)
{
	if (phead == NULL)
	{
		return;
	}
	else
	{
		printf("%5d", phead->data);
		show(phead->pNext);
	}

}