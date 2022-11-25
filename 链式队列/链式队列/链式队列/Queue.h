
#include <stdio.h>
#include <stdlib.h>


#define typedata  int

typedef struct Queue
{
	typedata data;
	struct Queue*pNext;

}Queue,*Pqueue;


void init(Pqueue* phead);//初始化
Pqueue Enqueue(Pqueue phead, typedata data);//入队
Pqueue Dequeue(Pqueue phead,typedata *pdata);//出队
void show(Pqueue phead);