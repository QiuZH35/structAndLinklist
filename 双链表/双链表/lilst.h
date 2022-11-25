#include <stdio.h>
#include <stdlib.h>


typedef struct Listnode
{
	int data;
	struct Listnode* pPre;//头节点
	struct Listnode* pNext;//为节点

}node;

typedef struct head
{
	node* head;//指向头部
	node* tail;//指向尾部


}List;


void init(List* p);//初始化

void adddatahead(List* p, int data);//头部插入
void adddataback(List* p, int data);//尾部插入

node* find(List* p,int data);
node* revfind(List* p,int data);

void insertdata(List* p, int data,int newdata);//插入
void deldata(List* p, int data);//删除

void show(List* p);
void revshow(List* p);