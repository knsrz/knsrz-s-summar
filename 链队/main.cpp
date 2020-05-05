#include <iostream>

using namespace std;
//-----���Ĵ洢�ṹ
typedef struct QNode
{
    int data;//������
    struct QNode *next;//ָ����
}QNode,*QueuePtr;
//-------���ӵĴ洢�ṹ
typedef struct
{
    QueuePtr rear;//βָ��
    QueuePtr front;//ͷָ��
}LinkQueue;
//��ʼ��
bool InitQueue(LinkQueue &q){

       q.front=q.rear=new QNode;//����ͷ��㣬ͷβָ�붼ָ��ýڵ�
       q.front->next=NULL;//ͷ���next��Ϊ��
       return true;
}
//-----���
bool InQueue(LinkQueue &q,int e){
QueuePtr p=new QNode;//�����½ڵ�
p->data=e;//�½ڵ������Ϊ�������
p->next=NULL;//�½ڵ��next����
q.rear->next=p;//β�ڵ�nextָ���½ڵ�
q.rear=p;//βָ�����
return true;
}
//----------����
bool OutQueue(LinkQueue &q,int &m){
    if(q.front==q.rear)return false;//�ն�
    Queueptr p=q.front->next;//������ָ��ָ����Ԫ�ڵ㣬������ʱ����ýڵ�
    m=q.front->next->data;//����Ҫɾ���ڵ������
    q.front->next=p->next;//ͷ����nextָ����Ԫ�ڵ�ĺ�һ���ڵ�
    if(q.rear=p)q.rear=q.front;//��β�ڵ������Ԫ�ڵ㣬Ϊ�˷�ֹɾ��βָ�룬��Ҫ��βָ��ǰ��
    delete p;//�ͷ�ɾ���Ľڵ�ռ�
    return true;
}
//ȡ�Ӷ�Ԫ��
int GetFront(LinkQueue q){

  if(q.front==q.rear)return NULL;//�ӿ�
  return q.front->next->data;//���ضӶ�����
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
