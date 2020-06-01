#include <iostream>
using namespace std;
//---------------------------ͼ���ڽӾ���洢�ṹ
#define MAXINT 32767  //����ֵ
#define MVNUM 100     //��󶥵���
typedef struct
{
    char vexs[MVNUM];     //�����
    int arcs[MVNUM][MVNUM]; //�ڽӾ���
    int vexnum,arcnum;     //ͼ�ĵ�ǰ�����ͱ���
}AMGraph;
//���ڽӾ��󴴽�������
int Location(AMGraph G, char v){//��ȡv��Ӧ�±꺯��
    for(int i=0;i<G.vexnum;i++){
        if(G.vexs[i]==v)return i;
    }
    return -1;         //δ�ҵ� ����-1
}
bool CreateUDN(AMGraph &G){
    cout<<"���붥�����ͱ���"<<endl;
    cin>>G.vexnum>>G.arcnum;      //�����ܶ��������ܱ���
    cout<<"���붥�����Ϣ"<<endl;
    for(int i=0;i<G.vexnum;i++){
        cin>>G.vexs[i];          //��������Ϣ
    }

    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            G.arcs[i][j]=MAXINT;         //��ʼ���ڽӾ������б���Ϊ����ֵ
        }
    }
    char v1,v2;
    int w;
    int i,j;
    for(int k=0;k<G.arcnum;k++){
        cout<<"����һ������������Ͷ�ӦȨֵ"<<endl;
        cin>>v1>>v2>>w;     //��������һ���߶�Ӧ�Ķ����Ȩֵ
        i=Location(G,v1);j=Location(G,v2);   //ȷ��v1��v2���±�
        G.arcs[i][j]=G.arcs[j][i]=w;         //��<v1,v2>��<v2,v1>ΪȨֵ
    }
}


