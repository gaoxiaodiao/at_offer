/*
*������06:�ع�������
*����:��С��
*����:2017-03-20
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cassert>
#include<stack>
//����㶨��
typedef struct TreeNode{
	int _value;
	TreeNode *_left;
	TreeNode *_right;
	//���캯��
	TreeNode(int value)
		:_value(value)
		,_left(NULL)
		,_right(NULL){}
}Node;

Node *ConstructTree(int *startPreOrder,int*endPreOrder,
	int*startInOrder,int *endInOrder){
	//���ڵ�
	Node *root = new Node(*startPreOrder);

	//Ҷ�ӽڵ�
	if(startPreOrder == endPreOrder){
		//ǰ�����ֻ��һ���ڵ�
		if(startInOrder==endInOrder && *startPreOrder==*endPreOrder){
			//�������ֻ��һ���ڵ�
			return root;
		}else{
			//��������
			assert(false);
		}
	}

	//����������Ҹ��ڵ�
	int *rootInOrder = startInOrder;
	while(rootInOrder <= endInOrder && *rootInOrder!=*startPreOrder){
		++rootInOrder;
	}
	if(rootInOrder==endInOrder &&*rootInOrder!=*startPreOrder){
		//��������
		assert(false);
	}

	int leftLength = rootInOrder - startInOrder;
	int *leftPreOrderEnd = startPreOrder + leftLength;
	if(leftLength > 0){
		//����������
		root->_left = ConstructTree(startPreOrder+1,leftPreOrderEnd,startInOrder,rootInOrder-1);
	}
	if(leftLength<endPreOrder - startPreOrder){
		//����������
		root->_right = ConstructTree(leftPreOrderEnd+1,endPreOrder,rootInOrder+1,endInOrder);
	}
	return root;
}
//����������
Node* Construct(int *preOrder,int *inOrder,size_t sz){
	assert(preOrder&&inOrder&&sz>0);
	return ConstructTree(preOrder,preOrder+sz-1,
		inOrder,inOrder+sz-1);
}
//ǰ�����
void PreOrderNonR(Node *root){
	assert(root);
	std::stack<Node*> s;
	Node *cur = root;
	while(!s.empty() || cur!=NULL){
		while(cur!=NULL){
			s.push(cur);
			std::cout<<cur->_value<<" ";
			cur = cur->_left;
		}

		Node *top = s.top();
		s.pop();

		cur = top->_right;
	}
	std::cout<<std::endl;
}
//�������
void InOrderNonR(Node *root){
	Node *cur = root;
	std::stack<Node*> s;
	while(!s.empty() ||cur!=NULL){
		while(cur!=NULL){
			s.push(cur);
			cur = cur->_left;
		}

		Node *top = s.top();
		s.pop();
		std::cout<<top->_value<<" ";

		cur = top->_right;
	}
	std::cout<<std::endl;
}
//��������ǵݹ�
void PostOrderNonR(Node* root){
	Node *cur = root;
	Node *prev = NULL;
	std::stack<Node*> s;
	while(!s.empty() || cur!=NULL){
		while(cur!=NULL){
			s.push(cur);
			cur = cur->_left;
		}

		Node *top = s.top();
		if(top->_right==NULL || top->_right==prev){
			prev = top;
			std::cout<<top->_value<<" ";
			s.pop();
		}else{
			cur =top->_right;
		}

	}
	std::cout<<std::endl;
}
//��������ݹ�ʵ��(��֤�ǵݹ�)
void PostOrder(Node *root){
	if(root==NULL){
		return ;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	std::cout<<root->_value<<" ";
}
void TestConstructTree(){
	int preOrder[]={1,2,4,7,3,5,6,8};
	int inOrder[]={4,7,2,1,5,3,8,6};
	Node *root = Construct(preOrder,inOrder,sizeof(preOrder)/sizeof(*preOrder));
	PreOrderNonR(root);
	InOrderNonR(root);
	PostOrderNonR(root);
	PostOrder(root);
	std::cout<<std::endl;
}