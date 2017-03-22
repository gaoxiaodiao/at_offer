/*
*������07:����ջʵ��һ������
*����:��С��
*����:2017-03-22
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
#include<stack>
#include<cassert>
template<typename T>
class Queue{
public:
	void Push(const T &e){
		s1.push(e);
	}
	void Pop(){
		if(s2.empty()){
			if(s1.empty()){
				//������û����ֵ
				assert(false);
			}else{
				//��s1�е����ݵ��뵽s2
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
		}
		s2.pop();
	}
	const T& Front(){
		if(s2.empty()){
			if(s1.empty()){
				//������û����ֵ
				assert(false);
			}else{
				//��s1�е����ݵ��뵽s2
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
		}
		return s2.top();
	}
private:
	std::stack<T> s1;
	std::stack<T> s2;
};

void TestQueue(){
	Queue<int> q;
	for(int i=0; i<5; ++i){
		q.Push(i);
	}
	for(int i=0; i<5; ++i){
		std::cout<<q.Front()<<std::endl;
		q.Pop();
	}
	q.Pop();	//����쳣���(����Ϊ��)
}