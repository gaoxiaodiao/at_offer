/*
*������10:��������1�ĸ���
*����:��С��
*����:2017-03-23
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
//�汾1 ͨ����ѧ����(�̳���)��ȡ������1�ĸ���
//����˵��:ͨ��unsigned intʹ���븺��Ҳ����������
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

//�汾2 ͨ����λ��ȡ��������1�ĸ���
int CountBitNumV2(unsigned int num){
	int count = 0;
	for(int i=0; i<32; ++i){
		//����iλ,ȡ���һλ
		if((num>>i)&1 == 1){
			++count;
		}
	}
	return count;
}

//�汾3: n&(n-1)���������,��count��1,ѭ��count��
int CountBitNumV3(unsigned int num){
	int count = 0;
	while(num){
		num &= num-1;
		++count;
	}
	return count;
}

//���Դ���
typedef int (*pFun)(unsigned int);
void _TestCountBitNum(pFun __CountBitNum){
	int arr[] = {0,1,2,3,4,5,6,7,8,9,-1};
	std::cout<<"         ����:";
	for(int i=0; i<sizeof(arr)/sizeof(*arr); ++i){
		std::cout<<arr[i]<<" "; 
	}
	std::cout<<std::endl;
	std::cout<<"������1�ĸ���:";
	for(int i=0; i<sizeof(arr)/sizeof(*arr); ++i){
		std::cout<<__CountBitNum(arr[i])<<" ";
	}
	std::cout<<endl;
}
void TestCountBitNum(){
	std::cout<<"v1�汾����:"<<std::endl;
	_TestCountBitNum(CountBitNumV1);
	std::cout<<endl;
	std::cout<<"v2�汾����:"<<std::endl;
	_TestCountBitNum(CountBitNumV2);
	std::cout<<endl;
	std::cout<<"v3�汾����:"<<std::endl;
	_TestCountBitNum(CountBitNumV2);
}


