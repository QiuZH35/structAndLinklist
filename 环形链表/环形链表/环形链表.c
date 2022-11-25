
#define _CRT_SECURE_NO_WARNINGS
#include "环形链表.h"




PNODE addback(PNODE phead, int data)//尾部插入
{
	PNODE pnew = malloc(sizeof(node));
	pnew->data = data;
	if (phead == NULL)
	{
		phead=pnew;
		pnew->pNext = phead;//一个节点的环

	}
	else
	{
		PNODE p = phead;
		while (p->pNext != phead)
		{
			/*printf(" %d", phead->data);*/
			p = p->pNext;
		}
		p->pNext = pnew;//尾部连接上新的节点
		pnew->pNext = phead;//连到开头
		//printf("\n");
	}
	return phead;

}
PNODE addrnot(PNODE phead, int data)//头部插入
{
	PNODE pnew = malloc(sizeof(node));
	pnew->data = data;
	if (phead == NULL)
	{
		phead = pnew;
		pnew->pNext = phead;//一个节点的环

	}
	else
	{
		PNODE p = phead;
		while (p->pNext != phead)
		{
			p = p->pNext;//循环到尾部
		}
		p->pNext = pnew;//尾部赋值
		pnew->pNext = phead; //保存头节点
		phead = pnew;


	}

	return phead;


}

PNODE findfirst(PNODE phead, int data)//查找数据
{
	if (phead == NULL)
	{
		return NULL;
	}
	else if (phead->pNext == phead)
	{
		if (phead->data == data)
		{
			return phead;
		}
	}
	else
	{
		PNODE p = phead;
		while (p->pNext != phead)
		{
			if (p->data == data)
			{
				return p;
			}
			p = p->pNext;

		}


	}
	return NULL;
}


PNODE deletedata(PNODE phead, int deldata)  //删除
{
	node* pfind = findfirst(phead, deldata);
	if (pfind != NULL)
	{
		PNODE p1 = NULL;
		PNODE p2 = NULL;
		p1 = phead;
		while (p1->pNext != phead)
		{
			if (p1->data == deldata)
			{
				break;

			}
			else
			{
				p2 = p1;
				p1 = p1->pNext;  //循环指向下一个节点
			}


		}
		if (p1 != phead)
		{
			p2->pNext = p1->pNext;
			free(p1);
		}
		else
		{
			//释放头节点
			node* p = phead;
			while (p->pNext != phead)//循环到尾部
			{
				p = p->pNext;
			}
			phead = phead->pNext;//改变头节点
			free(p1);
			p->pNext = phead;
		}
		return phead;
	}
	else
	{
		return phead;
	}
}

int getnum(PNODE phead)//获取环形链表的节点
{
	if (phead == NULL)
	{
		return 0;
	}
	else if (phead->pNext == phead)
	{
		return 1;
	}
	else
	{
		int count = 0;
		node* p = phead;
		while (p->pNext != phead)
		{
			count++;
			p = p->pNext;
		}

		return count+=1;
	}
}

PNODE insertdata(PNODE phead, int finddata, int newdata)//插入数据
{
	PNODE p1 = phead;
	PNODE p2 = NULL;
	while (p1->pNext != phead)
	{
		if (p1->data == finddata)
		{

			break;
		}
		else
		{
			p2 = p1;
			p1 = p1->pNext;
		}


	}
	printf("p1=%d\n", p1->data);

	PNODE pnew = malloc(sizeof(node));
	pnew->data = newdata;
	pnew->pNext = NULL;
	if (p1 != phead)
	{
		//pnew->pNext = p1->pNext;
		//p1->pNext = pnew;//后插需要p1,前插需要p2

		pnew->pNext = p2->pNext;   //p2在p1 的前面，p2的后插就是p1的前插
		p2->pNext = pnew;
	}
	else
	{

	/*	PNODE p = phead;
		while (p->pNext != phead)
		{
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;
		phead = pnew;*/   //后插

		PNODE p = phead;
		while (p->pNext != phead)
		{
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;
		phead = pnew;   //后插


	}



	return phead;


}
void show(PNODE phead)//显示
{
	printf("\n");
	if (phead == NULL)
	{
		return;
	}else if (phead->pNext == phead)
	{
			printf("%d  %p  %p\n", phead->data, phead->pNext, &phead->data);
	}
	else
	{
		PNODE p = phead;   
		while (p->pNext != phead)
		{

			printf("%d  %p  %p\n", p->data, p->pNext, &p->data);
			p = p->pNext;    
		}
		printf("%d  %p  %p\n", p->data, p->pNext, &p->data);

	}

}

PNODE deletedatap(PNODE phead, int deldata, PNODE* pphead)//删除
{
	//node* pfind = findfirst(phead, deldata);
	//if (pfind != NULL)
	//{
		PNODE p1 = NULL;
		PNODE p2 = NULL;
		p1 = phead;
		while (p1->pNext != phead)
		{
			if (p1->data == deldata)
			{
				break;

			}
			else
			{
				p2 = p1;
				p1 = p1->pNext;  //循环指向下一个节点
			}


		}
		if (p1 != phead)
		{
			p2->pNext = p1->pNext;
			*pphead = p1->pNext;//下一个节点
			free(p1);
		}
		else
		{
			//释放头节点
			node* p = phead;
			while (p->pNext != phead)//循环到尾部
			{
				p = p->pNext;
			}
			phead = phead->pNext;//改变头节点
			*pphead = p1->pNext;//下一个节点
			free(p1);
			p->pNext = phead;
		}
		return phead;
	//}
	//else
	//{
	//	return phead;
	//}
}

void showall(PNODE phead)//显示
{
	printf("\n");
	if (phead == NULL)
	{
		return;
	}
	else if (phead->pNext == phead)
	{
		printf("母猴子%d号  %p  %p\n", phead->data, phead->pNext, &phead->data);
	}
	else
	{
		PNODE p = phead;
		while (p->pNext != phead)
		{

			printf("母猴子%d号  %p  %p\n", p->data, p->pNext, &p->data);
			p = p->pNext;
		}
		printf("母猴子%d号  %p  %p\n", p->data, p->pNext, &p->data);

	}

}