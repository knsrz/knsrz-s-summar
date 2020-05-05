#include <iostream>

using namespace std;
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

//前序复制二叉树
void Copy(BiTree T,BiTree &copyT){
        if(T==NULL)return ;
        else{
            copyT=new BiTNode;
            copyT->data=T->data;
            Copy(T->lchild,copyT->lchild);
            Copy(T->rchild,copyT->rchild);
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


int main()
{
   BiTree T;
   CreateBiTree(T);
   InOrderTraverse(T);
   cout<<"深度"<<Depth(T)<<endl;
   cout<<"节点数"<<CountNode(T);

    return 0;
}
