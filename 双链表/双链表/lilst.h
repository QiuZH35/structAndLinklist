#include <stdio.h>
#include <stdlib.h>


typedef struct Listnode
{
	int data;
	struct Listnode* pPre;//ͷ�ڵ�
	struct Listnode* pNext;//Ϊ�ڵ�

}node;

typedef struct head
{
	node* head;//ָ��ͷ��
	node* tail;//ָ��β��


}List;


void init(List* p);//��ʼ��

void adddatahead(List* p, int data);//ͷ������
void adddataback(List* p, int data);//β������

node* find(List* p,int data);
node* revfind(List* p,int data);

void insertdata(List* p, int data,int newdata);//����
void deldata(List* p, int data);//ɾ��

void show(List* p);
void revshow(List* p);