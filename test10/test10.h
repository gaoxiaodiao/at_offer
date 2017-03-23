/*
*面试题10:二进制中1的个数
*作者:高小调
*日期:2017-03-23
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
//版本1 通过数学计算(短除法)获取二进制1的个数
//参数说明:通过unsigned int使传入负数也能正常工作
int CountBitNumV1(unsigned int num){
	int count = 0;
	while(num){
		if(num%2==1){
			++count;
		}
		num /= 2;
	}
	return count;
}

//版本2 通过移位获取二进制中1的个数
int CountBitNumV2(unsigned int num){
	int count = 0;
	for(int i=0; i<32; ++i){
		//右移i位,取最后一位
		if((num>>i)&1 == 1){
			++count;
		}
	}
	return count;
}

//版本3: n&(n-1)的灵活运用,有count个1,循环count次
int CountBitNumV3(unsigned int num){
	int count = 0;
	while(num){
		num &= num-1;
		++count;
	}
	return count;
}

//测试代码
typedef int (*pFun)(unsigned int);
void _TestCountBitNum(pFun __CountBitNum){
	int arr[] = {0,1,2,3,4,5,6,7,8,9,-1};
	std::cout<<"         数字:";
	for(int i=0; i<sizeof(arr)/sizeof(*arr); ++i){
		std::cout<<arr[i]<<" "; 
	}
	std::cout<<std::endl;
	std::cout<<"二进制1的个数:";
	for(int i=0; i<sizeof(arr)/sizeof(*arr); ++i){
		std::cout<<__CountBitNum(arr[i])<<" ";
	}
	std::cout<<endl;
}
void TestCountBitNum(){
	std::cout<<"v1版本测试:"<<std::endl;
	_TestCountBitNum(CountBitNumV1);
	std::cout<<endl;
	std::cout<<"v2版本测试:"<<std::endl;
	_TestCountBitNum(CountBitNumV2);
	std::cout<<endl;
	std::cout<<"v3版本测试:"<<std::endl;
	_TestCountBitNum(CountBitNumV2);
}


