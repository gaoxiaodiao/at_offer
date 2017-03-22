/*
*面试题07:两个栈实现一个队列
*作者:高小调
*日期:2017-03-22
*集成开发环境:Microsoft Visual Studio 2010 
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
				//队列中没有数值
				assert(false);
			}else{
				//把s1中的数据倒入到s2
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
				//队列中没有数值
				assert(false);
			}else{
				//把s1中的数据倒入到s2
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
	q.Pop();	//检测异常情况(队列为空)
}