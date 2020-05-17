#include <iostream>

using namespace std;
#define MAXSIZE 100
int m;
double n;

//1）顺序栈的定义和基本操作

//定义顺序栈的存储结构
typedef struct {
int *base;//栈底指针
int *top;//栈尾指针
int stacksize;//栈的最大容量  用于判断是否栈满
}SqStack;

//1.初始化
bool InitStack(SqStack &s){
s.base=new int[MAXSIZE];//为顺序栈分配空间
if(!s.base)return false;//分配失败
s.top=s.base;//空栈时 top=base
s.stacksize=MAXSIZE;
return true;//分配成功
}
//2.入栈
bool Push(SqStack &s,int e){
if(s.top-s.base==s.stacksize)return false;//1.先判断是否满
*s.top=e;//元素压入栈顶
s.top++;//顶指针加一
}
//3.出栈
bool Pop(SqStack &s,int&m){
    if(s.top==s.base)return false;//栈空
    s.top--;//顶指针减1  此处和入栈相反
    m=*s.top;//取栈顶元素

}
//4.取栈顶元素
int GetTop(SqStack s){
    if(s.top!=s.base)return *(s.top-1);//栈非空
    else return NULL;//栈空 返回null
}
//输出线栈内容
void print_SqStack(SqStack s){
          while(s.top!=s.base){
           s.top--;
            cout<<(*s.top)<<"  ";
          }
           cout<<endl;
}


//2）链栈的定义和基本操作


//---------链栈存储结构
typedef struct StackNode{
     int data;//数据域
     struct StackNode  *next;//指针域
}StackNode,*LinkStack;

//--------1.将链表头作为栈顶
//---------2.不用像单链表那样设置头结点


//----------1.初始化
bool InitStack(LinkStack &s){
     s=NULL;
     return true;
}

//----------2.入栈
bool Push(LinkStack &s,int e){
      StackNode *p=new StackNode;//先为e创建一个节点
      p->data=e;//赋值给该节点
      p->next=s;//新节点插入
      s=p;//修改栈顶指针
      return true;

}
//----------3.出栈
bool Pop(LinkStack&s,int &m){
      if(s==NULL)return false;//判断空
          m=s->data;//保存栈顶元素
          StackNode*p=s;//创建节点临时保存栈顶节点
          s=s->next;//修改栈顶指针
          delete p;//释放节点
          return true;
}
//---------4.取栈顶元素
int GetTop(LinkStack l){
      if(l==NULL)return NULL;
      else return l->data;//返回栈顶元素
}
//输出链栈内容
void print_LinkStack(LinkStack l){
      while(l!=NULL){
        cout<<l->data<<"  ";
        l=l->next;
      }
      cout<<endl;
}

//3）循环队列的定义和基本操作


//-------队列的顺序存储结构
#define MAXSIZE  50//队列最大长度
typedef struct
{
    double *base;//存储空间的基地址
    int front;//头指针
    int rear;//尾指针
}SqQueue;

//-----------1.初始化
bool InitQueue(SqQueue &q){
      q.base=new double[MAXSIZE];//申请空间
      if(!q.base)return false;//申请失败
      q.front=q.rear=0;//队列空 头尾指针置零
      return true;
}

//-----------2.求队长
int GetqLength(SqQueue q){

    return (q.rear-q.front+MAXSIZE)%MAXSIZE;
}

//-----------3.入队
bool InQueue(SqQueue &q,double e){

       if((q.rear+1)%MAXSIZE==q.front)return false;//队满
       q.base[q.rear]=e;//将e入队
       q.rear=(q.rear+1)%MAXSIZE;//尾指针移动
       return true;
}

//-----------4.出队
bool OutQueue(SqQueue &q,double &m){

     if(q.rear==q.front)return false;//队空
     m=q.base[q.front];//将m传给参数带出
     q.front=(q.front+1)%MAXSIZE;//头指针改变
     return true;
}

//-----------5.取队头元素
double GetFront(SqQueue s){

      if(s.front==s.rear)return NULL;//队空
      else return s.base[s.front];//返回头指针所指元素
}

//输出循环队列
void print_sqQueue(SqQueue s){

               while(s.front!=s.rear){
                cout<<s.base[s.front]<<"  ";
                s.front= (s.front+1)%MAXSIZE;
               }
               cout<<endl;
}


//4）链队列的定义和基本操作

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
    QueuePtr p=q.front->next;//建立新指针指向首元节点，用于临时保存该节点
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
void print_LinkQueue(LinkQueue q){
     QueuePtr p=q.front->next;
     /*while(q.front!=q.rear){
        cout<<p->data<<"  ";
        q.front=q.front->next;
        p=q.front->next;
     }*/
     while(p){
        cout<<p->data<<"  ";
        p=p->next;
     }
     cout<<endl;
}

int main()
{
 //顺序栈

/*SqStack s;

InitStack(s);

Push(s,2);

Push(s,4);

Push(s,6);

print_SqStack(s);

Pop(s,m);

print_SqStack(s);
*/

//链栈

/*LinkStack l;

InitStack(l);

Push(l,4);

Push(l,5);

Push(l,6);

print_LinkStack(l);

Pop(l,m);

print_LinkStack(l);
*/

//循环队列

SqQueue s;

InitQueue(s);

InQueue(s,12);

InQueue(s,14);

InQueue(s,16);

print_sqQueue(s);

OutQueue(s,n);

print_sqQueue(s);



//链队列

/*LinkQueue l;
InitQueue(l);

InQueue(l,9);
InQueue(l,8);
InQueue(l,7);
print_LinkQueue(l);

OutQueue(l,m);
print_LinkQueue(l);*/
    return 0;
}
