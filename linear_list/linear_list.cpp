/*
柳坤 2019.5.6 
带头节点的单链表的实现 
NOTE： 
一个带头节点的单链表默认长度是1（包含头结点）； 
头节点只有next没有data 。 
节点的编号为1,2,3,4,... 
*/
#include<iostream>
#include"linear_list.h"
#include"../common.h"

using namespace std;

LinkList::LinkList(){
	length = 1;	
	head = new Node;
	head->next = NULL;
	head->data = 0;
};
	
int LinkList::GetLength(void){
	return length;
};

Status LinkList::ListIsEmpty(void){
	if (length == 0)
		return Yes;
	else
		return No;
}

Status LinkList::CreateList1(int n){
	int i = 0;
	Node * p;
	Node * temp;
	p = head;
	
	if(n <= 1)
		return Error;
    else{
		for(i=0;i<n-1;i++){
			temp = new Node;
			temp->data = i;
			p->next = temp;
			p = p->next;
		} 
	}
	length = n;
	return OK;	
}

Status LinkList::CreateList2(int n){
	int i = 0;
	Node * temp;
	
	if(n <= 1)
		return Error;
    else{
		for(i=0;i<n-1;i++){
			temp = new Node;
			temp->data = i;		
			temp->next = head->next; 
			head->next = temp;	
		} 
	}
	length = n;
	return OK;
}

Node* LinkList::GetNode(int dest){
	Node *p;
	int i = 0;
	p = head;
	
	if(dest < 1 || dest > length)
		return NULL; 
	else
	{
		for(i=0;i<length-1;i++){
			p = p->next;
		}
		printf("%d\n",p->data);
		return p;
	}	
	
};
	
Status LinkList::ListInsertNode(Node *node,int dest){
	int i = 0;
	Node *temp;
	Node *p;
	p = head;
	if (dest<=length+1)
	{
		for(i=0;i<dest-2;i++){
			p = p->next;
		}
		temp = p->next;
		p->next = node;
		p->next->next = temp;
		length = length + 1;
		return OK;
	}
		
	else
		return Error;
};

Status LinkList::ListDeleteNode(int dest){
	Node *p;
	Node * temp;
	int i = 0;
	if(dest>=length)
		return Error;
	p = head;
	for(i=0;i<dest-1;i++)
	{
		p = p -> next;
	}
	temp = p->next;
	p->next = temp->next;
	temp->next = NULL;
}

Status LinkList::CopyList(LinkList deslist,LinkList srclist){
	int len = srclist.GetLength();
	Node * p = srclist.head;
	Node * t = deslist.head;
	if(len<=1){
		return Error;
	}
	while(len-1){
		p = p->next;
		Node * temp = new Node;
		temp->next = p->next;	
		temp->data = p->data;
		
		t->next = temp;
	    t = t->next;	
	}
	deslist.length = srclist.length;
	return OK;
} 

LinkList LinkList::JoinList(LinkList list01,LinkList list02){
	LinkList list_temp01;
	LinkList list_temp02;
	Node * p = NULL;
	list_temp01.CopyList(list_temp01,list01);
	list_temp02.CopyList(list_temp02,list01);
	p = list_temp01.GetNode((list_temp01.length) - 1);
	p->next = list_temp02.head->next;
	return list_temp02;
} 

void test_GetNode(){
	Node * node1 = new Node;
	Node * node2 = new Node;
	Node * node3 = new Node;
	LinkList list;
	
	node1->data = 1;
	node1->next = NULL;
	node2->data = 2;
	node2->next = NULL;
	node3->data = 3;
	node3->next = NULL;
	
	printf("1 data:%d\n",list.GetNode(1)->data);
	printf("insert:%d\n",list.ListInsertNode(node1,2));
	printf("length=%d\n",list.GetLength());
	printf("2 data:%d\n",list.GetNode(2)->data);
	printf("insert:%d\n",list.ListInsertNode(node1,3));
	printf("length=%d\n",list.GetLength());
	printf("3 data:%d\n",list.GetNode(3)->data);
} 

void test_CreateList1(){
    int i = 0;
	LinkList list1;
	
	list1.CreateList1(10);
	
	printf("length=%d\n",list1.GetLength());
	
	for(i=0;i<list1.GetLength();i++){
		printf("data:%d\n",list1.GetNode(i)->data);
	}	
}

void test_CreateList2(){
    int i = 0;
	LinkList list1;
	
	list1.CreateList2(10);
	
	printf("length=%d\n",list1.GetLength());
	printf("1 data:%d\n",list1.GetNode(2)->data);	
}

int main(void){
	test_GetNode();
	//test_CreateList1();
	//test_CreateList2();
	return 0;
}
