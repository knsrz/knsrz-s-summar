#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//--------双端栈----
//--------结构体----
#define MAXSIZE 100
typedef struct
{
    int top[2],bot[2];//栈顶和栈底指针
    double *v;//栈数组
    int m;//栈最大可容纳元素个数
}DblStack;
//----1.初始化
bool InitStack(DblStack &d){
    d.v=new double[MAXSIZE];//分配空间
    if(!d.v)return false;//分配失败
    d.m=MAXSIZE;
    d.top[0]=d.bot[0]=-1;//栈空时指针赋值
    d.top[1]=d.bot[1]=d.m;
    return true;
}

//-----2.判断栈空
bool isEmpty(DblStack d,int a){//a为栈的编号
    if(a<0||a>1)exit(0);//a不合法
    if(a==0&&d.top[a]==-1)return true;//若a为0号栈且空  返回true
    if(a==1&&d.top[a]==d.m)return true;//若a为1号栈且空  返回true
    return false;//a号栈不空，返回true
}
//-----3.判断栈满
bool isFull(DblStack d){//a为栈的编号
    if(d.top[1]-d.top[0]==1)return true;//栈满 返回true
    else return false;//栈空
}

//-------4.进栈
bool Push(DblStack &d,int a,double e){//a为几号栈  e为进栈元素
    if(a<0||a>1)exit(0);//a不合法
    if(isFull(d))return false;//栈满
    if(a==0)d.top[a]++;//指针前移
    else if(a==1)d.top[a]--;//指针后移
    d.v[d.top[a]]=e;//e入栈
    return true;
}
//-------4.出栈
bool Pop(DblStack &d,int a,double &e){//a为几号栈  e为进栈元素
    if(a<0||a>1)exit(0);//a不合法
    if(isEmpty(d,a))return false;//a号栈空
    e=d.v[d.top[a]];//取出a号栈元素
    if(a==0)d.top[a]--;//指针后移
    else  if(a==1)d.top[a]++;//指针前移
    return true;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
