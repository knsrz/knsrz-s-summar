#include <iostream>

using namespace std;


//------单链表的存储结构
typedef struct LNode{
   int data;//数据域
   struct LNode *next;//指针域
}LNode,*LinkList;


//1）建立单链表，查找单链表，插入单链表，删除单链表
//1.初始化
bool InitList(LinkList &L){ //指针类型的引用  必须要加&  否则没法改变指针L
   L=new LNode;
   L->next=NULL;
   return true;
}
//2.后插法创建长度为n的链表  需要尾指针
void CreateList_R(LinkList &L,int n){
  InitList(L);//初始化L
   LinkList r=L;//创建尾指针
   for(int i=1;i<=n;i++){
    LinkList p=new LNode;//生成新节点
    cin>>p->data;//输入数据
    p->next=NULL;//next值空
    r->next=p;//尾插
    r=p;//尾指针后移
   }
}

//3.头插法创建长度为n的链表  需要头指针
void CreateList_H(LinkList &L,int n){
  InitList(L);//初始化L
   LinkList r=L;//创建头指针
   for(int i=1;i<=n;i++){
    LinkList p=new LNode;//生成新节点
    cin>>p->data;//输入数据
    p->next=r->next;//头差
    r->next=p;
   }
}

//4.查找
LNode *SearchE(LinkList l,int e){

     LinkList p=l->next;//初始化指针p
     while(p&&p->data!=e){//没有找到e
        p=p->next;//指针后移
     }
     return p;//返回已指向的带e节点的指针p
}

//5.插入
bool Insert(LinkList &l,int i,int e){//在链表l的第i个位置插入元素e

      LinkList p=l;//初始化p
     int k=0;
     while(p&&k<i-1){//p不为空，一直遍历到第i-1个位置
        p=p->next;k++;
     }
     if(!p||i<1){return false;}//输入的i不和法
    LinkList n=new LNode;//生成新节点
    n->data=e;
    n->next=p->next;//新节点next指向第i个位置
    p->next=n;//第i-1个位置next指向新节点
    return true;
}
//6.删除
bool Insert(LinkList &l,int i){//删除链表第i个节点

      LinkList p=l;//初始化p
     int k=0;
     while(p->next&&k<i-1){//p不为空，一直遍历到第i-1个位置
        p=p->next;k++;
     }
     if(!(p->next)||i<1){return false;}//输入的i不和法
    LinkList n=p->next;//生成新指针 临时保存要删除的节点
    p->next=n->next;//第i-1个位置的next指针指向第i个位置的后一个位置
    delete n;//释放第i个节点
    return true;
}
//2）两个有序单链表的归并运算
//有序链表归并
//假设按升序排列
void AandB(LinkList&la,LinkList&lb,LinkList&lc){
     LinkList pa=la->next,pb=lb->next;//pa，pb指向la，lc的首元节点
     lc=la;//lc等于la的头结点
     LinkList pc=lc;//指针pc指向lc的表头
     while(pa&&pb){//当指针均为到达两个链表尾部
        if(pa->data<=pb->data){//如果pa元素更小
            pc->next=pa;//pc的next指向pa
            pc=pa;//pc指针后移
            pa=pa->next;//pa指针后移
        }
        else{//与前相反
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
     }
     if(pa)pc->next=pa;//如果pa没有遍历完  则在pc位置接上pa
     else pc->next=pb;//相反
     delete lb;//释放lb的表头
}

void PrintList(LinkList L){
                LinkList p=L->next;
               while(p){
                cout<<p->data<<"  ";
                p=p->next;
               }

               cout<<endl;
}

int main()
{
    LinkList L1;
    LinkList L2;
    //后插法创建长度为5的单链表  1,3,5,7,9
    CreateList_R(L1,5);
    //头插法创建长度为6的链表2,4,6,8,10,12
    CreateList_H(L2,6);

    PrintList(L1);
    PrintList(L2);
//查找值为5的节点
LNode * tem=SearchE(L1,5);
cout<<tem->data<<endl;

//删除链表第6个节点
Insert(L2,6);
PrintList(L2);

//两个有序单链表的归并
LinkList m;
AandB(L1,L2,m);
PrintList(m);

    return 0;
}
