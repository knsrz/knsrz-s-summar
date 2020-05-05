#include <iostream>

using namespace std;
//-----结点的存储结构
typedef struct QNode
{
    int data;//数据域
    struct QNode *next;//指针域
}QNode,*QueuePtr;
//-------链队的存储结构
typedef struct
{
    QueuePtr rear;//尾指针
    QueuePtr front;//头指针
}LinkQueue;
//初始化
bool InitQueue(LinkQueue &q){

       q.front=q.rear=new QNode;//生成头结点，头尾指针都指向该节点
       q.front->next=NULL;//头结点next域为空
       return true;
}
//-----入队
bool InQueue(LinkQueue &q,int e){
QueuePtr p=new QNode;//生成新节点
p->data=e;//新节点的数据为入队数据
p->next=NULL;//新节点的next赋空
q.rear->next=p;//尾节点next指向新节点
q.rear=p;//尾指针后移
return true;
}
//----------出队
bool OutQueue(LinkQueue &q,int &m){
    if(q.front==q.rear)return false;//空队
    Queueptr p=q.front->next;//建立新指针指向首元节点，用于临时保存该节点
    m=q.front->next->data;//保存要删除节点的数据
    q.front->next=p->next;//头结点的next指向首元节点的后一个节点
    if(q.rear=p)q.rear=q.front;//若尾节点就是首元节点，为了防止删除尾指针，需要将尾指针前移
    delete p;//释放删除的节点空间
    return true;
}
//取队顶元素
int GetFront(LinkQueue q){

  if(q.front==q.rear)return NULL;//队空
  return q.front->next->data;//返回队顶数据
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
