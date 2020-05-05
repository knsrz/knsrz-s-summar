#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//--------˫��ջ----
//--------�ṹ��----
#define MAXSIZE 100
typedef struct
{
    int top[2],bot[2];//ջ����ջ��ָ��
    double *v;//ջ����
    int m;//ջ��������Ԫ�ظ���
}DblStack;
//----1.��ʼ��
bool InitStack(DblStack &d){
    d.v=new double[MAXSIZE];//����ռ�
    if(!d.v)return false;//����ʧ��
    d.m=MAXSIZE;
    d.top[0]=d.bot[0]=-1;//ջ��ʱָ�븳ֵ
    d.top[1]=d.bot[1]=d.m;
    return true;
}

//-----2.�ж�ջ��
bool isEmpty(DblStack d,int a){//aΪջ�ı��
    if(a<0||a>1)exit(0);//a���Ϸ�
    if(a==0&&d.top[a]==-1)return true;//��aΪ0��ջ�ҿ�  ����true
    if(a==1&&d.top[a]==d.m)return true;//��aΪ1��ջ�ҿ�  ����true
    return false;//a��ջ���գ�����true
}
//-----3.�ж�ջ��
bool isFull(DblStack d){//aΪջ�ı��
    if(d.top[1]-d.top[0]==1)return true;//ջ�� ����true
    else return false;//ջ��
}

//-------4.��ջ
bool Push(DblStack &d,int a,double e){//aΪ����ջ  eΪ��ջԪ��
    if(a<0||a>1)exit(0);//a���Ϸ�
    if(isFull(d))return false;//ջ��
    if(a==0)d.top[a]++;//ָ��ǰ��
    else if(a==1)d.top[a]--;//ָ�����
    d.v[d.top[a]]=e;//e��ջ
    return true;
}
//-------4.��ջ
bool Pop(DblStack &d,int a,double &e){//aΪ����ջ  eΪ��ջԪ��
    if(a<0||a>1)exit(0);//a���Ϸ�
    if(isEmpty(d,a))return false;//a��ջ��
    e=d.v[d.top[a]];//ȡ��a��ջԪ��
    if(a==0)d.top[a]--;//ָ�����
    else  if(a==1)d.top[a]++;//ָ��ǰ��
    return true;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
