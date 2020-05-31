#include <iostream>
//---------------------------图的邻接矩阵存储结构
#define MAXINT 32767  //极大值
#define MVUNM 100     //最大顶点数
typedef struct
{
    char vexs[MVNUM];     //顶点表
    int arcs[MVNUM][MVNUM]; //邻接矩阵
    int vexnum,arcnum;     //图的当前点数和边数
}AMGraph;
//用邻接矩阵创建无向网
bool CreateUDN(AMGraph &G){
    cin>>G.vexnum>>arcnum;      //输入总顶点数，总边数
    for(int i=0;i<G.vexnum;i++){
        cin>>G.vex[i];          //输入点的信息
    }

    for(int i=0;i<vexnum;i++){
        for(int j=0;j<vexnum;j++){
            G.arcs[i][j]=MACINT;         //初始化邻接矩阵，所有边设为极大值
        }
    }
    char v1,v2;
    int w;
    for(int i=0;i<arcnum;i++){
        cin>>v1>>v2>>w;     //依次输入一条边对应的顶点和权值
        i=Location(G,v1);j=Location(G,v2);   //确定v1和v2的下标
        G.arcs[i][j]=G.arcs[j][i]=w;         //置<v1,v2>和<v2,v1>为权值
    }
}
int Location(AMGraph G, char v){//获取v对应下标函数
    for(int i=0;i<G.vexnum;i++){
        if(G.vexs[i]==v)return i;
    }
    return -1;         //未找到 返回-1
}

//-----------------------图的邻接表存储结构
#define MVNUM  100           //最大顶点数
typedef struct ArcNode       //边节点
{
   int adjvex;              //该边指向的顶点位置
   struct ArcNode * next;   //指向下一条边
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
