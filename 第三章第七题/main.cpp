#include <iostream>

using namespace std;

//-------���е�˳��洢�ṹ
#define MAXSIZE  50//������󳤶�
typedef struct
{
    double *base;//�洢�ռ�Ļ���ַ
    int tag;
    int front;//ͷָ��
    int rear;//βָ��
}SqQueue;

//-----------1.��ʼ��
bool InitQueue(SqQueue &q){
      q.base=new double[MAXSIZE];//����ռ�
      if(!q.base)return false;//����ʧ��
      q.front=q.rear=0;//���п� ͷβָ������
      q.tag=0;
      return true;
}


//��������������ֻ�п����ö��б����������ö��б�գ�����ֻҪһ����Ӿ���tag=1���෴��
//���Ե��ҽ���rear==front&&tag=1ʱ����rear==front&&tag=0ʱ���ӿ�
//-----------3.���
bool InQueue(SqQueue &q,double e){

       if(q.tag==1&&q.rear==q.front)return false;//����
       q.base[q.rear]=e;//��e���
       q.tag=1;
       q.rear=(q.rear+1)%MAXSIZE;//βָ���ƶ�
       return true;
}

//-----------4.����
bool OutQueue(SqQueue &q,double &m){

     if(q.tag==0&&q.rear==q.front)return false;//�ӿ�
     m=q.base[q.front];//��m������������
     q.tag=0;//��tag��Ϊ���ܿյ�״̬
     q.front=(q.front+1)%MAXSIZE;//ͷָ��ı�
     return true;
}
int main()
{

    return 0;
}
