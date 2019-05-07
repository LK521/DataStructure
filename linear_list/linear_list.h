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
		LinkList();//构造函数 
		int GetLength(void);//获取链表长度
		Status ListIsEmpty(void);//判断链表为空 
		Status ListInsertNode(Node *node,int dest);//插入节点 
		Status ListDeleteNode(int dest);//删除节点 
		Status CreateList1(int n);//头插法创建链表 
		Status CreateList2(int n);//尾插法创建链表
		Node* GetNode(int dest);//获取指定位置的一个节点 
		LinkList CopyList(LinkList deslist,LinkList srclist);//将源链表copy到目的链表 
		LinkList JoinList(LinkList list);//将两个链表直接拼接	
};


