/*
*面试题07:两个栈实现一个队列
*作者:高小调
*日期:2017-03-20
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
#include<stack>
template<typename T>
class Queue{
public:
	void Push(const T &e){
		s1.push(e);
	}
	T & Front(){
		if(s2.empty()){
			assert(s1.empty());
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}
	const T &Front()const{
		if(s2.empty()){
			assert(s1.empty());
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}
	void Pop(){
		if(s2.empty()){
			assert(s1.empty());
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
	}
private:
	std::stack<T> s1;	//入队
	std::stack<T> s2;	//出队
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
}