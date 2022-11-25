
#include "lilst.h"

void main()
{
	List dlist;
	init(&dlist);
	/*adddatahead(&dlist, 1);
	adddatahead(&dlist, 2);
	adddatahead(&dlist, 3);
	adddatahead(&dlist, 4);
	adddatahead(&dlist, 5);*/



	adddataback(&dlist, 1);
	adddataback(&dlist, 2);
	adddataback(&dlist, 3);
	adddataback(&dlist, 4);
	adddataback(&dlist, 5);
	
	
	//deldata(&dlist, 5);
	insertdata(&dlist, 1, 99);
	insertdata(&dlist, 4, 99);

	show(&dlist);

	printf("\n\n");

	revshow(&dlist);
		



	system("pause");
}