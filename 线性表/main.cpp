#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define MAXSIZE 100
//----˳���洢�ṹ
struct SqList{
    int*elme;//����洢�ռ����ַ
    int length;//��ǰԪ�ظ���
    }l;
//��ʼ��
bool InitList(SqList &l){
    l.elme=new int[MAXSIZE];//����洢�ռ�
    if(!l.elme)return false;//����ʧ��
    l.length=0;//Ԫ�ظ���Ϊ0
    return true;
    }
//ȡֵ
bool getelem(SqList l,int i,int &e){
if(i>l.length||i<1)return false;//i�Ƿ�Ϸ�
e=l.elme[i-1];//����i��ȡ�ø�ֵ��e��������ɾ����Ԫ��
return true;
}
//����
int LocateElem(SqList l,int e){
for(int i=0;i<l.length;i++){//����˳���
    if(l.elme[i]==e)return i+1;//�ҵ�������Ԫ���±��1
              return NULL;//δ�ҵ� ���ؿ�ֵ
}
return 0;
}
//����
bool Insert(SqList &l,int i,int e){//����Ԫ�س��뵽��i��λ��
if(i<0||i>l.length+1)return false;//�ж��Ƿ�Ϸ�   i����length+1�ֲ鷨
if(l.length==MAXSIZE)return false;//˳�������
for(int j=l.length-1;j>=i-1;j--)//�Ӻ���ǰ���� ÿ������һ�����㽫������ƶ�  �ƶ���i-1��Ԫ�غ�ֹͣ
    l.elme[j+1]=l.elme[j];//
l.elme[i-1]=e;//���뵽��i-1��λ��
l.length++;//���ȼ�1
return true;
}
//ɾ�� ��i��Ԫ��
bool Delete(SqList &l,int i){
if(i<1||i>l.length)return false;//i���Ϸ�  ����Ϊlength  ����lengthԪ�ؿ�ɾ��
for(int j=i;j<=l.length-1;j++)//�ӵ�i����ʼ����  ����i���Ƶ���i-1��λ��  Ȼ�����κ���
    l.elme[j-1]=l.elme[j];//
l.length--;//���ȼ�1
return true;
}
//�󲢼�
SqList And(SqList m1,SqList m2){
      for(int i=0;i<m2.length;i++){//����m2
        if(LocateElem(m1,m2.elme[i])==NULL){//���m1�в�����m2�еĸ�Ԫ��
           if(m1.length!=MAXSIZE) Insert(m1,m1.length+1,m2.elme[i]);//���m1û���� ���˳������λ�ò���m1�ĸ�Ԫ��
                else exit(0);}//������� �����MAXSIZE���ȵ�˳���治�¸ò��� ��ֹ
      }
     return m1;//���ز������
}
//�󽻼�
SqList Intersection(SqList m1,SqList m2){
    SqList tem;//����˳����潻�ʽ��
    InitList(tem);//��ʼ���ñ�
      for(int i=0;i<m2.length;i++){//������m2
        if(LocateElem(m1,m2.elme[i])!=NULL);//���m1�к���m2�е����Ԫ��
           Insert(tem,tem.length+1,m2.elme[i]);//�����Ԫ�ز��뵽˳������λ��
      }
     return tem;//���ؽ������
}
//���
SqList Subtraction(SqList m1,SqList m2){
      for(int i=0;i<m2.length;i++){//������m2
        if(LocateElem(m1,m2.elme[i])!=NULL)//���m1�к���m2�е����Ԫ��
          Delete(m1,i+1);//�����Ԫ�ش�m1��ɾ��
      }
     return m1;//���ز���
}
//10.ɾ������ֵΪitem��Ԫ��  ���Ա�����֪
void DeleteItem(SqList &l,int n,int item){
    int j=n-1;//jָ�����Ա�β
    for(int i=0;i<l.length;i++){//�������Ա�
            while(l.elme[j]==item){ j--;l.length--;}//ȷ����βԪ�ز�Ϊitem
        if(l.elme[i]==item){
         l.elme[i]=l.elme[j];//����βԪ���滻����λ��
         j--;
         l.length--;
        }
    }


}
int main()
{
    //��ʼ��
    InitList(l);
    //��ֵ
    for(int i=0;i<10;i++){
        l.elme[i]=i+1;
        l.length++;
    }
    //ȡֵ
   // int m;
    //getelem(l,2,m);
    //printf("%d\n",m);
    //����
    //printf("%d\n",LocateElem(l,6));

    //����
    //Insert(l,3,11);

    //ɾ��
    //Delete(l,4);

    return 0;
}
