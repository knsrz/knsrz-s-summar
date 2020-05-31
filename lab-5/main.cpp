#include <iostream>
using namespace std;
//---------------------------图的邻接矩阵存储结构
#define MAXINT 32767  //极大值
#define MVNUM 100     //最大顶点数
typedef struct
{
    char vexs[MVNUM];     //顶点表
    int arcs[MVNUM][MVNUM]; //邻接矩阵
    int vexnum,arcnum;     //图的当前点数和边数
}AMGraph;
//用邻接矩阵创建无向网
int Location(AMGraph G, char v){//获取v对应下标函数
    for(int i=0;i<G.vexnum;i++){
        if(G.vexs[i]==v)return i;
    }
    return -1;         //未找到 返回-1
}
bool CreateUDN(AMGraph &G){
    cin>>G.vexnum>>G.arcnum;      //输入总顶点数，总边数
    for(int i=0;i<G.vexnum;i++){
        cin>>G.vexs[i];          //输入点的信息
    }

    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            G.arcs[i][j]=MAXINT;         //初始化邻接矩阵，所有边设为极大值
        }
    }
    char v1,v2;
    int w;
    int i,j;
    for(int k=0;k<G.arcnum;k++){
        cin>>v1>>v2>>w;     //依次输入一条边对应的顶点和权值
        i=Location(G,v1);j=Location(G,v2);   //确定v1和v2的下标
        G.arcs[i][j]=G.arcs[j][i]=w;         //置<v1,v2>和<v2,v1>为权值
    }
}


//-----------------------图的邻接表存储结构
#define MVNUM  100           //最大顶点数
typedef struct ArcNode       //边节点
{
   int adjvex;              //该边指向的顶点位置
   struct ArcNode * next;   //指向下一条边
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
//用邻接表创建无向图
int Location2(ALGraph G,char v){//查找 v在G中的位置
    for (int i = 0; i < G.vexnum; ++i) {
        if(G.vertices[i].data==v)return i;
    }
    return -1;//未找到
}
bool CreateUDG(ALGraph &G){
    cin>>G.vexnum>>G.arcnum;//输入顶点数，边数
    for(int i=0;i<G.vexnum;i++){//输入各点，构造表头节点表
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    char v1,v2;
    int i,j;
    ArcNode* p1,*p2;
    for (int k = 0; k <G.arcnum ; ++k) {//构造各边
        cin>>v1>>v2;//输入一条边依附的两个节点
        i=Location2(G,v1);j=Location2(G,v2);//确定v1 v2在G中的位置

        p1=new ArcNode;//生成新边节点
        p1->adjvex=j;//临接点序号为j
        p1->next=G.vertices[i].firstarc;G.vertices[i].firstarc=p1;//将新节点插入vi的边表头

        p2=new ArcNode;//生成新边节点
        p2->adjvex=i;//临接点序号为i
        p2->next=G.vertices[j].firstarc;G.vertices[j].firstarc=p2;//将新节点插入vj的边表头

    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
