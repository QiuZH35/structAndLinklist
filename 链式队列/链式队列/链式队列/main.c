#include "Queue.h"


void main()
{

	Queue *phead ;
	init(&phead);
	for (int i = 0;i < 10;i++)
	{

		phead = Enqueue(phead, i);
		printf("\nqueue");
		show(phead);
	}
	printf("\n\n\n");
	while(phead !=NULL)
	{
		typedata pdata;
		
		phead = Dequeue(phead,&pdata);
		printf("\nÍÂ³öµÄ%d\n",pdata);
		show(phead);
	}
	

	system("pause");
}