
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void show(int* p, int length)
{
	printf("\n\n");
	for (int i = 0; i < length; i++)
	{
		printf("%4d", *(p + i));
	}


}


void myqsort(int* p, int start, int end)
{
	if (start < end)
	{
		int i = start; //·Ö½çÏß
		for (int j = i + 1; j <= end; j++)
		{
			if (p[j] < p[start]) {
				i++;
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
		int temp = p[i];
		p[i] = p[start];
		p[start] = temp;



		myqsort(p, start, i - 1);
		myqsort(p, i + 1, end);

	}

}


void main12()
{
	int a[10] = { 7,8,45,3,2,56,6,86,85,90 };

	show(a, 10);
	
	myqsort(a, 0, 9);

	show(a, 10);



	system("pause");
}