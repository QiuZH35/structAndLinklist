

#define _CRT_SECURE_NO_WARNINGS
#include "环形链表.h"


void main22()
{
	PNODE phead = NULL;
	for (int i = 0; i < 10; i++)
	{
		//phead = addback(phead, i);
		phead = addrnot(phead, i);
	}
	show(phead);


	/*PNODE pfind = findfirst(phead, 0);
	pfind->data = 30;*/

	//phead = deletedata(phead, 1);
	phead = insertdata(phead, 9, 99);
	show(phead);

	//printf("\n%d", getnum(phead));

	system("pause");

}

void  main()
{
	PNODE phead = NULL;
	for (int i = 0; i < 10; i++)
	{
		//phead = addback(phead, i);
		phead = addrnot(phead, i);
	}
	show(phead);

	PNODE p = phead;
	while (getnum(phead) != 1)
	{
		for (int i = 0; i < 4; i++)
		{
			p = p->pNext;
		}
		phead = deletedatap(phead, p->data, &p);
		printf("\n\n");
		showall(phead);//初始化
	}



	system("pause");
}