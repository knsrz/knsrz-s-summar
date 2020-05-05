#include <iostream>

using namespace std;
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
      if(s==NUll)return false;//判断空
          m=s->data;//保存栈顶元素
          StackNode*p=s;//创建节点临时保存栈顶节点
          s=s->next;//修改栈顶指针
          delete p;//释放节点
          return true;
}
//---------4.取栈顶元素
int GetTop(LinkStack l){
      if(l==null)return null;
      else return l->data;//返回栈顶元素
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
