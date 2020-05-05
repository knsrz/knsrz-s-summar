#include <iostream>

using namespace std;
#define MAXSIZE 100

//����ջ�Ĵ洢�ṹ
typedef struct {
int *base;//ջ��ָ��
int *top;//ջβָ��
int stacksize;//ջ���������  �����ж��Ƿ�ջ��
}SqStack;

//1.��ʼ��
bool InitStack(SqStack &s){
s.base=new int[MAXSIZE];//Ϊ˳��ջ����ռ�
if(!s.base)return false;//����ʧ��
s.top=s.base;//��ջʱ top=base
s.stacksize=MAXSIZE;
return true;//����ɹ�
}
//2.��ջ
bool Push(SqStack &s,int e){
if(s.top-s.base==s.stacksize)return false;//1.���ж��Ƿ���
*s.top=e;//Ԫ��ѹ��ջ��
s.top++;//��ָ���һ
}
//3.��ջ
bool Pop(SqStack &s,int&m){
    if(s.top==s.base)return false;//ջ��
    s.top--;//��ָ���1  �˴�����ջ�෴
    m=*s.top;//ȡջ��Ԫ��

}
//4.ȡջ��Ԫ��
int GetTop(SqStack s){
    if(s.top!=s.base)return *(s.top-1);
    else return NULL;
}


int main()
{
    SqStack s;
    InitStack(s);
    Push(s,1);
    Push(s,2);
    Push(s,3);
    int a;
    Pop(s,a);
    cout<<a<<endl;
    Pop(s,a);
    cout<<a<<endl;
    a=GetTop(s);
    cout<<a<<endl;
    return 0;
}
