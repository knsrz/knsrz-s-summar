#include <iostream>

using namespace std;
#define MAXSIZE 100
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

//ǰ�������������(�ݹ���ʽ��
void FrontTraverse(BiTree T){
       if(T==NULL) return;
       else{                                 //Tָ�벻Ϊ��
      cout<<T->data;
       InOrderTraverse(T->lchild);
       InOrderTraverse(T->rchild);
       }
}
//���������������(�ݹ���ʽ��
void RearTraverse(BiTree T){
       if(T==NULL) return;
       else{                                 //Tָ�벻Ϊ
       InOrderTraverse(T->lchild);
       InOrderTraverse(T->rchild);
       cout<<T->data;
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
//�������������
//�ȶ�����д洢�ṹ
typedef struct
{
   BiTree *base;//�洢�ռ�Ļ���ַ
    int front;//ͷָ��
    int rear;//βָ��
}SqQueue;
bool InitQueue(SqQueue &q){
      q.base=new BiTree[MAXSIZE];//����ռ�
      if(!q.base)return false;//����ʧ��
      q.front=q.rear=0;//���п� ͷβָ������
      return true;
}
bool InQueue(SqQueue &q,BiTree e){

       if((q.rear+1)%MAXSIZE==q.front)return false;//����
       q.base[q.rear]=e;//��e���
       q.rear=(q.rear+1)%MAXSIZE;//βָ���ƶ�
       return true;
}
bool OutQueue(SqQueue &q,BiTree &m){

     if(q.rear==q.front)return false;//�ӿ�
     m=q.base[q.front];//��m������������
     q.front=(q.front+1)%MAXSIZE;//ͷָ��ı�
     return true;
}
void levelTree(BiTree b){

          SqQueue s;
          InitQueue(s);

          BiTree tem;
          InQueue(s,b);
          while(s.front!=s.rear){
            OutQueue(s,tem);
            cout<<tem->data;

            if(tem->lchild) InQueue(s,tem->lchild);
            if(tem->rchild)InQueue(s,tem->rchild);
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


//��������
//���������Ĵ洢�ṹ
typedef struct{

   int weight;
   int parent,lchild,rchild;
}HTNode,*HTree;
//�����������
void  Select(HTree H,int n,int &s1,int &s2){//�ҵ�Ȩ����С��������� ���±��s1 s2

         for(int i=1;i<=n;i++){
                if(H[i].parent==0){
                    s1=i;
                }
            }

            for(int i=1;i<=n;i++){
                if(H[i].parent==0){
                    if(H[i].weight<H[s1].weight){s1=i;}
                }
            }

            for(int i=1;i<=n;i++){
                if(H[i].parent==0&&i!=s1){
                    s2=i;
                }
            }
            for(int i=1;i<=n;i++){
                if(H[i].parent==0&&i!=s1){
                    if(H[i].weight<H[s2].weight){s2=i;}
                }
            }
}
void CreateHTree(HTree &H,int n){

              if(n<=1) return;
              int m=2*n-1;
              H=new HTNode[m+1];//��ʹ��0�ŵ�Ԫ

              for(int i=1;i<=m;i++){//��ʼ��ÿһ���ڵ�
                H[i].parent=0;H[i].lchild=0;H[i].rchild=0;
              }

              for(int j=1;j<=n;j++){//����Ȩ��
                cin>>H[j].weight;
              }

              int s1,s2;
              for(int i=n+1;i<=m;i++){
              Select(H,i-1,s1,s2);
              H[s1].parent=i;H[s2].parent=i;

              H[i].lchild=s1;H[i].rchild=s2;
              H[i].weight=(H[s1].weight+H[s2].weight);

              }

}
int main()
{
  /*BiTree T;
   CreateBiTree(T);
   cout<<"����"<<endl;
   InOrderTraverse(T);
    cout<<"ǰ��"<<endl;
   FrontTraverse(T);
    cout<<"����"<<endl;
   RearTraverse(T);
cout<<"����"<<endl;
   levelTree(T);

   cout<<endl;
  cout<<"���"<<Depth(T)<<endl;
cout<<"�ڵ���"<<CountNode(T)<<endl;*/


HTree h;
CreateHTree(h,4);
for(int i=1 ;i<=7;i++){
    cout<<h[i].weight<<"   ";
}



    return 0;
}
