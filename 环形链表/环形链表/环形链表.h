
#include <stdio.h>
#include <stdlib.h>


typedef struct Linknode
{
	int data;
	struct Linknode* pNext;


}node,*PNODE;  //�ṹ�������ָ��ṹ��Ľṹ��ָ��


PNODE addback(PNODE phead, int data);//β������
PNODE addrnot(PNODE phead, int data);//ͷ������

void show(PNODE);//��ʾ

PNODE findfirst(PNODE phead, int data);//��������

PNODE deletedata(PNODE phead, int deldata);//ɾ��

PNODE deletedatap(PNODE phead, int deldata,PNODE *pphead);//ɾ��

int getnum(PNODE phead);//��ȡ��������Ľڵ�

void showall(PNODE phead);//��ʾ

PNODE insertdata(PNODE phead, int finddata, int newdata);//��������