//-----------------------ͼ���ڽӱ�洢�ṹ
#define MVNUM  100           //��󶥵���
typedef struct ArcNode       //�߽ڵ�
{
   int adjvex;              //�ñ�ָ��Ķ���λ��
   struct ArcNode * next;   //ָ����һ����
}ArcNode;
typedef struct VNode
{
    char data;
    ArcNode *firstarc;
}VNode,AdjList[MVNUM];
typedef struct {
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
//���ڽӱ�������ͼ
int Location2(ALGraph G,char v){//���� v��G�е�λ��
    for (int i = 0; i < G.vexnum; ++i) {
        if(G.vertices[i].data==v)return i;
    }
    return -1;//δ�ҵ�
}
bool CreateUDG(ALGraph &G){
    cin>>G.vexnum>>G.arcnum;//���붥����������
    for(int i=0;i<G.vexnum;i++){//������㣬�����ͷ�ڵ��
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    char v1,v2;
    int i,j;
    ArcNode* p1,*p2;
    for (int k = 0; k <G.arcnum ; ++k) {//�������
        cin>>v1>>v2;//����һ���������������ڵ�
        i=Location2(G,v1);j=Location2(G,v2);//ȷ��v1 v2��G�е�λ��

        p1=new ArcNode;//�����±߽ڵ�
        p1->adjvex=j;//�ٽӵ����Ϊj
        p1->next=G.vertices[i].firstarc;G.vertices[i].firstarc=p1;//���½ڵ����vi�ı߱�ͷ

        p2=new ArcNode;//�����±߽ڵ�
        p2->adjvex=i;//�ٽӵ����Ϊi
        p2->next=G.vertices[j].firstarc;G.vertices[j].firstarc=p2;//���½ڵ����vj�ı߱�ͷ

    }
    return true;
}
//-------------DFS
//�ڽӾ���DFS
void DFS_AM(AMGraph G,int v,bool visited[])//�ӵ�v����������������
{
    cout<<v;visited[v]=true;//���ʵ�v���ڵ㣬�����
    for(int k=0;k<G.vexnum;k++){
        if((G.arcs[v][k]!=MAXINT)&&!visited[k])DFS_AM(G,k,visited);
    }
}
//------------BFS
//�ڽӾ���BFS
//�ȶ������
#define MAXSIZE  50//������󳤶�
typedef struct
{
    int *base;//�洢�ռ�Ļ���ַ
    int front;//ͷָ��
    int rear;//βָ��
}SqQueue;

//��ʼ��
bool InitQueue(SqQueue &q){
    q.base=new int[MAXSIZE];//����ռ�
    if(!q.base)return false;//����ʧ��
    q.front=q.rear=0;//���п� ͷβָ������
    return true;
}
//���
bool InQueue(SqQueue &q,int e){

    if((q.rear+1)%MAXSIZE==q.front)return false;//����
    q.base[q.rear]=e;//��e���
    q.rear=(q.rear+1)%MAXSIZE;//βָ���ƶ�
    return true;
}

//����
bool OutQueue(SqQueue &q,int &m){

    if(q.rear==q.front)return false;//�ӿ�
    m=q.base[q.front];//��m������������
    q.front=(q.front+1)%MAXSIZE;//ͷָ��ı�
    return true;
}
int FirstAdjVex(AMGraph G,int u)//���Һ�u�����ĵ�һ���ڽӵ����
{
    for (int i = 0; i <G.vexnum ; ++i) {
        if(G.arcs[u][i]!=MAXINT)return i;
    }
    return -1;//δ�ҵ�
}
int NextAdjVex(AMGraph G,int u,int w)//���Һ�u������ ��u��Ķ������
{
    for (int i = w+1; i <G.vexnum ; ++i) {
        if(G.arcs[u][i]!=MAXINT)return i;
    }
    return -1;//δ�ҵ�
}
void BFS_AM(AMGraph G,int v,bool visited[],SqQueue Q)
{
   cout<<v;visited[v]=true;//���ʵ�v�����㣬�����
   InitQueue(Q);//��ʼ������
    InQueue(Q,v);//v���
    while (!(Q.rear==Q.front))//�Ӳ���
    {
     int u;
        OutQueue(Q,u);  //��ͷԪ�س��ӣ�����u
        for(int w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
            if(!visited[w])
            {
                cout<<w;visited[w]=true;
                InQueue(Q,w);
            }
    }
}
//------------�Ͻ�˹�������·��
void ShortesPath_DIJ(AMGraph G,int v0)//��v0�������������·��
{

    int n=G.vexnum;       //nΪG�ж������
    bool S[n];
    int D[n];
    int Path[n];
    for (int i = 0; i <n ; ++i) {
        S[i]=false;
        D[i]=G.arcs[v0][i];
        if(D[v0]<MAXINT)Path[i]=v0;
        else Path[i]=-1;
    }
    S[v0]=true;
    D[v0]=0;
    //-------------------
    int v;
    for (int i = 0; i <n ; ++i) {
        int min=MAXINT;
        for (int w = 0; w <n ; ++w) {
            if(!S[w]&&D[w]<min){v=w;min=D[w];}
        }
        S[v]=true;
        for (int w = 0; w <n ; ++w) {
            if(!S[w]&&(D[v]+G.arcs[v][w])<D[w])
            {
                D[w]=D[v]+G.arcs[v][w];
                Path[w]=v;
            }
        }
    }

    for (int j = 0; j < n; ++j) {
        cout<<"��"<<G.vexs[j]<<"���"<<D[j]<<" ";
    }

}
int main() {

    AMGraph G;
    CreateUDN(G);
    bool visited[G.vexnum];
    for(int i=0;i<G.vexnum;i++)visited[i]=false;
    SqQueue Q;
    cout<<"DFS"<<endl;
    DFS_AM(G,0,visited);

    cout<<endl;
    for(int i=0;i<G.vexnum;i++)visited[i]=false;
    cout<<"BFS"<<endl;
    BFS_AM(G,0,visited,Q);

    cout<<endl;
    cout<<"�Ͻ�˹����"<<endl;
    ShortesPath_DIJ(G,0);

    return 0;
}
