#include <iostream>

using namespace std;

//-------���е�˳��洢�ṹ
#define MAXSIZE  50//������󳤶�
typedef struct
{
    double *base;//�洢�ռ�Ļ���ַ
    int front;//ͷָ��
    int rear;//βָ��
}SqQueue;

//-----------1.��ʼ��
bool InitQueue(SqQueue &q){
      q.base=new double[MAXSIZE];//����ռ�
      if(!q.base)return false;//����ʧ��
      q.front=q.rear=0;//���п� ͷβָ������
      return true;
}

//-----------2.��ӳ�
int GetqLength(SqQueue q){

    return (q.rear-q.front+MAXSIZE)%MAXSIZE;
}

//-----------3.���
bool InQueue(SqQueue &q,double e){

       if((q.rear+1)%MAXSIZE==q.front)return false;//����
       q.base[q.rear]=e;//��e���
       q.rear=(q.rear+1)%MAXSIZE;//βָ���ƶ�
       return true;
}

//-----------4.����
bool OutQueue(SqQueue &q,double &m){

     if(q.rear==q.front)return false;//�ӿ�
     m=q.base[q.front];//��m������������
     q.front=(q.front+1)%MAXSIZE;//ͷָ��ı�
     return true;
}

//-----------5.ȡ��ͷԪ��
double GetFront(SqQueue s){

      if(s.front==s.rear)return NULL;//�ӿ�
      else return s.base[s.front];//����ͷָ����ָԪ��
}
int main()
{
   SqQueue s;
   InitQueue(s);
   InQueue(s,2.1);
   InQueue(s,3.0);
   InQueue(s,4.44);
   int l=GetqLength(s);
   cout<<"�ӳ�"<<l<<endl;
  double m1;
   OutQueue(s,m1);
   double m2;
   OutQueue(s,m2);
   cout<<"����"<<m1<<"  "<<m2<<endl;
   cout<<"ȡ��ͷ"<<GetFront(s);
    return 0;
}
