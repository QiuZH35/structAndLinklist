
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void main11()
{
	list<int>mylist;//˫����
	for (int i = 0;i < 10;i++)
	{

		mylist.push_back(i);//���

	}
	for (auto i : mylist)
	{
		printf("%d ", i);
	}
}