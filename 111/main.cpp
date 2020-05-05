#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct LNode{
   int data;
   struct LNode *next;
}LNode,*LinkList;

static LNode*p;    //伪指针、静态指针
static LNode*r;


//单链表初始化
bool InitList(LinkList &L){ //指针类型的引用  必须要加&  否则没法改变指针L
   L=new LNode;
   L->next=NULL;
   return true;
}
//后插法创建长度为n的链表
void CreateList_R(LinkList &L,int n){
//   L=new LNode;  //创建头结点
   //cin>>L->data;//不输入头结点数据
   L->next=NULL;

   r=L;//r为以声明过的尾指针

   for(int i=1;i<=n;i++){
    p=new LNode;//p为以声明过的一个节点指针  此处用来声明新节点
    cin>>p->data;
    p->next=NULL;
    r->next=p;//尾插
    r=p;//尾指针后移
   }
}
int DataMax(LinkList L,int n){// n为链表长度（不包括头结点）

    if(L->next==NULL)return 0;
     p=L->next;//p为前面已经定义过的指针
     LNode*tem=p;//tem保存最大值  初值为第
    for(int i=1;i<=n;i++){//从第一个开始遍历
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

