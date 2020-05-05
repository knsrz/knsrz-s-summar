#include <iostream>

using namespace std;
#define MAXSIZE 100;
typedef struct BiTNode{
           char data;//������
           struct BiTNode *lchild,*rchild;//���Һ���

}BiTNode,*BiTree;

//-------���е�˳��洢�ṹ
#define MAXSIZE  50//������󳤶�
typedef struct
{
    BiTree *base;//�洢�ռ�Ļ���ַ
    int front;//ͷָ��
    int rear;//βָ��
}SqQueue;

//-----------1.��ʼ��
bool InitQueue(SqQueue &q){
      q.base=new BiTree[MAXSIZE];//����ռ�
      if(!q.base)return false;//����ʧ��
      q.front=q.rear=0;//���п� ͷβָ������
      return true;
}

//���
bool InQueue(SqQueue &q,BiTree e){

       if((q.rear+1)%MAXSIZE==q.front)return false;//����
       q.base[q.rear]=e;//��e���
       q.rear=(q.rear+1)%MAXSIZE;//βָ���ƶ�
       return true;
}

//-----------4.����
bool OutQueue(SqQueue &q,BiTree &m){

     if(q.rear==q.front)return false;//�ӿ�
     m=q.base[q.front];//��m������������
     q.front=(q.front+1)%MAXSIZE;//ͷָ��ı�
     return true;
}


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


//(1)ͳ�ƶ�������Ҷ�ڵ����
void CountLeaf(BiTree T,int &sum){//
        if(T==NULL)return;//
        else{
            CountLeaf(T->lchild,sum);
            CountLeaf(T->rchild,sum);
            if(T->lchild==NULL&&T->rchild==NULL)sum++;
        }
}
//(2)�ж��������Ƿ����
bool IsEqual(BiTree T1,BiTree T2){//
    if(T1==NULL&&T2==NULL) return true;//���ڵ㶼��
    if((T1==NULL&&T2!=NULL)||(T2==NULL&&T1==NULL))return false;//�������һ��Ϊ����һ����Ϊ�� �����
    if(T1->data!=T2->data)return false;//  ������㶼����  ��������ͬ  �����
       return  IsEqual(T1->lchild,T2->lchild)&&IsEqual(T1->rchild,T2->rchild);//   �����������бȽ�

}

//��3�����������������Һ���
void changeChild(BiTree &T){
     if(!T->lchild&&!T->rchild)return;//���Һ��Ӷ���  ����


     BiTree tem;//��ʱ�ڵ�   �����ҽڵ㽻��
     tem=T->lchild;//
     T->lchild=T->rchild;//
     T->rchild=tem;//

     changeChild(T->lchild);//�������ĸ����ڵ㽻��
     changeChild(T->rchild);//������������㽻��

}

//(6)�����˳�����������������ͳ�����ж�Ϊ1�Ľڵ���Ŀ
int countOne(BiTree T){//������� �ö���
          int sum=0;//��¼��Ϊ1����
          SqQueue s;
          InitQueue(s);//��ʼ��һ������
         if(T==NULL)return sum;//���ڵ�Ϊ��
         InQueue(s,T);//���ڵ����
         while(!(s.front==s.rear)){//���в���
                BiTree tem;//��ʱ������ӽڵ�
                 OutQueue(s,tem);//����
            if((tem->lchild==NULL&&tem->rchild!=NULL)||(tem->lchild!=NULL&&tem->rchild==NULL))sum++;//�˽ڵ��Ϊ1��������һ
            if(tem->lchild!=NULL)InQueue(s,tem->lchild);//���Ӳ���  ���
             if(tem->rchild!=NULL)InQueue(s,tem->rchild);//�Һ��Ӳ���  ���
         }
return sum;


}

int main()
{
    int sum=0;
   BiTree T1;
   BiTree T2;
   CreateBiTree(T1);
   InOrderTraverse(T1);
    //CreateBiTree(T2);
  // InOrderTraverse(T2);
   //CountLeaf(T,sum);
  //cout<<"Ҷ��"<<sum<<endl;

  //cout<<IsEqual(T1,T2);
  //changeChild(T1);

  cout<<countOne(T1);
//InOrderTraverse(T1);

    return 0;
}
