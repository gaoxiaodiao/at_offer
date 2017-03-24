/*
*������11:��ֵ�������η�
*����:��С��
*����:2017-03-24
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
bool g_invalid = false;

//double���������ж��Ƿ����
bool doubleEqual(double num1,double num2){
	if(num1-num2 > -0.000000001 &&
		num1-num2 < 0.000000001){
		return true;
	}
	return false;
}
//��ĳ�����������η�
double Power(double base,int exponent){
	g_invalid = false;
	if(doubleEqual(base,0.0) && exponent<0){
		//�쳣		
		g_invalid = true;
		return 0.0;
	}

	//��ȡ�η���
	unsigned int absExponent = (unsigned int)exponent;
	if(exponent<0){
		absExponent = (unsigned int)(-exponent);
	}
	
	//����η�
	double ret = 1.0;
	for(int i=0; i<absExponent; ++i){
		ret *= base;
	}

	//�жϴη�Ϊ��
	if(exponent<0){
		ret = 1.0/ret; 
	}

	return ret;
}
void TestPower(){
	std::cout<<Power(2,5)<<std::endl;
	std::cout<<Power(2,0)<<std::endl;
	std::cout<<Power(2,-2)<<std::endl;
	std::cout<<std::endl;

	std::cout<<Power(0,5)<<std::endl;
	std::cout<<Power(0,0)<<std::endl;
	std::cout<<Power(0,-2)<<std::endl;
	std::cout<<std::endl;

	std::cout<<Power(-2,5)<<std::endl;
	std::cout<<Power(-2,0)<<std::endl;
	std::cout<<Power(-2,-3)<<std::endl;
	std::cout<<std::endl;
}