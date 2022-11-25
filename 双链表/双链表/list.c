
#include "lilst.h"

void init(List* p)//初始化
{
	p->head = p->tail = NULL;
}

void adddatahead(List* p, int data)//头部插入
{
	node* pnew = malloc(sizeof(node));
	pnew->data = data;
	pnew->pNext = NULL;
	pnew->pPre = NULL;
	if (p->head == NULL || p->tail == NULL)  //没有节点的情况
	{
		p->head = pnew;
		p->tail = pnew;
	}
	else
	{
		p->head->pPre = pnew;//前驱
		pnew->pNext = p->head;//后继
		p->head = pnew; //头插
	}
		
}
void adddataback(List* p, int data)//尾部插入
{
	node* pnew = malloc(sizeof(node));
	pnew->data = data;
	pnew->pNext = NULL;
	pnew->pPre = NULL;
	if (p->head == NULL || p->tail == NULL)  //没有节点的情况
	{
		p->head = pnew;
		p->tail = pnew;
	}
	else
	{
		p->tail->pNext = pnew;//后继
		pnew->pPre = p->tail;//前驱
		p->tail = pnew;//尾插


	}

}



void show(List* p)
{
	node* pshow = p->head;
	while (pshow != NULL)
	{
		printf("%4d", pshow->data); 
		pshow = pshow->pNext;
	}



}
void revshow(List* p)
{

	node* pshow = p->tail;
	while (pshow != NULL)
	{
		printf("%4d", pshow->data);
		pshow = pshow->pPre;
	}



}

node* find(List* p,int data)
{
	node* pshow = p->head;
	while (pshow != NULL)
	{
		if (pshow->data == data)
		{
			return pshow;
		}
		pshow = pshow->pNext;
	}
	return NULL;
}
node *revfind(List* p,int data)
{
	node* pshow = p->tail;
	while (pshow != NULL)
	{

		if (pshow->data == data)
		{
			return pshow;
		}
		pshow = pshow->pPre;
	}
	return NULL;
}


void insertdata(List* p, int data,int newdata)//插入
{
	node* pnew = malloc(sizeof(node));
	pnew->data = newdata;
	pnew->pNext = NULL;
	pnew->pPre = NULL;
	node* p1 = NULL;
	p1 = p->head;
	while (p1 != NULL)
	{
		if (p1->data != data)
		{
			p1 = p1->pNext;
		}
		else
		{
			break;
		}


	}
	if (p1 != p->head && p1 != p->tail)
	{
		pnew->pNext = p1;
		pnew->pPre = p1->pPre;
		p1->pPre = pnew;
		p1->pPre->pNext = pnew;
	
	}
	else if (p1 == p->head)
	{
		 p1->pPre=pnew;
		 pnew->pNext = p1;
		 p->head = pnew;

	}
	else if (p1 == p->tail)
	{
		pnew->pNext = p1;
		pnew->pPre = p1->pPre;
		p1->pPre->pNext = pnew;
		p1->pPre = pnew;

	}
}
void deldata(List* p, int data)//删除
{
	node* pfind = find(p, data);
	if (pfind != NULL) {
		node* p1 = NULL;
		p1 = p->head;
		while (p1 != NULL)
		{
			if (p1->data != data)
			{
				p1 = p1->pNext;
			}
			else
			{
				break;
			}
		}
		//p1记录找到的位置
		if (p1 != p->head && p1 != p->tail)
		{
			p1->pPre->pNext = p1->pNext;
			p1->pNext->pPre = p1->pPre;
			free(p1);
		}
		else if (p1 == p->head)
		{
			p->head = p1->pNext;
			p1->pNext->pPre = NULL;
			free(p1);
		}
		else if (p1 == p->tail)
		{
			p->tail = p1->pPre;
			p1->pPre->pNext = NULL;
			free(p1);
		}

	}
	else
	{
		printf("该数据不存在\n");
	}

}