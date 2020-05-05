#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define MAXSIZE 100
//----顺序表存储结构
struct SqList{
    int*elme;//定义存储空间基地址
    int length;//当前元素个数
    }l;
//初始化
bool InitList(SqList &l){
    l.elme=new int[MAXSIZE];//分配存储空间
    if(!l.elme)return false;//分配失败
    l.length=0;//元素个数为0
    return true;
    }
//取值
bool getelem(SqList l,int i,int &e){
if(i>l.length||i<1)return false;//i是否合法
e=l.elme[i-1];//将第i个取得赋值给e，但不是删除该元素
return true;
}
//查找
int LocateElem(SqList l,int e){
for(int i=0;i<l.length;i++){//遍历顺序表
    if(l.elme[i]==e)return i+1;//找到，返回元素下标加1
              return NULL;//未找到 返回空值
}
return 0;
}
//插入
bool Insert(SqList &l,int i,int e){//将新元素出入到第i个位置
if(i<0||i>l.length+1)return false;//判断是否合法   i共有length+1种查法
if(l.length==MAXSIZE)return false;//顺序表已满
for(int j=l.length-1;j>=i-1;j--)//从后向前遍历 每遍历到一个，便将其向后移动  移动第i-1个元素后停止
    l.elme[j+1]=l.elme[j];//
l.elme[i-1]=e;//插入到第i-1个位置
l.length++;//长度加1
return true;
}
//删除 第i个元素
bool Delete(SqList &l,int i){
if(i<1||i>l.length)return false;//i不合法  长度为length  共有length元素可删除
for(int j=i;j<=l.length-1;j++)//从第i个开始遍历  将第i个移到第i-1的位置  然后依次后移
    l.elme[j-1]=l.elme[j];//
l.length--;//长度减1
return true;
}
//求并集
SqList And(SqList m1,SqList m2){
      for(int i=0;i<m2.length;i++){//遍历m2
        if(LocateElem(m1,m2.elme[i])==NULL){//如果m1中不含有m2中的该元素
           if(m1.length!=MAXSIZE) Insert(m1,m1.length+1,m2.elme[i]);//如果m1没有满 则从顺序表最后位置插入m1的该元素
                else exit(0);}//如果满了 则表明MAXSIZE长度的顺序表存不下该并集 终止
      }
     return m1;//返回并集结果
}
//求交集
SqList Intersection(SqList m1,SqList m2){
    SqList tem;//建立顺序表保存交际结果
    InitList(tem);//初始化该表
      for(int i=0;i<m2.length;i++){//遍历表m2
        if(LocateElem(m1,m2.elme[i])!=NULL);//如果m1中含有m2中的这个元素
           Insert(tem,tem.length+1,m2.elme[i]);//将这个元素插入到顺序表最后位置
      }
     return tem;//返回交集结果
}
//求差
SqList Subtraction(SqList m1,SqList m2){
      for(int i=0;i<m2.length;i++){//遍历表m2
        if(LocateElem(m1,m2.elme[i])!=NULL)//如果m1中含有m2中的这个元素
          Delete(m1,i+1);//将这个元素从m1中删除
      }
     return m1;//返回差结果
}
//10.删除所有值为item的元素  线性表长度已知
void DeleteItem(SqList &l,int n,int item){
    int j=n-1;//j指向线性表尾
    for(int i=0;i<l.length;i++){//遍历线性表
            while(l.elme[j]==item){ j--;l.length--;}//确保表尾元素不为item
        if(l.elme[i]==item){
         l.elme[i]=l.elme[j];//将表尾元素替换到此位置
         j--;
         l.length--;
        }
    }


}
int main()
{
    //初始化
    InitList(l);
    //赋值
    for(int i=0;i<10;i++){
        l.elme[i]=i+1;
        l.length++;
    }
    //取值
   // int m;
    //getelem(l,2,m);
    //printf("%d\n",m);
    //查找
    //printf("%d\n",LocateElem(l,6));

    //插入
    //Insert(l,3,11);

    //删除
    //Delete(l,4);

    return 0;
}
