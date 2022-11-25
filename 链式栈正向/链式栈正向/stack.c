
#define _CRT_SECURE_NO_WARNINGS
#include "starck.h"

PNODE init(PNODE phead)  //初始化
{
	phead = NULL;
	return phead;//初始化一个头节点



	//初始化一个节点
	/*phead->id = 0;
	phead->data = 0;
	phead->pNext = NULL;*/

}

PNODE push(PNODE phead, int id, typedata data)//压入数据
{
	PNODE pnew = malloc(sizeof(node));
	pnew->id = id;
	pnew->data = data;
	pnew->pNext = NULL;
	if (phead == NULL)
	{
		phead = pnew;  //只有一个节点的情况
	}
	else
	{
		PNODE ptemp = phead;
		while (ptemp->pNext != NULL)
		{
			ptemp = ptemp->pNext;
		}
		ptemp->pNext = pnew;//连接
	}

	return phead;

}



PNODE pop(PNODE phead, PNODE pdata)//吐出数据
{
	if (phead == NULL)
	{
		return NULL;
	}
	else if (phead->pNext==NULL)
	{
		pdata->id = phead->id;
		pdata->data = phead->data;//赋值
		free(phead);
		phead = NULL;
		return phead;   //删除一个节点
	}
	else
	{
		PNODE ptemp = phead;
		while (ptemp->pNext->pNext != NULL)
		{
			ptemp = ptemp->pNext;

		}
		pdata->id = ptemp->pNext->id;
		pdata->data = ptemp->pNext->data;
		free(ptemp->pNext);
		ptemp->pNext = NULL;
		return phead;

	}



}

PNODE clear(PNODE phead)//清空数据
{
	if (phead == NULL)
	{

		return NULL;

	}
	else
	{
		PNODE p1=phead, p2 = NULL;
		while (p1->pNext != NULL)
		{
			p2 = p1->pNext;//保存下一个节点;
			p1->pNext = p2->pNext; //跳过p2
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
		printf("%d , %d , %p , %p \n", phead->id,phead->data, phead, phead->pNext);
		show(phead->pNext);
	}




}