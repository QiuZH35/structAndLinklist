#pragma once
#include <stdio.h>
#include <stdlib.h>
#define typedata int

typedef struct LinkNode
{
	int id;  //�ڵ���
	typedata data;//�ڵ�����
	struct LinkNode* pNext;

}node, * PNODE;



PNODE init(PNODE phead);  //��ʼ��

PNODE push(PNODE phead, int id, typedata data);//ѹ������

PNODE pop(PNODE phead, PNODE pdata);//�³�����

PNODE clear(PNODE phead);//�������

void show(PNODE phead);