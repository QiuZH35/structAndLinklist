
#include <stdio.h>
#include <stdlib.h>


typedef struct Linknode
{
	int data;
	struct Linknode* pNext;


}node,*PNODE;  //结构体变量，指向结构体的结构体指针


PNODE addback(PNODE phead, int data);//尾部插入
PNODE addrnot(PNODE phead, int data);//头部插入

void show(PNODE);//显示

PNODE findfirst(PNODE phead, int data);//查找数据

PNODE deletedata(PNODE phead, int deldata);//删除

PNODE deletedatap(PNODE phead, int deldata,PNODE *pphead);//删除

int getnum(PNODE phead);//获取环形链表的节点

void showall(PNODE phead);//显示

PNODE insertdata(PNODE phead, int finddata, int newdata);//插入数据