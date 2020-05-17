#include <iostream>

using namespace std;
#define MAXSIZE 100
typedef struct BiTNode{
           char data;//数据域
           struct BiTNode *lchild,*rchild;//左右孩子

}BiTNode,*BiTree;

//中序遍历二叉链表(递归形式）
void InOrderTraverse(BiTree T){
       if(T==NULL) return;
       else{                                 //T指针不为空
       InOrderTraverse(T->lchild);
       cout<<T->data;
       InOrderTraverse(T->rchild);
       }
}

//前序遍历二叉链表(递归形式）
void FrontTraverse(BiTree T){
       if(T==NULL) return;
       else{                                 //T指针不为空
      cout<<T->data;
       InOrderTraverse(T->lchild);
       InOrderTraverse(T->rchild);
       }
}
//后序遍历二叉链表(递归形式）
void RearTraverse(BiTree T){
       if(T==NULL) return;
       else{                                 //T指针不为
       InOrderTraverse(T->lchild);
       InOrderTraverse(T->rchild);
       cout<<T->data;
       }
}


//先顺序遍历创建二叉链表

void CreateBiTree(BiTree &T){
    cout<<"输入"<<endl;
    char integer;   //待输入数据
    cin>>integer;
    if(integer=='#') {T=NULL; return;}   //若输入# 表明不再创建节点
    else{
        T=new BiTNode;  //节点初始化
        T->data=integer;
         cout<<"建好一个"<<endl;
        CreateBiTree(T->lchild);   //看是不是还要左孩子
         CreateBiTree(T->rchild);//看是不是还要右孩子
    }
}
//层序遍历二叉树
//先定义队列存储结构
typedef struct
{
   BiTree *base;//存储空间的基地址
    int front;//头指针
    int rear;//尾指针
}SqQueue;
bool InitQueue(SqQueue &q){
      q.base=new BiTree[MAXSIZE];//申请空间
      if(!q.base)return false;//申请失败
      q.front=q.rear=0;//队列空 头尾指针置零
      return true;
}
bool InQueue(SqQueue &q,BiTree e){

       if((q.rear+1)%MAXSIZE==q.front)return false;//队满
       q.base[q.rear]=e;//将e入队
       q.rear=(q.rear+1)%MAXSIZE;//尾指针移动
       return true;
}
bool OutQueue(SqQueue &q,BiTree &m){

     if(q.rear==q.front)return false;//队空
     m=q.base[q.front];//将m传给参数带出
     q.front=(q.front+1)%MAXSIZE;//头指针改变
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

//计算二叉树深度

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

//统计二叉树中节点个数
int CountNode(BiTree T){

     if(T==NULL)return 0;
     else return CountNode(T->lchild)+CountNode(T->rchild)+1;
}


//哈夫曼树
//哈夫曼树的存储结构
typedef struct{

   int weight;
   int parent,lchild,rchild;
}HTNode,*HTree;
//构造哈夫曼树
void  Select(HTree H,int n,int &s1,int &s2){//找到权重最小的两个结点 将下表给s1 s2

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
              H=new HTNode[m+1];//不使用0号单元

              for(int i=1;i<=m;i++){//初始化每一个节点
                H[i].parent=0;H[i].lchild=0;H[i].rchild=0;
              }

              for(int j=1;j<=n;j++){//输入权重
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
   cout<<"中序"<<endl;
   InOrderTraverse(T);
    cout<<"前序"<<endl;
   FrontTraverse(T);
    cout<<"后序"<<endl;
   RearTraverse(T);
cout<<"层序"<<endl;
   levelTree(T);

   cout<<endl;
  cout<<"深度"<<Depth(T)<<endl;
cout<<"节点数"<<CountNode(T)<<endl;*/


HTree h;
CreateHTree(h,4);
for(int i=1 ;i<=7;i++){
    cout<<h[i].weight<<"   ";
}



    return 0;
}
