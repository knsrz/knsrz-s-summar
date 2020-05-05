#include <iostream>

using namespace std;
#define MAXSIZE 100;
typedef struct BiTNode{
           char data;//数据域
           struct BiTNode *lchild,*rchild;//左右孩子

}BiTNode,*BiTree;

//-------队列的顺序存储结构
#define MAXSIZE  50//队列最大长度
typedef struct
{
    BiTree *base;//存储空间的基地址
    int front;//头指针
    int rear;//尾指针
}SqQueue;

//-----------1.初始化
bool InitQueue(SqQueue &q){
      q.base=new BiTree[MAXSIZE];//申请空间
      if(!q.base)return false;//申请失败
      q.front=q.rear=0;//队列空 头尾指针置零
      return true;
}

//入队
bool InQueue(SqQueue &q,BiTree e){

       if((q.rear+1)%MAXSIZE==q.front)return false;//队满
       q.base[q.rear]=e;//将e入队
       q.rear=(q.rear+1)%MAXSIZE;//尾指针移动
       return true;
}

//-----------4.出队
bool OutQueue(SqQueue &q,BiTree &m){

     if(q.rear==q.front)return false;//队空
     m=q.base[q.front];//将m传给参数带出
     q.front=(q.front+1)%MAXSIZE;//头指针改变
     return true;
}


//中序遍历二叉链表(递归形式）
void InOrderTraverse(BiTree T){
       if(T==NULL) return;
       else{                                 //T指针不为空
       InOrderTraverse(T->lchild);
       cout<<T->data;
       InOrderTraverse(T->rchild);
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


//(1)统计二叉树中叶节点个数
void CountLeaf(BiTree T,int &sum){//
        if(T==NULL)return;//
        else{
            CountLeaf(T->lchild,sum);
            CountLeaf(T->rchild,sum);
            if(T->lchild==NULL&&T->rchild==NULL)sum++;
        }
}
//(2)判断两棵树是否相等
bool IsEqual(BiTree T1,BiTree T2){//
    if(T1==NULL&&T2==NULL) return true;//两节点都空
    if((T1==NULL&&T2!=NULL)||(T2==NULL&&T1==NULL))return false;//两个结点一个为空另一个不为空 不相等
    if(T1->data!=T2->data)return false;//  两个结点都不空  但数据域不同  不相等
       return  IsEqual(T1->lchild,T2->lchild)&&IsEqual(T1->rchild,T2->rchild);//   左右子树进行比较

}

//（3）交换二叉树的左右孩子
void changeChild(BiTree &T){
     if(!T->lchild&&!T->rchild)return;//左右孩子都空  结束


     BiTree tem;//临时节点   将左右节点交换
     tem=T->lchild;//
     T->lchild=T->rchild;//
     T->rchild=tem;//

     changeChild(T->lchild);//左子树的各个节点交换
     changeChild(T->rchild);//右子树各个结点交换

}

//(6)按层次顺序遍历二叉树方法，统计树中度为1的节点数目
int countOne(BiTree T){//按层遍历 用队列
          int sum=0;//记录度为1个数
          SqQueue s;
          InitQueue(s);//初始化一个队列
         if(T==NULL)return sum;//根节点为空
         InQueue(s,T);//根节点入队
         while(!(s.front==s.rear)){//队列不空
                BiTree tem;//临时保存出队节点
                 OutQueue(s,tem);//出队
            if((tem->lchild==NULL&&tem->rchild!=NULL)||(tem->lchild!=NULL&&tem->rchild==NULL))sum++;//此节点度为1，计数加一
            if(tem->lchild!=NULL)InQueue(s,tem->lchild);//左孩子不空  入队
             if(tem->rchild!=NULL)InQueue(s,tem->rchild);//右孩子不空  入队
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
  //cout<<"叶子"<<sum<<endl;

  //cout<<IsEqual(T1,T2);
  //changeChild(T1);

  cout<<countOne(T1);
//InOrderTraverse(T1);

    return 0;
}
