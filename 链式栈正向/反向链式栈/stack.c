
#define _CRT_SECURE_NO_WARNINGS

#include "stack.h"

PNODE init(PNODE phead)  //��ʼ��
{
	phead = NULL;
	return phead;//��ʼ��һ��ͷ�ڵ�



	//��ʼ��һ���ڵ�
	/*phead->id = 0;
	phead->data = 0;
	phead->pNext = NULL;*/

}

PNODE push(PNODE phead, int id, typedata data)//ѹ������
{
	PNODE pnew = malloc(sizeof(node));
	pnew->id = id;
	pnew->data = data;
	pnew->pNext = NULL;
	if (phead == NULL)
	{
		phead = pnew;
	}
	else
	{
		pnew->pNext = phead;
		phead = pnew;
	}

	return phead;
}


PNODE pop(PNODE phead, PNODE pdata)//�³�����
{
	if (phead == NULL)
	{
		return NULL;
	}
	else  if(phead->pNext==NULL)
	{

		pdata->id = phead->id;
		pdata->data = phead->data;
		free(phead);
		phead = NULL;
		return phead;
	}
	else
	{
		pdata->id = phead->id;
		pdata->data = phead->data;
		
		PNODE ptemp = phead->pNext;//����

		free(phead);

		phead = ptemp;
		return phead;
	}

}

PNODE clear(PNODE phead)//�������
{
	if (phead == NULL)
	{

		return NULL;

	}
	else
	{
		PNODE p1 = phead, p2 = NULL;
		while (p1->pNext != NULL)
		{
			p2 = p1->pNext;//������һ���ڵ�;
			p1->pNext = p2->pNext; //����p2
			free(p2);
		}
		free(phead);
		phead = NULL;
		return phead;
	}
}

void show(PNODE phead)
{
	if (phead == NULL)
	{
		return;
	}
	else
	{
		printf("%d , %d , %p , %p \n", phead->id, phead->data, phead, phead->pNext);
		show(phead->pNext);
	}

}