
#define _CRT_SECURE_NO_WARNINGS
#include "linklist.h"


void init(node* phead)//初始化
{
	phead->data = 0;
	phead->pNext = NULL;


}

//改变一个指针，需要一个二级指针，或者返回指针赋值
node* addback(node* phead, int data) //尾部添加节点
{
	node* pnew = malloc(sizeof(node));//新的节点
	pnew->data = data;
	pnew->pNext = NULL;//赋值


	if (phead == NULL)
	{

		phead = pnew;//直接赋值
	}
	else
	{
		node* ptemp = phead;//备份头节点

		while (ptemp->pNext != NULL)
		{
			ptemp = ptemp->pNext;//循环前进


		}
		ptemp->pNext = pnew;//连接


	}
	return phead;
}
void addhead(node** pphead, int data)//头部添加
{
	node* pnew = malloc(sizeof(node));//新的节点
	pnew->data = data;
	pnew->pNext = NULL;//赋值
	if (pnew == NULL)
	{
		*pphead = pnew;//直接连接
	}
	else
	{
		pnew->pNext = *pphead;//连接新的节点
		*pphead = pnew;

	}
}

node* searchfirst(node* phead, int finddata)//查找数据
{

	for (node* p = phead; p != NULL; p = p->pNext)
	{
		if (p->data == finddata)
		{
			return p;
		}
	}
	return NULL;
}

node* changefirst(node* phead, int finddata, int newdata)
{
	for (node* p = phead; p != NULL; p = p->pNext)
	{
		if (p->data == finddata)
		{
			p->data = newdata;
			return p;
		}
	}
	return NULL;


}

node* deletefirst(node* phead, int deldata)//删除
{
	node* p1=NULL, * p2=NULL; //双指针
	p1 = phead;//保存头节点
	while (p1 != NULL)
	{
		
		if (p1->data != deldata)
		{
			p2 = p1;//备份p1上一个位置
			p1 = p1->pNext;//p1向前移动
		}
		else
		{

			break;
		}

	}
	if (p1 != phead) //不是头节点的情况
	{
		p2->pNext = p1->pNext;//跳过p1,中间删除

		free(p1); //删除p1
	}
	else
	{
		phead = phead->pNext;   //头部删除

		free(p1);

	}

	return phead;

}


void deleteall(node* phead)//删除全部
{

	free(phead);
	phead = NULL;

}



node* insertfirst(node* phead, int finddata, int newdata)//插入数据
{
	node* p1 = NULL, * p2 = NULL;
	p1 = phead;//保存头节点
	while (p1 != NULL)
	{
		if (p1->data != finddata)
		{
			p2 = p1;// 保存上一个节点
			p1=p1->pNext; //循环下一个节点


		}
		else
		{

			break;
		}


	}
	node* pnew = malloc(sizeof(node));
	pnew->data = newdata;
	pnew->pNext = NULL;

	if (p1 != phead)
	{
		pnew->pNext = p1;
		p2->pNext = pnew;// 连接


	}
	else
	{
		pnew->pNext = phead;
		phead = pnew;//头部插入
	}
	return phead;


}

void showall(node* phead)//显示
{
	if (phead == NULL)
	{
		return;
	}
	else
	{
		printf("%d , %p , %p \n", phead->data, phead->pNext, &phead->data);

		showall(phead->pNext);
	}



}
void revshowall(node* phead) //反转显示
{
	if (phead == NULL)
	{
		return;
	}
	else
	{
		revshowall(phead->pNext);
		printf("%d , %p , %p \n", phead->data, phead->pNext, &phead->data);	
	}
}

void  bubblesort(node* phead)//排序
{
	for (node* p1 = phead; p1 != NULL; p1 = p1->pNext)
	{
		for (node* p2 = phead; p2 != NULL; p2 = p2->pNext)
		{
			if (p1->data < p2->data)
			{
				int temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
		}
	}
}

void  myquicksort(node* phead, node* pback)//快排
{
	if (phead == pback)
	{
		return;
	}
	else
	{
		int key = phead->data;//获取第一个值，分界线
		node* p1 = phead;
		for (node* p2 = phead->pNext; p2 != NULL; p2 = p2->pNext)
		{
			if (p2->data < key)
			{
				p1=p1->pNext;//循环到下一个
				int temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}


		}
		int temp = p1->data;
		p1->data = phead->data;
		phead->data = temp;


		myquicksort(phead, p1);
		myquicksort(p1->pNext, pback);
	}



}

int getnum(node* phead)//计算节点
{
	int i = 0;
	for (; phead != NULL; phead = phead->pNext)
	{
		i++;
	}


	return i;
}
int getnumdigui(node* phead)//计算节点
{
	if (phead == NULL)
	{
		return 0;
	}
	else
	{


		return 1 + getnumdigui(phead->pNext);
	}

}

node* revit(node* phead)//链表反转
{
	if (phead == NULL || phead->pNext == NULL)
	{
		return;
	}
	else
	{
		node* pre = NULL;
		node* pcurr = NULL;
		node* pnext = NULL;

		pre = phead;
		pcurr = phead->pNext;
		while (pcurr != NULL)
		{
			pnext = pcurr->pNext;
			pcurr->pNext = pre;

			pre = pcurr;
			pcurr = pnext;


		}
		phead->pNext = NULL;
		phead = pre;
	}

	return phead;


}


node* rev(node* phead)//链表反转
{
	if (phead == NULL || phead->pNext == NULL)
	{
		return NULL;
	}
	else
	{
		node* pre, * pcurr, * pnext;
		pre = pcurr = pnext = NULL;
		
		pre = phead;
		pcurr = phead->pNext;
		
		while (pcurr != NULL)
		{
			pnext = pcurr->pNext;
			pcurr->pNext = pre;

			pre = pcurr;
			pcurr = pnext;
		}
		phead->pNext = NULL;
		phead = pre;
	}
	return phead;
}


node* revgui(node* phead)//链表反转
{
	if (phead == NULL || phead->pNext == NULL)
	{
		return phead;
	}
	else
	{
		node* pnext = phead->pNext;

		node* head = revgui(pnext);

		pnext->pNext = phead;//保存
		phead->pNext = NULL;



		return head;
	}





}


void ShowRinglike(node* phead)//显示环形链表
{
	node* phead1 = phead;
	
	for (; phead1->pNext != phead; phead1 = phead1->pNext)
	{
		printf(" %d", phead1->data);
	}
	printf(" %d", phead1->data);




}

int   isit(node* phead)//判断是否有环
{
	int flag = 0;
	for (node* p1 = phead, *p2 = phead; p1 != NULL; p1 = p1->pNext)   //双指针
	{
		p2=p2->pNext;
		if (p2->pNext != NULL)
		{
			p2 = p2->pNext;
		}
		else
		{
			flag = 0;
			break;
		}
		if (p1 == p2)
		{
			flag = 1;
			break;

		}
	
	}

	return flag;


}