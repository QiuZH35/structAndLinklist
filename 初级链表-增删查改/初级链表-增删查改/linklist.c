
#define _CRT_SECURE_NO_WARNINGS
#include "linklist.h"


void init(node* phead)//��ʼ��
{
	phead->data = 0;
	phead->pNext = NULL;


}

//�ı�һ��ָ�룬��Ҫһ������ָ�룬���߷���ָ�븳ֵ
node* addback(node* phead, int data) //β����ӽڵ�
{
	node* pnew = malloc(sizeof(node));//�µĽڵ�
	pnew->data = data;
	pnew->pNext = NULL;//��ֵ


	if (phead == NULL)
	{

		phead = pnew;//ֱ�Ӹ�ֵ
	}
	else
	{
		node* ptemp = phead;//����ͷ�ڵ�

		while (ptemp->pNext != NULL)
		{
			ptemp = ptemp->pNext;//ѭ��ǰ��


		}
		ptemp->pNext = pnew;//����


	}
	return phead;
}
void addhead(node** pphead, int data)//ͷ�����
{
	node* pnew = malloc(sizeof(node));//�µĽڵ�
	pnew->data = data;
	pnew->pNext = NULL;//��ֵ
	if (pnew == NULL)
	{
		*pphead = pnew;//ֱ������
	}
	else
	{
		pnew->pNext = *pphead;//�����µĽڵ�
		*pphead = pnew;

	}
}

node* searchfirst(node* phead, int finddata)//��������
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

node* deletefirst(node* phead, int deldata)//ɾ��
{
	node* p1=NULL, * p2=NULL; //˫ָ��
	p1 = phead;//����ͷ�ڵ�
	while (p1 != NULL)
	{
		
		if (p1->data != deldata)
		{
			p2 = p1;//����p1��һ��λ��
			p1 = p1->pNext;//p1��ǰ�ƶ�
		}
		else
		{

			break;
		}

	}
	if (p1 != phead) //����ͷ�ڵ�����
	{
		p2->pNext = p1->pNext;//����p1,�м�ɾ��

		free(p1); //ɾ��p1
	}
	else
	{
		phead = phead->pNext;   //ͷ��ɾ��

		free(p1);

	}

	return phead;

}


void deleteall(node* phead)//ɾ��ȫ��
{

	free(phead);
	phead = NULL;

}



node* insertfirst(node* phead, int finddata, int newdata)//��������
{
	node* p1 = NULL, * p2 = NULL;
	p1 = phead;//����ͷ�ڵ�
	while (p1 != NULL)
	{
		if (p1->data != finddata)
		{
			p2 = p1;// ������һ���ڵ�
			p1=p1->pNext; //ѭ����һ���ڵ�


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
		p2->pNext = pnew;// ����


	}
	else
	{
		pnew->pNext = phead;
		phead = pnew;//ͷ������
	}
	return phead;


}

void showall(node* phead)//��ʾ
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
void revshowall(node* phead) //��ת��ʾ
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

void  bubblesort(node* phead)//����
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

void  myquicksort(node* phead, node* pback)//����
{
	if (phead == pback)
	{
		return;
	}
	else
	{
		int key = phead->data;//��ȡ��һ��ֵ���ֽ���
		node* p1 = phead;
		for (node* p2 = phead->pNext; p2 != NULL; p2 = p2->pNext)
		{
			if (p2->data < key)
			{
				p1=p1->pNext;//ѭ������һ��
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

int getnum(node* phead)//����ڵ�
{
	int i = 0;
	for (; phead != NULL; phead = phead->pNext)
	{
		i++;
	}


	return i;
}
int getnumdigui(node* phead)//����ڵ�
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

node* revit(node* phead)//����ת
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


node* rev(node* phead)//����ת
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


node* revgui(node* phead)//����ת
{
	if (phead == NULL || phead->pNext == NULL)
	{
		return phead;
	}
	else
	{
		node* pnext = phead->pNext;

		node* head = revgui(pnext);

		pnext->pNext = phead;//����
		phead->pNext = NULL;



		return head;
	}





}


void ShowRinglike(node* phead)//��ʾ��������
{
	node* phead1 = phead;
	
	for (; phead1->pNext != phead; phead1 = phead1->pNext)
	{
		printf(" %d", phead1->data);
	}
	printf(" %d", phead1->data);




}

int   isit(node* phead)//�ж��Ƿ��л�
{
	int flag = 0;
	for (node* p1 = phead, *p2 = phead; p1 != NULL; p1 = p1->pNext)   //˫ָ��
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