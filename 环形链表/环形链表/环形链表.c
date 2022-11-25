
#define _CRT_SECURE_NO_WARNINGS
#include "��������.h"




PNODE addback(PNODE phead, int data)//β������
{
	PNODE pnew = malloc(sizeof(node));
	pnew->data = data;
	if (phead == NULL)
	{
		phead=pnew;
		pnew->pNext = phead;//һ���ڵ�Ļ�

	}
	else
	{
		PNODE p = phead;
		while (p->pNext != phead)
		{
			/*printf(" %d", phead->data);*/
			p = p->pNext;
		}
		p->pNext = pnew;//β���������µĽڵ�
		pnew->pNext = phead;//������ͷ
		//printf("\n");
	}
	return phead;

}
PNODE addrnot(PNODE phead, int data)//ͷ������
{
	PNODE pnew = malloc(sizeof(node));
	pnew->data = data;
	if (phead == NULL)
	{
		phead = pnew;
		pnew->pNext = phead;//һ���ڵ�Ļ�

	}
	else
	{
		PNODE p = phead;
		while (p->pNext != phead)
		{
			p = p->pNext;//ѭ����β��
		}
		p->pNext = pnew;//β����ֵ
		pnew->pNext = phead; //����ͷ�ڵ�
		phead = pnew;


	}

	return phead;


}

PNODE findfirst(PNODE phead, int data)//��������
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


PNODE deletedata(PNODE phead, int deldata)  //ɾ��
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
				p1 = p1->pNext;  //ѭ��ָ����һ���ڵ�
			}


		}
		if (p1 != phead)
		{
			p2->pNext = p1->pNext;
			free(p1);
		}
		else
		{
			//�ͷ�ͷ�ڵ�
			node* p = phead;
			while (p->pNext != phead)//ѭ����β��
			{
				p = p->pNext;
			}
			phead = phead->pNext;//�ı�ͷ�ڵ�
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

int getnum(PNODE phead)//��ȡ��������Ľڵ�
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

PNODE insertdata(PNODE phead, int finddata, int newdata)//��������
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
		//p1->pNext = pnew;//�����Ҫp1,ǰ����Ҫp2

		pnew->pNext = p2->pNext;   //p2��p1 ��ǰ�棬p2�ĺ�����p1��ǰ��
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
		phead = pnew;*/   //���

		PNODE p = phead;
		while (p->pNext != phead)
		{
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;
		phead = pnew;   //���


	}



	return phead;


}
void show(PNODE phead)//��ʾ
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

PNODE deletedatap(PNODE phead, int deldata, PNODE* pphead)//ɾ��
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
				p1 = p1->pNext;  //ѭ��ָ����һ���ڵ�
			}


		}
		if (p1 != phead)
		{
			p2->pNext = p1->pNext;
			*pphead = p1->pNext;//��һ���ڵ�
			free(p1);
		}
		else
		{
			//�ͷ�ͷ�ڵ�
			node* p = phead;
			while (p->pNext != phead)//ѭ����β��
			{
				p = p->pNext;
			}
			phead = phead->pNext;//�ı�ͷ�ڵ�
			*pphead = p1->pNext;//��һ���ڵ�
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

void showall(PNODE phead)//��ʾ
{
	printf("\n");
	if (phead == NULL)
	{
		return;
	}
	else if (phead->pNext == phead)
	{
		printf("ĸ����%d��  %p  %p\n", phead->data, phead->pNext, &phead->data);
	}
	else
	{
		PNODE p = phead;
		while (p->pNext != phead)
		{

			printf("ĸ����%d��  %p  %p\n", p->data, p->pNext, &p->data);
			p = p->pNext;
		}
		printf("ĸ����%d��  %p  %p\n", p->data, p->pNext, &p->data);

	}

}