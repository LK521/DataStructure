#include"../common.h"

struct Node{
	int    data;
	Node * next;
};

class LinkList{
	private:
		int    length;
		Node * head;
	public:
		LinkList();//���캯�� 
		int GetLength(void);//��ȡ������
		Status ListIsEmpty(void);//�ж�����Ϊ�� 
		Status ListInsertNode(Node *node,int dest);//����ڵ� 
		Status ListDeleteNode(int dest);//ɾ���ڵ� 
		Status CreateList1(int n);//ͷ�巨�������� 
		Status CreateList2(int n);//β�巨��������
		Node* GetNode(int dest);//��ȡָ��λ�õ�һ���ڵ� 
		LinkList CopyList(LinkList deslist,LinkList srclist);//��Դ����copy��Ŀ������ 
		LinkList JoinList(LinkList list);//����������ֱ��ƴ��	
};


