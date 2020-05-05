#include <iostream>

using namespace std;

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
int main()
{
   SqQueue s;
   InitQueue(s);
   InQueue(s,2.1);
   InQueue(s,3.0);
   InQueue(s,4.44);
   int l=GetqLength(s);
   cout<<"队长"<<l<<endl;
  double m1;
   OutQueue(s,m1);
   double m2;
   OutQueue(s,m2);
   cout<<"出队"<<m1<<"  "<<m2<<endl;
   cout<<"取队头"<<GetFront(s);
    return 0;
}
