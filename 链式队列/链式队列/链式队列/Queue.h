
#include <stdio.h>
#include <stdlib.h>


#define typedata  int

typedef struct Queue
{
	typedata data;
	struct Queue*pNext;

}Queue,*Pqueue;


void init(Pqueue* phead);//��ʼ��
Pqueue Enqueue(Pqueue phead, typedata data);//���
Pqueue Dequeue(Pqueue phead,typedata *pdata);//����
void show(Pqueue phead);