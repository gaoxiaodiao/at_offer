/*
*面试题06:重建二叉树
*作者:高小调
*日期:2017-03-18
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cassert>
//树节点
struct TreeNode{
	int _value;
	TreeNode *_left;
	TreeNode *_right;
	TreeNode(int value)
		:_value(value)
		,_left(NULL)
		,_right(NULL){}
};

//递归构建树
TreeNode *ConstructCore(int *startPreOrder,int *endPreOrder,int *startInOrder,int *endInOrder){
	//前序第一个元素为根节点
	TreeNode *root = new TreeNode(startPreOrder[0]);
	if(startPreOrder==endPreOrder){
		if(startInOrder == endInOrder && 
			*startPreOrder == *startInOrder){
			return root;
		}else{
			//数据错误
			assert(false);
		}
	}

	//中序找根节点的值
	int *rootInOrder = startInOrder;
	while(rootInOrder <= endInOrder && *rootInOrder!= *startPreOrder){
		++rootInOrder;
	}
	if(rootInOrder == endInOrder && *rootInOrder!= *startPreOrder){
		//数据错误
		assert(false);
	}
	int leftLength = rootInOrder - startInOrder;
	int *leftPreOrderEnd = startPreOrder + leftLength;
	if(leftLength > 0){
		//构建左子树
		root->_left = ConstructCore(startPreOrder+1,leftPreOrderEnd,
			startInOrder,rootInOrder-1);
	}
	if(leftLength<endPreOrder-startPreOrder){
		//构建右子树
		root->_right = ConstructCore(leftPreOrderEnd+1,endPreOrder,
			rootInOrder+1,endInOrder);
	}
	return root;
}

TreeNode *Construct(int *preorder,int *inorder,int sz){
	assert(preorder!=NULL&&inorder!=NULL&&sz>0);
	return ConstructCore(preorder,preorder+sz-1,inorder,inorder+sz-1);
}

//前序遍历
void PreOrder(TreeNode *root){
	if(root==NULL){
		return ;
	}
	cout<<root->_value<<" ";
	PreOrder(root->_left);
	PreOrder(root->_right);
}
//中序遍历
void InOrder(TreeNode *root){
	if(root==NULL){
		return ;
	}
	InOrder(root->_left);
	cout<<root->_value<<" ";
	InOrder(root->_right);
}
//后序遍历
void PostOrder(TreeNode *root){
	if(root==NULL){
		return ;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	cout<<root->_value<<" ";
}
void TestConstructTree(){
	int preOrder[] = {1,2,4,7,3,5,6,8};
	int inOrder[] = {4,7,2,1,5,3,8,6};
	TreeNode * root = Construct(preOrder,inOrder,sizeof(preOrder)/sizeof(preOrder[0]));
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;
}