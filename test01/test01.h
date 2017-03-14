/*
*面试题1:赋值运算符函数
*作者:高小调
*日期:2017-3-14
*集成开发环境:Microsoft Visual Studio 2010 
*PS:原题目只要求写出赋值运算符重载函数,本人在此做个扩展,写一个简洁版的String类
*/
#pragma once
#include<cstring>
class String{
public:
	//构造函数
	String(const char *str=NULL )
		:_str(NULL){
			if(str!=NULL){
				_str = new char[std::strlen(str)+1];	//开辟空间(strlen求字符个数不计算\0,因此多开辟一个空间放\0)
				std::strcpy(_str,str);					//拷贝字符
			}else{
				_str = new char[1];  //多开一个空间方便统一用delete[]析构
				*_str = '\0';		 //默认为空串
			}
	}
	//拷贝构造
	String(const String &s)
		:_str(NULL){	//***此处必须初始化_str为空,否则临时对象析构时会delete[]随机值,程序崩溃
			String tmp(s._str);		//调用构造函数
			std::swap(tmp._str,_str);	//交换指针
	}
	//赋值运算符重载
	String &operator=(const String &s){
		if(s._str!=_str){	//判断是否自我赋值
			//赋值运算符重载的简洁写法
			String tmp(s);
			std::swap(_str,tmp._str);
		}
		return *this;
	}
	//析构函数
	~String(){
		delete[] _str;
	}
private:
	char *_str;
};

void TestString(){
	String s1("Hello");	//有参
	String s2(NULL);	//特殊
	String s3;			//无参
	s2 = s1;			//赋值运算符重载
	String s4(s2);		//拷贝构造
}