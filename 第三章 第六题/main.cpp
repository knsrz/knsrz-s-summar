#include <iostream>

using namespace std;
//-----�ṹ��
typedef struct QNode//�ڵ�ṹ��
{
    int data;
    struct QNode *next;
}QNode;
typedef struct//���нṹ��
{
    QNode*rear;//βָ��
}LinkQueue;
//--------��ʼ��
bool InitQueue(LinkQueue &q){

       q.rear=new QNode;//����ͷ���
       if(!q.rear)return false;
       q.rear->next=q.rear;//�Լ���nextָ��ָ��ͷ����γɻ�
       return true;
}
//--------���
void InQueue(LinkQueue &q,int e){
QNode *p=new QNode;//�����½ڵ�
p->data=e;//��ֵ�����½ڵ�
p->next=q.rear->next;//�½ڵ��nextָ��ͷ�ڵ�
q.rear->next=p;//β�ڵ��nextָ���½ڵ�
q.rear=p;//βָ�����
}
//-------�Ƿ�Ϊ��
bool isEmpty(LinkQueue q){
      if(q.rear->next==q.rear)return true;//β�ڵ��nextָ������ ��Ϊ��
      else return false;
}
//---------����
bool OutQueue(LinkQueue &q,int &m){
    if(isEmpty(q))return false;//
   QNode *n;//����ָ�����ڱ���Ҫɾ���Ľڵ�
   n=q.rear->next->next;//nָ����Ԫ�ڵ�
   m=n->data;//m����Ҫɾ����ֵ
   //---��ʱҪ�ж�rear��ָ���ǲ�����Ԫ�ڵ㣨����ʱֻ��һ�������ݵĽڵ㣩
   if(q.rear==n){//����ֻ��һ���ڵ�
    q.rear=q.rear->next;//�Ƚ�rearָ���Ƶ�ͷ���
    q.rear->next=q.rear;//�ٽ�ͷ���nextָ��ͷ���
   }
   else{//�������  �����ƶ�rearָ��
    q.rear->next->next=n->next;//ͷ����nextָ��ɾ���ڵ����һ���ڵ�
   }
   delete n;//�ͷŽڵ�n
    return true;
}
//--------�ÿ�
void SetEmpty(LinkQueue &q){
    QNode *n;//����ָ�����ڱ���Ҫɾ���Ľڵ�
    q.rear=q.rear->next;//βָ��ָ��ͷ���
    int m;
    while(!isEmpty(q)){//����ʱ  ��һ��ջ
         OutQueue(q,m);
    }
}
int main()
{
    return 0;
}

