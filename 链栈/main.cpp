#include <iostream>

using namespace std;
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
      if(s==NUll)return false;//�жϿ�
          m=s->data;//����ջ��Ԫ��
          StackNode*p=s;//�����ڵ���ʱ����ջ���ڵ�
          s=s->next;//�޸�ջ��ָ��
          delete p;//�ͷŽڵ�
          return true;
}
//---------4.ȡջ��Ԫ��
int GetTop(LinkStack l){
      if(l==null)return null;
      else return l->data;//����ջ��Ԫ��
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
