/*
*������09:쳲���������
*����:��С��
*����:2017-03-25
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
//�����n��쳲�������
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
//����
void TestFib(){
	for(int i=1; i<10; ++i){
		std::cout<<Fib(i)<<" ";
	}
	std::cout<<std::endl;
}