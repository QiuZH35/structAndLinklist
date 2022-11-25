#pragma once
#include <stdio.h>
#include <stdlib.h>
#define typedata int

typedef struct LinkNode
{
	int id;  //节点编号
	typedata data;//节点数据
	struct LinkNode* pNext;

}node, * PNODE;



PNODE init(PNODE phead);  //初始化

PNODE push(PNODE phead, int id, typedata data);//压入数据

PNODE pop(PNODE phead, PNODE pdata);//吐出数据

PNODE clear(PNODE phead);//清空数据

void show(PNODE phead);