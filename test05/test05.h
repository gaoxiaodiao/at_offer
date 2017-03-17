/*
*面试题05:从尾到头打印链表
*作者:高小调
*日期:2017-03-17
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cassert>
//链表节点定义
template<typename T = int>
struct LinkNode{
	T _value;
	LinkNode *_next;
	//构造函数
	LinkNode(const T& value)
		:_value(value)
		,_next(NULL){}
};
/*
*函数说明:创建一个链表0-9
*参数说明:头指针的二级指针
*返回值:无返回值
*/
void CreateLinkList(LinkNode<int> **head){
	assert(head);
	*head = new LinkNode<int>(0);
	LinkNode<int> *cur = *head;
	for(int i=1; i<10; ++i){
		cur->_next = new LinkNode<int>(i);
		cur = cur->_next;
	}
}
/*
*函数说明:销毁一个链表
*参数说明:头指针的二级指针
*返回值:无返回值
*/
void DestoryLinkList(LinkNode<int> **head){
	assert(head);
	if(*head!=NULL){
		LinkNode<int> *cur = *head;
		while(cur!=NULL){
			LinkNode<int> *del = cur;
			cur = cur->_next;
			delete del;
			del = NULL;
		}
		*head = NULL;
	}
}
/*
*函数名称:打印链表
*函数参数:链表的头指针
*返回值:无
*/
void PrintLinkList(LinkNode<int> *head){
	LinkNode<int>* cur = head;
	while(cur!=NULL){
		std::cout<<cur->_value<<" ";
		cur = cur->_next;
	}
	std::cout<<std::endl;
}

/*
*函数名称:从尾到头打印链表
*函数参数:链表的头指针
*返回值:无
*/
void ReversePrint(LinkNode<int> *head){
	if(head==NULL){
		return ;
	}
	ReversePrint(head->_next);
	std::cout<<head->_value<<" ";
}

void TestReversePrint(){
	LinkNode<int> *head = NULL;
	CreateLinkList(&head);		//创建0-9的链表
	PrintLinkList(head);		//正序打印
	ReversePrint(head);			//逆序打印
	DestoryLinkList(&head);		//销毁链表
}