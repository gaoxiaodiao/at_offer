/*
*面试题09:斐波那契数列
*作者:高小调
*日期:2017-03-22
*集成开发环境:Microsoft Visual Studio 2010 
*/
//0 1 1 2 3 5 8
long long Fib(long long n){
	if(n<=0){
		return 0;
	}
	if(n==1 || n==2){
		return 1;
	}
	long long x1 = 1;
	long long x2 = 1;
	long long ret = 0;
	for(long long i=3; i<=n; ++i){
		ret = x1 + x2;
		x1 = x2;
		x2 = ret;
	}
	return ret;
}

void TestFib(){
	for(long long i=1; i<=10; ++i){
		std::cout<<Fib(i)<<" ";
	}
	std::cout<<endl;
}