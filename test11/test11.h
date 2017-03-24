/*
*面试题11:数值的整数次方
*作者:高小调
*日期:2017-03-24
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
bool g_invalid = false;

//double类型数据判断是否相等
bool doubleEqual(double num1,double num2){
	if(num1-num2 > -0.000000001 &&
		num1-num2 < 0.000000001){
		return true;
	}
	return false;
}
//求某个数的整数次方
double Power(double base,int exponent){
	g_invalid = false;
	if(doubleEqual(base,0.0) && exponent<0){
		//异常		
		g_invalid = true;
		return 0.0;
	}

	//获取次方数
	unsigned int absExponent = (unsigned int)exponent;
	if(exponent<0){
		absExponent = (unsigned int)(-exponent);
	}
	
	//计算次方
	double ret = 1.0;
	for(int i=0; i<absExponent; ++i){
		ret *= base;
	}

	//判断次方为负
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