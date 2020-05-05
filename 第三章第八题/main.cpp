#include <iostream>

using namespace std;

#define MAXSIZE 100
typedef struct{
	int *data;
	int front,rear;
}SqlQueue;
//-----从队尾删除
bool DeFromRear(SqlQueue Q,int &m){//从队尾删除
	if (Q.front==Q.rear)return false;//队空
	Q.rear=(Q.rear-1+MAXSIZE)%MAXSIZE; 	// 修改队尾指针。
	m=Q.data[Q.rear];//保存删除元素
	return true；
}
//------从队头插入
bool InFromFront(SqlQueue Q, int e){
	if(Q.front==(Q.rear+1+MAXSIZE)%MAXSIZE)return false;
	Q.front=(Q.front-1+MAXSIZE)%MAXSIZE; 		// 修改队头指针。
	Q.data[Q.front]=e;//元素入队
	return true;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
