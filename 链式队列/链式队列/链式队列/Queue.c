#include "Queue.h"




void  init(Pqueue* phead)//��ʼ��
{
	*phead = NULL;
}

Pqueue Enqueue(Pqueue phead, typedata data)//���
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

		ptemp->pNext = pnew; //β������

	}

	return phead;
}
Pqueue Dequeue(Pqueue phead,typedata *pdata)//����
{
	if (phead == NULL)
	{
		return NULL;
	}
	else
	{

		*pdata = phead->data;//����������
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