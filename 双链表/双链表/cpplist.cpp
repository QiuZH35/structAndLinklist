
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void main11()
{
	list<int>mylist;//Ë«Á´±í
	for (int i = 0;i < 10;i++)
	{

		mylist.push_back(i);//ºó²å

	}
	for (auto i : mylist)
	{
		printf("%d ", i);
	}
}