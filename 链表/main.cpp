#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//------������Ĵ洢�ṹ
typedef struct LNode{
   int data;//������
   struct LNode *next;//ָ����
}LNode,*LinkList;



//1.��ʼ��
bool InitList(LinkList &L){ //ָ�����͵�����  ����Ҫ��&  ����û���ı�ָ��L
   L=new LNode;
   L->next=NULL;
   return true;
}
//2.��巨��������Ϊn������  ��Ҫβָ��
void CreateList_R(LinkList &L,int n){
  InitList(L);//��ʼ��L
   LinkList r=L;//����βָ��
   for(int i=1;i<=n;i++){
    LinkList p=new LNode;//�����½ڵ�
    cin>>p->data;//��������
    p->next=NULL;//nextֵ��
    r->next=p;//β��
    r=p;//βָ�����
   }
}

//3.ͷ�巨��������Ϊn������  ��Ҫͷָ��
void CreateList_H(LinkList &L,int n){
  InitList(L);//��ʼ��L
   LinkList r=L;//����ͷָ��
   for(int i=1;i<=n;i++){
    LinkList p=new LNode;//�����½ڵ�
    cin>>p->data;//��������
    p->next=r->next;//ͷ��
    r->next=p;
   }
}

//4.����
LNode *SearchE(LinkList l,int e){

     LinkList p=l.next;//��ʼ��ָ��p
     while(p&&p->data!=e){//û���ҵ�e
        p=p->next;//ָ�����
     }
     return p;//������ָ��Ĵ�e�ڵ��ָ��p
}
//5.����
bool Insert(LinkList &l,int i,int e){//������l�ĵ�i��λ�ò���Ԫ��e

      LinkList p=l;//��ʼ��p
     k=0;
     while(p&&k<i-1){//p��Ϊ�գ�һֱ��������i-1��λ��
        p=p->next;k++;
     }
     if(!p&&i<1){return false;}//�����i���ͷ�
    LinkList n=new LNode;//�����½ڵ�
    n->data=e;
    n->next=p->next;//�½ڵ�nextָ���i��λ��
    p->next=n;//��i-1��λ��nextָ���½ڵ�
    return true;
}
//6.ɾ��
bool Insert(LinkList &l,int i){//ɾ�������i���ڵ�

      LinkList p=l;//��ʼ��p
     k=0;
     while(p->next&&k<i-1){//p��Ϊ�գ�һֱ��������i-1��λ��
        p=p->next;k++;
     }
     if(!(p->next)&&i<1){return false;}//�����i���ͷ�
    LinkList n=p->next;//������ָ�� ��ʱ����Ҫɾ���Ľڵ�
    p->next=n->next;//��i-1��λ�õ�nextָ��ָ���i��λ�õĺ�һ��λ��
    delete n;//�ͷŵ�i���ڵ�
    return true;
}
//��������鲢
//���谴��������
void AandB(LinkList&la,LinkList&lb,LinkList&lc){
     LinkList pa=la->next,pb=lb->next;//pa��pbָ��la��lc����Ԫ�ڵ�
     lc=la;//lc����la��ͷ���
     LinkList pc=lc;//ָ��pcָ��lc�ı�ͷ
     while(la&&lb){//��ָ���Ϊ������������β��
        if(pa->data<=pb->data){//���paԪ�ظ�С
            pc->next=pa;//pc��nextָ��pa
            pc=pa;//pcָ�����
            pa=pa->next;//paָ�����
        }
        else{//��ǰ�෴
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
     }
     if(pa)pc->next=pa;//���paû�б�����  ����pcλ�ý���pa
     else pc->next=pb;//�෴
     delete lb;//�ͷ�lb�ı�ͷ
}
//���������������
void CoutLdata(LinkList L){
    p=L->next;//pָ���һ���ڵ�
while(p){
    cout<<p->data<<endl;
    p=p->next;
}
}

//6.�������Ϊn�������е����ֵ
LNode* DataMax(LinkList L,int n){// nΪ�����ȣ�������ͷ��㣩
    if(L->next==NULL)return NULL;
     p=L->next;//pΪǰ���Ѿ��������ָ��
     LNode*tem=p;//tem�������ֵ  ��ֵΪ��
    for(int i=1;i<=n;i++){//�ӵ�һ����ʼ����
        if(tem->data<p->data)tem=p;
        p=p->next;
    }
   return tem;
}

//7. ��ת���� ��֪����ĳ���
void reverseLNode(LinkList &L,int n){//nΪ����ڵ��� ������ͷ���
    //������Ĭ�������ǿ�  ����û������Ϊ�յ����
    LNode*tem=NULL;//������ʱ����δ��ת���ֵı� ��ֹ��ʧ
    LNode*cur=L->next;//����ָ��δ��ת���ֵĵ�һ��λ��
    LNode*pre=NULL;//����ָ���ѷ�ת�õĲ��ֵĵ�һ��λ��
    for(int i=1;i<=n;i++){//��ת����ͷ�������Ľڵ�
        tem=cur->next;//��ʱ����δ��ת���ֵ�һ��λ�ú���Ĳ���
        cur->next=pre;//��δ��ת���ֵ�һ��λ�ýӵ���ת�õ�ͷ��
        pre=cur;//��ǰ�ƶ���ͷ��
        cur=tem;//cur����ָ��δת�öε�ͷ��
    }
    L->next=pre;//��ͷ������ȥ
}

int main()
{
LinkList L;//����ͷָ��
//��������Ϊ5������
CreateList_R(L,5);
//��ת����
//reverseLNode(L,5);
//�������
//CoutLdata(L);
//������ֵ
LNode* a;
a=DataMax(L,5);
cout<<a->data;


    return 0;
}
