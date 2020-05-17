#include <iostream>

using namespace std;


//------������Ĵ洢�ṹ
typedef struct LNode{
   int data;//������
   struct LNode *next;//ָ����
}LNode,*LinkList;


//1���������������ҵ��������뵥����ɾ��������
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

     LinkList p=l->next;//��ʼ��ָ��p
     while(p&&p->data!=e){//û���ҵ�e
        p=p->next;//ָ�����
     }
     return p;//������ָ��Ĵ�e�ڵ��ָ��p
}

//5.����
bool Insert(LinkList &l,int i,int e){//������l�ĵ�i��λ�ò���Ԫ��e

      LinkList p=l;//��ʼ��p
     int k=0;
     while(p&&k<i-1){//p��Ϊ�գ�һֱ��������i-1��λ��
        p=p->next;k++;
     }
     if(!p||i<1){return false;}//�����i���ͷ�
    LinkList n=new LNode;//�����½ڵ�
    n->data=e;
    n->next=p->next;//�½ڵ�nextָ���i��λ��
    p->next=n;//��i-1��λ��nextָ���½ڵ�
    return true;
}
//6.ɾ��
bool Insert(LinkList &l,int i){//ɾ�������i���ڵ�

      LinkList p=l;//��ʼ��p
     int k=0;
     while(p->next&&k<i-1){//p��Ϊ�գ�һֱ��������i-1��λ��
        p=p->next;k++;
     }
     if(!(p->next)||i<1){return false;}//�����i���ͷ�
    LinkList n=p->next;//������ָ�� ��ʱ����Ҫɾ���Ľڵ�
    p->next=n->next;//��i-1��λ�õ�nextָ��ָ���i��λ�õĺ�һ��λ��
    delete n;//�ͷŵ�i���ڵ�
    return true;
}
//2��������������Ĺ鲢����
//��������鲢
//���谴��������
void AandB(LinkList&la,LinkList&lb,LinkList&lc){
     LinkList pa=la->next,pb=lb->next;//pa��pbָ��la��lc����Ԫ�ڵ�
     lc=la;//lc����la��ͷ���
     LinkList pc=lc;//ָ��pcָ��lc�ı�ͷ
     while(pa&&pb){//��ָ���Ϊ������������β��
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
    //��巨��������Ϊ5�ĵ�����  1,3,5,7,9
    CreateList_R(L1,5);
    //ͷ�巨��������Ϊ6������2,4,6,8,10,12
    CreateList_H(L2,6);

    PrintList(L1);
    PrintList(L2);
//����ֵΪ5�Ľڵ�
LNode * tem=SearchE(L1,5);
cout<<tem->data<<endl;

//ɾ�������6���ڵ�
Insert(L2,6);
PrintList(L2);

//������������Ĺ鲢
LinkList m;
AandB(L1,L2,m);
PrintList(m);

    return 0;
}
