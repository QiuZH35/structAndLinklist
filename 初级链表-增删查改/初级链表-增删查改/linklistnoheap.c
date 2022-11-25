
#define _CRT_SECURE_NO_WARNINGS
#include "linklist.h"


void main11()
{


	node* phead=NULL;  //头节点不分配内存
	//init(phead); //初始化



	phead = addback(phead, 11);
	phead = addback(phead, 12);
	phead = addback(phead, 13);
	phead = addback(phead, 14);
	phead = addback(phead, 15);
	phead = addback(phead, 16);
	phead = addback(phead, 17);
	phead = addback(phead, 18);
	phead = addback(phead, 19);
	phead = addback(phead, 20);


	/*phead = deletefirst(phead, 11);
	phead = deletefirst(phead, 13);
	phead = deletefirst(phead, 15);*/

	
	/*addhead(&phead, 20); 
	addhead(&phead, 21);
	addhead(&phead, 22);*/

	
	phead = insertfirst(phead, 11, 899);
	phead = insertfirst(phead, 14, 888);
	phead = insertfirst(phead, 15, 800);

	showall(phead);
	printf("\n\n\n");


	phead = revgui(phead);

	//bubblesort(phead);
	//myquicksort(phead, NULL);
	showall(phead);
	//printf("\n%d", getnumdigui(phead));

	system("pause");
}

void main3()
{

	node* phead1 = NULL;
	phead1 = addback(phead1, 2);
	phead1 = addback(phead1, 4);
	phead1 = addback(phead1, 6);
	phead1 = addback(phead1, 8);
	phead1 = addback(phead1, 10);
	phead1 = addback(phead1, 13);
	phead1 = addback(phead1, 14);



	node* phead2 = NULL;
	phead2 = addback(phead2, 1);
	phead2 = addback(phead2, 3);
	phead2 = addback(phead2, 5);
	phead2 = addback(phead2, 7);
	phead2 = addback(phead2, 9);


	node* phead = NULL;
	node* p1 = phead1;
	node* p2 = phead2;

	while (p1 != NULL || p2 != NULL)
	{
		if (p1 != NULL && p2 != NULL)
		{
			if (p1->data < p2->data)
			{
				phead = addback(phead, p1->data);
				p1 = p1->pNext;
			}
			else
			{
				phead = addback(phead, p2->data);
				p2=p2->pNext;
			}


		}
		else
		{
			while (p1 != NULL)
			{
				phead = addback(phead, p1->data);
				p1=p1->pNext;

			}
			while (p2 != NULL)
			{
				phead = addback(phead, p2->data);
				p2 = p2->pNext;

			}
			break;
		}
	}
	showall(phead);
	system("pause");
}


node* getmid(node* phead)  //判断中间节点
{
	if (phead == NULL || phead->pNext == NULL)
	{
		return phead;
	}
	else
	{
		node* p1=phead, * p2=phead;

		while (p2->pNext != NULL)
		{
			p1 = p1->pNext;
			p2 = p2->pNext;
			if (p2->pNext != NULL)
			{
				p2=p2->pNext;

			}


		}
		return p1;

	}



}



void  main32()
{
	node* phead1 = NULL;
	phead1 = addback(phead1, 2);
	phead1 = addback(phead1, 4);
	phead1 = addback(phead1, 6);
	phead1 = addback(phead1, 8);
	phead1 = addback(phead1, 10);
	phead1 = addback(phead1, 13);
	phead1 = addback(phead1, 14);

	node* phead2 = getmid(phead1);
	printf("  %d  ",phead2->data);
	

	system("pause");
}



void main()
{
	node* phead1 = NULL;
	phead1 = addback(phead1, 1);
	phead1 = addback(phead1, 2);
	phead1 = addback(phead1, 4);
	phead1 = addback(phead1, 6);
	phead1 = addback(phead1, 8);
	phead1 = addback(phead1, 10);
	phead1 = addback(phead1, 13);
	phead1 = addback(phead1, 14);

	node* p = phead1;
	for (;p->pNext != NULL; p = p->pNext)
	{

	}
	p->pNext= phead1;

	//ShowRinglike(phead1);

	printf(" %d", isit(phead1));
	//deleteall(phead1);

	
	system("pause");
}