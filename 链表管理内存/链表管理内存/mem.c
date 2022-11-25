
#define _CRT_SECURE_NO_WARNINGS
#include "mem.h"

struct LinkNode* phead = NULL;//定义

void* mymalloc(size_t size)
{
	void* p = malloc(size);
	printf("开辟内存%p,大小%d\n", p, size);
	struct Mem* pmem = malloc(sizeof(struct Mem));
	pmem->p = p;
	pmem->size = size;
	phead = addback(phead, pmem);
	return p;
}

void myfree(void* p)
{
	PNODE *px=findit(phead, p);
	if (px == NULL)
	{
		
		return;
	}
	else
	{
		phead=delnode(phead, p);//删除
		free(p);
		//printf("释放内存地址%p\n", p);
	}
	
	

}

void* myrealloc(void* p, size_t size)
{
	void* pt = realloc(p, size);
	//printf("内存地址%p重新分配到%p大小%d\n", p, pt, size);
	struct Mem pmem;
	pmem.p = pt;
	pmem.size = size;
	phead=change(phead, p, &pmem);
	/*printf("\n修改后");*/
	


	return pt;

}



PNODE addback(PNODE phead, struct Mem* pmem)//插入一个数据
{
	PNODE pnew = malloc(sizeof(node));

	pnew->Pmem = pmem;
	pnew->pNext = NULL;//开辟一个节点

	if (phead == NULL)
	{
		phead = pnew;

	}
	else
	{
		PNODE ptemp = phead;
		while (ptemp->pNext != NULL)
		{

			ptemp = ptemp->pNext;

		}
		ptemp->pNext = pnew;
	}
	return phead;

}



PNODE change(PNODE phead, void* pfind, struct Mem* pnewmem)//修改
{
	for (PNODE p = phead; p != NULL; p = p->pNext)
	{
		if (p->Pmem->p == pfind)
		{
			p->Pmem->p = pnewmem->p;
			p->Pmem->size = pnewmem->size;
			printf("\np=%p,p=%d\n", p->Pmem->p, p->Pmem->size);

			return p;
		}
	}
	return phead;
}

PNODE findit(PNODE phead, void* pfind)
{
	for (PNODE p = phead; p != NULL; p = p->pNext)
	{
		if (p->Pmem->p == pfind)
		{
			return p;
		}

	}
	return NULL;

}

PNODE delnode(PNODE phead, void* paddr)//根据地址删除
{
	PNODE p1, p2;
	p1 = p2 = NULL;
	p1 = phead;
	while (p1 != NULL)
	{
		if (p1->Pmem->p == paddr)
		{
			break;
		}
		else
		{
			p2 = p1;
			p1 = p1->pNext;
		}

	}
	if (p1 != phead)
	{
		p2->pNext = p1->pNext;
		free(p1);

	}
	else
	{
		phead = phead->pNext;
		free(p1);
	}

	return phead;
}


void showall(PNODE phead)//显示
{
	if (phead == NULL)
	{
		return;
	}
	else
	{

		printf("memaddr=%p,size=%d\n", phead->Pmem->p, phead->Pmem->size);
		showall(phead->pNext);//便利
	}


}

void getinfo(PNODE phead)//实时监测内存
{
	if (phead != NULL) {
		int i = 0;//代表有多少片内存
		int j = 0;//代表内存的大小
		for (PNODE p = phead; p != NULL; p = p->pNext)
		{
			i++;
			j += p->Pmem->size;
			printf("%p,%d\n", p->Pmem->p, p->Pmem->size);
		}
		printf("共%d片内存在堆区，内存大小为%d", i, j);

	}
}


PNODE delall(PNODE phead)//删除全部
{
	if (phead == NULL)
	{
		return NULL;
	}
	else
	{
		PNODE p1 = phead,p2=NULL;
		while (p1->pNext != NULL)
		{

			p2 = p1->pNext;
			p1->pNext = p2->pNext;
			free(p2->Pmem->p);

			free(p2);

		}
		free(( phead)->Pmem->p);
		
		free(phead);
		
		
	}

	return NULL;


}