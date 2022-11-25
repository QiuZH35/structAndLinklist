//#pragma once

#include <stdio.h>
#include <stdlib.h>




void* mymalloc(size_t size);
void myfree(void* p);
void* myrealloc(void* p, size_t size);




//记录分配内存的大小，和地址
struct Mem
{
	void* p;
	int size;
};



 typedef struct LinkNode
{
	struct Mem* Pmem;  //保存指针
	struct LinkNode* pNext; //指向下一个节点

}node,*PNODE;

 struct LinkNode* phead;//声明



 PNODE addback(PNODE phead, struct Mem* pmem);//插入一个数据
 PNODE change(PNODE phead, void* pfind, struct Mem* pnewmem);//修改

 PNODE findit(PNODE phead, void* pfind); 
 PNODE delnode(PNODE phead, void* paddr);//根据地址删除
 void showall(PNODE phead);//显示

 void getinfo(PNODE phead);//实时监测内存

 PNODE delall(PNODE phead);//删除全部