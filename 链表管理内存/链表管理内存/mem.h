//#pragma once

#include <stdio.h>
#include <stdlib.h>




void* mymalloc(size_t size);
void myfree(void* p);
void* myrealloc(void* p, size_t size);




//��¼�����ڴ�Ĵ�С���͵�ַ
struct Mem
{
	void* p;
	int size;
};



 typedef struct LinkNode
{
	struct Mem* Pmem;  //����ָ��
	struct LinkNode* pNext; //ָ����һ���ڵ�

}node,*PNODE;

 struct LinkNode* phead;//����



 PNODE addback(PNODE phead, struct Mem* pmem);//����һ������
 PNODE change(PNODE phead, void* pfind, struct Mem* pnewmem);//�޸�

 PNODE findit(PNODE phead, void* pfind); 
 PNODE delnode(PNODE phead, void* paddr);//���ݵ�ַɾ��
 void showall(PNODE phead);//��ʾ

 void getinfo(PNODE phead);//ʵʱ����ڴ�

 PNODE delall(PNODE phead);//ɾ��ȫ��