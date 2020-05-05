#include <iostream>

using namespace std;

//-------队列的顺序存储结构
#define MAXSIZE  50//队列最大长度
typedef struct
{
    double *base;//存储空间的基地址
    int tag;
    int front;//头指针
    int rear;//尾指针
}SqQueue;

//-----------1.初始化
bool InitQueue(SqQueue &q){
      q.base=new double[MAXSIZE];//申请空间
      if(!q.base)return false;//申请失败
      q.front=q.rear=0;//队列空 头尾指针置零
      q.tag=0;
      return true;
}


//分析：如果入队则只有可能让队列变慢，出队让队列变空；所以只要一旦入队就让tag=1，相反；
//所以当且仅当rear==front&&tag=1时满，rear==front&&tag=0时，队空
//-----------3.入队
bool InQueue(SqQueue &q,double e){

       if(q.tag==1&&q.rear==q.front)return false;//队满
       q.base[q.rear]=e;//将e入队
       q.tag=1;
       q.rear=(q.rear+1)%MAXSIZE;//尾指针移动
       return true;
}

//-----------4.出队
bool OutQueue(SqQueue &q,double &m){

     if(q.tag==0&&q.rear==q.front)return false;//队空
     m=q.base[q.front];//将m传给参数带出
     q.tag=0;//将tag置为可能空的状态
     q.front=(q.front+1)%MAXSIZE;//头指针改变
     return true;
}
int main()
{

    return 0;
}
