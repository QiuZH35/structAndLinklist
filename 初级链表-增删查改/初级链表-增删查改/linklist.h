#include <stdio.h>
#include <stdlib.h>


typedef struct LinkNode  //������
{
	int data;
	struct LinkNode* pNext;

}node;

void init(node* phead);//��ʼ��
node*addback(node* phead, int data); //β����ӽڵ�
void addhead(node** pphead, int data);//ͷ�����

node* searchfirst(node* phead, int finddata);//��������

node* changefirst(node* phead, int finddata,int newdata);//�޸�һ������

node* deletefirst(node* phead, int deldata); //ɾ������

node* insertfirst(node* phead, int finddata, int newdata);//��������

void deleteall(node* phead);//ɾ��ȫ��


void  bubblesort(node* phead);//����

void  myquicksort(node* phead, node* pback);//����
void showall(node* phead);//��ʾ
void revshowall(node* phead); //��ת��ʾ

void ShowRinglike(node* phead);//��ʾ��������


int getnum(node* phead);//����ڵ�
int getnumdigui(node* phead);//����ڵ�


node* revit(node* phead);//����ת

node* rev(node* phead);//����ת
node* revgui(node* phead);//����ת


int   isit(node* phead); //�ж��Ƿ��л�
