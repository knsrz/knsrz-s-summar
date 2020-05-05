#include <iostream>

using namespace std;
typedef struct BiTNode{
           char data;//������
           struct BiTNode *lchild,*rchild;//���Һ���

}BiTNode,*BiTree;

//���������������(�ݹ���ʽ��
void InOrderTraverse(BiTree T){
       if(T==NULL) return;
       else{                                 //Tָ�벻Ϊ��
       InOrderTraverse(T->lchild);
       cout<<T->data;
       InOrderTraverse(T->rchild);
       }
}

//��˳�����������������

void CreateBiTree(BiTree &T){
    cout<<"����"<<endl;
    char integer;   //����������
    cin>>integer;
    if(integer=='#') {T=NULL; return;}   //������# �������ٴ����ڵ�
    else{
        T=new BiTNode;  //�ڵ��ʼ��
        T->data=integer;
         cout<<"����һ��"<<endl;
        CreateBiTree(T->lchild);   //���ǲ��ǻ�Ҫ����
         CreateBiTree(T->rchild);//���ǲ��ǻ�Ҫ�Һ���
    }
}

//ǰ���ƶ�����
void Copy(BiTree T,BiTree &copyT){
        if(T==NULL)return ;
        else{
            copyT=new BiTNode;
            copyT->data=T->data;
            Copy(T->lchild,copyT->lchild);
            Copy(T->rchild,copyT->rchild);
        }
}

//������������

int Depth(BiTree T){
        int m,n;
        if(T==NULL) return 0;
        else{
            m=Depth(T->lchild);
            n=Depth(T->rchild);
            if(m>n)return (m+1);
            else return (n+1);
        }
}

//ͳ�ƶ������нڵ����
int CountNode(BiTree T){

     if(T==NULL)return 0;
     else return CountNode(T->lchild)+CountNode(T->rchild)+1;
}


int main()
{
   BiTree T;
   CreateBiTree(T);
   InOrderTraverse(T);
   cout<<"���"<<Depth(T)<<endl;
   cout<<"�ڵ���"<<CountNode(T);

    return 0;
}
