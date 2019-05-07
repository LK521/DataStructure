/*
柳坤 2019.5.6 
带头节点的单链表的实现 
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
	Node * temp;
	
	if(n <= 0)
		return Error;
    else{
		for(i=0;i<=n;i++){
			temp = head;
			head = new Node;
			head->next = temp;
			head->data = i;
		} 
	}
	length = n;
	return OK;	
}

Status LinkList::CreateList2(int n){
	int i = 0;
	Node * temp;
	Node * p;
	
	if(n <= 0)
		return Error;
    else{
    	p = head;
		for(i=0;i<=n;i++){
			temp = new Node;
			temp->data = i;
			p->next = temp;
			p = temp;		
		} 
	}
	length = n;
	return OK;
}

Node* LinkList::GetNode(int dest){
	Node *temp;
	int i = 0;
	temp = head;
	
	if (dest>=length-1)
		printf("Error!\n");
		
	for(i=0;i<dest-1;i++){
		temp = temp->next;
	}
	return temp;
};
	
Status LinkList::ListInsertNode(Node *node,int dest){
	int i = 0;
	Node *temp;
	Node *p;
	p = head;
	if (dest<=length-1)
	{
		for(i=0;i<dest-2;i++){
			p = p->next;
		}
		temp = p->next;
		p->next = node;
		p->next->next = temp;
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

LinkList LinkList::CopyList(LinkList deslist,LinkList srclist){
	
} 

LinkList LinkList::JoinList(LinkList list){
	
} 


int main(void){
	LinkList list1;
	int i = list1.CreateList1(10);
	printf("status:%d\n",i);
	return 0;
}
