#include <iostream>

using namespace std;
#define MAXSIZE 100

//定义栈的存储结构
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
