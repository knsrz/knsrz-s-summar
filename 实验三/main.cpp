#include <iostream>

using namespace std;
#define MAXSIZE 100
int m;
double n;

//1��˳��ջ�Ķ���ͻ�������

//����˳��ջ�Ĵ洢�ṹ
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
    if(s.top!=s.base)return *(s.top-1);//ջ�ǿ�
    else return NULL;//ջ�� ����null
}
//�����ջ����
void print_SqStack(SqStack s){
          while(s.top!=s.base){
           s.top--;
            cout<<(*s.top)<<"  ";
          }
           cout<<endl;
}


//2����ջ�Ķ���ͻ�������


//---------��ջ�洢�ṹ
typedef struct StackNode{
     int data;//������
     struct StackNode  *next;//ָ����
}StackNode,*LinkStack;

//--------1.������ͷ��Ϊջ��
//---------2.������������������ͷ���


//----------1.��ʼ��
bool InitStack(LinkStack &s){
     s=NULL;
     return true;
}

//----------2.��ջ
bool Push(LinkStack &s,int e){
      StackNode *p=new StackNode;//��Ϊe����һ���ڵ�
      p->data=e;//��ֵ���ýڵ�
      p->next=s;//�½ڵ����
      s=p;//�޸�ջ��ָ��
      return true;

}
//----------3.��ջ
bool Pop(LinkStack&s,int &m){
      if(s==NULL)return false;//�жϿ�
          m=s->data;//����ջ��Ԫ��
          StackNode*p=s;//�����ڵ���ʱ����ջ���ڵ�
          s=s->next;//�޸�ջ��ָ��
          delete p;//�ͷŽڵ�
          return true;
}
//---------4.ȡջ��Ԫ��
int GetTop(LinkStack l){
      if(l==NULL)return NULL;
      else return l->data;//����ջ��Ԫ��
}
//�����ջ����
void print_LinkStack(LinkStack l){
      while(l!=NULL){
        cout<<l->data<<"  ";
        l=l->next;
      }
      cout<<endl;
}

//3��ѭ�����еĶ���ͻ�������


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

//���ѭ������
void print_sqQueue(SqQueue s){

               while(s.front!=s.rear){
                cout<<s.base[s.front]<<"  ";
                s.front= (s.front+1)%MAXSIZE;
               }
               cout<<endl;
}


//4�������еĶ���ͻ�������

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
    QueuePtr p=q.front->next;//������ָ��ָ����Ԫ�ڵ㣬������ʱ����ýڵ�
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
void print_LinkQueue(LinkQueue q){
     QueuePtr p=q.front->next;
     /*while(q.front!=q.rear){
        cout<<p->data<<"  ";
        q.front=q.front->next;
        p=q.front->next;
     }*/
     while(p){
        cout<<p->data<<"  ";
        p=p->next;
     }
     cout<<endl;
}

int main()
{
 //˳��ջ

/*SqStack s;

InitStack(s);

Push(s,2);

Push(s,4);

Push(s,6);

print_SqStack(s);

Pop(s,m);

print_SqStack(s);
*/

//��ջ

/*LinkStack l;

InitStack(l);

Push(l,4);

Push(l,5);

Push(l,6);

print_LinkStack(l);

Pop(l,m);

print_LinkStack(l);
*/

//ѭ������

SqQueue s;

InitQueue(s);

InQueue(s,12);

InQueue(s,14);

InQueue(s,16);

print_sqQueue(s);

OutQueue(s,n);

print_sqQueue(s);



//������

/*LinkQueue l;
InitQueue(l);

InQueue(l,9);
InQueue(l,8);
InQueue(l,7);
print_LinkQueue(l);

OutQueue(l,m);
print_LinkQueue(l);*/
    return 0;
}
