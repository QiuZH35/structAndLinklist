
#define _CRT_SECURE_NO_WARNINGS
#include "mem.h"

struct LinkNode* phead = NULL;//����

void* mymalloc(size_t size)
{
	void* p = malloc(size);
	printf("�����ڴ�%p,��С%d\n", p, size);
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
		phead=delnode(phead, p);//ɾ��
		free(p);
		//printf("�ͷ��ڴ��ַ%p\n", p);
	}
	
	

}

void* myrealloc(void* p, size_t size)
{
	void* pt = realloc(p, size);
	//printf("�ڴ��ַ%p���·��䵽%p��С%d\n", p, pt, size);
	struct Mem pmem;
	pmem.p = pt;
	pmem.size = size;
	phead=change(phead, p, &pmem);
	/*printf("\n�޸ĺ�");*/
	


	return pt;

}



PNODE addback(PNODE phead, struct Mem* pmem)//����һ������
{
	PNODE pnew = malloc(sizeof(node));

	pnew->Pmem = pmem;
	pnew->pNext = NULL;//����һ���ڵ�

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



PNODE change(PNODE phead, void* pfind, struct Mem* pnewmem)//�޸�
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

PNODE delnode(PNODE phead, void* paddr)//���ݵ�ַɾ��
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


void showall(PNODE phead)//��ʾ
{
	if (phead == NULL)
	{
		return;
	}
	else
	{

		printf("memaddr=%p,size=%d\n", phead->Pmem->p, phead->Pmem->size);
		showall(phead->pNext);//����
	}


}

void getinfo(PNODE phead)//ʵʱ����ڴ�
{
	if (phead != NULL) {
		int i = 0;//�����ж���Ƭ�ڴ�
		int j = 0;//�����ڴ�Ĵ�С
		for (PNODE p = phead; p != NULL; p = p->pNext)
		{
			i++;
			j += p->Pmem->size;
			printf("%p,%d\n", p->Pmem->p, p->Pmem->size);
		}
		printf("��%dƬ�ڴ��ڶ������ڴ��СΪ%d", i, j);

	}
}


PNODE delall(PNODE phead)//ɾ��ȫ��
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