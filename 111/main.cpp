#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct LNode{
   int data;
   struct LNode *next;
}LNode,*LinkList;

static LNode*p;    //αָ�롢��ָ̬��
static LNode*r;


//�������ʼ��
bool InitList(LinkList &L){ //ָ�����͵�����  ����Ҫ��&  ����û���ı�ָ��L
   L=new LNode;
   L->next=NULL;
   return true;
}
//��巨��������Ϊn������
void CreateList_R(LinkList &L,int n){
//   L=new LNode;  //����ͷ���
   //cin>>L->data;//������ͷ�������
   L->next=NULL;

   r=L;//rΪ����������βָ��

   for(int i=1;i<=n;i++){
    p=new LNode;//pΪ����������һ���ڵ�ָ��  �˴����������½ڵ�
    cin>>p->data;
    p->next=NULL;
    r->next=p;//β��
    r=p;//βָ�����
   }
}
int DataMax(LinkList L,int n){// nΪ�����ȣ�������ͷ��㣩

    if(L->next==NULL)return 0;
     p=L->next;//pΪǰ���Ѿ��������ָ��
     LNode*tem=p;//tem�������ֵ  ��ֵΪ��
    for(int i=1;i<=n;i++){//�ӵ�һ����ʼ����
        if(tem->data<p->data)tem=p;
        p=p->next;
    }
   return tem->data;
}

int PrintLinkList(LinkList L){

    p=L->next;
    while(p){
        cout<<p->data;
        p=p->next;
    }
}

int main()
{
LinkList L;
InitList(L);
CreateList_R(L,5);

PrintLinkList(L);
DataMax(L,5);
}

