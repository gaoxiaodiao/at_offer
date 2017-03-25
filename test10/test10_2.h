/*
*面试题09:斐波那契数列
*作者:高小调
*日期:2017-03-25
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
//计算第n个斐波那契数
long long Fib(int n){
	if(n<=0){
		return 0;
	}
	if(n<=2){
		return 1;
	}
	long long x1 = 1;
	long long x2 = 1;
	long long ret = 0;
	for(int i=2; i<n; ++i){
		ret = x1+x2;
		x1 = x2;
		x2 = ret;
	}
	return ret;
}
//测试
void TestFib(){
	for(int i=1; i<10; ++i){
		std::cout<<Fib(i)<<" ";
	}
	std::cout<<std::endl;
}