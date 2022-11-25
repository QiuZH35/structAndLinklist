#include <stdio.h>
#include <stdlib.h>


typedef struct LinkNode  //简化类型
{
	int data;
	struct LinkNode* pNext;

}node;

void init(node* phead);//初始化
node*addback(node* phead, int data); //尾部添加节点
void addhead(node** pphead, int data);//头部添加

node* searchfirst(node* phead, int finddata);//查找数据

node* changefirst(node* phead, int finddata,int newdata);//修改一个数据

node* deletefirst(node* phead, int deldata); //删除数据

node* insertfirst(node* phead, int finddata, int newdata);//插入数据

void deleteall(node* phead);//删除全部


void  bubblesort(node* phead);//排序

void  myquicksort(node* phead, node* pback);//快排
void showall(node* phead);//显示
void revshowall(node* phead); //反转显示

void ShowRinglike(node* phead);//显示环形链表


int getnum(node* phead);//计算节点
int getnumdigui(node* phead);//计算节点


node* revit(node* phead);//链表反转

node* rev(node* phead);//链表反转
node* revgui(node* phead);//链表反转


int   isit(node* phead); //判断是否有环
