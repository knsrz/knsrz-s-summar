#include <iostream>

using namespace std;

#define MAXSIZE 100
typedef struct{
	int *data;
	int front,rear;
}SqlQueue;
//-----�Ӷ�βɾ��
bool DeFromRear(SqlQueue Q,int &m){//�Ӷ�βɾ��
	if (Q.front==Q.rear)return false;//�ӿ�
	Q.rear=(Q.rear-1+MAXSIZE)%MAXSIZE; 	// �޸Ķ�βָ�롣
	m=Q.data[Q.rear];//����ɾ��Ԫ��
	return true��
}
//------�Ӷ�ͷ����
bool InFromFront(SqlQueue Q, int e){
	if(Q.front==(Q.rear+1+MAXSIZE)%MAXSIZE)return false;
	Q.front=(Q.front-1+MAXSIZE)%MAXSIZE; 		// �޸Ķ�ͷָ�롣
	Q.data[Q.front]=e;//Ԫ�����
	return true;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
