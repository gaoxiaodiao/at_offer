/*
*������05:��β��ͷ��ӡ����
*����:��С��
*����:2017-03-17
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cassert>
//����ڵ㶨��
template<typename T = int>
struct LinkNode{
	T _value;
	LinkNode *_next;
	//���캯��
	LinkNode(const T& value)
		:_value(value)
		,_next(NULL){}
};
/*
*����˵��:����һ������0-9
*����˵��:ͷָ��Ķ���ָ��
*����ֵ:�޷���ֵ
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
*����˵��:����һ������
*����˵��:ͷָ��Ķ���ָ��
*����ֵ:�޷���ֵ
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
*��������:��ӡ����
*��������:�����ͷָ��
*����ֵ:��
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
*��������:��β��ͷ��ӡ����
*��������:�����ͷָ��
*����ֵ:��
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
	CreateLinkList(&head);		//����0-9������
	PrintLinkList(head);		//�����ӡ
	ReversePrint(head);			//�����ӡ
	DestoryLinkList(&head);		//��������
}