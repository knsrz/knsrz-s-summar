#include <iostream>

using namespace std;
//-----结构体
typedef struct QNode//节点结构体
{
    int data;
    struct QNode *next;
}QNode;
typedef struct//队列结构体
{
    QNode*rear;//尾指针
}LinkQueue;
//--------初始化
bool InitQueue(LinkQueue &q){

       q.rear=new QNode;//生成头结点
       if(!q.rear)return false;
       q.rear->next=q.rear;//自己的next指针指向头结点形成环
       return true;
}
//--------入队
void InQueue(LinkQueue &q,int e){
QNode *p=new QNode;//生成新节点
p->data=e;//将值放入新节点
p->next=q.rear->next;//新节点的next指向头节点
q.rear->next=p;//尾节点的next指向新节点
q.rear=p;//尾指针后移
}
//-------是否为空
bool isEmpty(LinkQueue q){
      if(q.rear->next==q.rear)return true;//尾节点的next指向自身 则为空
      else return false;
}
//---------出队
bool OutQueue(LinkQueue &q,int &m){
    if(isEmpty(q))return false;//
   QNode *n;//生成指针用于保存要删除的节点
   n=q.rear->next->next;//n指向首元节点
   m=n->data;//m保存要删除的值
   //---此时要判断rear所指的是不是首元节点（即此时只有一个带数据的节点）
   if(q.rear==n){//假设只有一个节点
    q.rear=q.rear->next;//先将rear指针移到头结点
    q.rear->next=q.rear;//再将头结点next指向头结点
   }
   else{//如果不是  则不用移动rear指针
    q.rear->next->next=n->next;//头结点的next指向删除节点的下一个节点
   }
   delete n;//释放节点n
    return true;
}
//--------置空
void SetEmpty(LinkQueue &q){
    QNode *n;//生成指针用于保存要删除的节点
    q.rear=q.rear->next;//尾指针指向头结点
    int m;
    while(!isEmpty(q)){//不空时  逐一出栈
         OutQueue(q,m);
    }
}
int main()
{
    return 0;
}

