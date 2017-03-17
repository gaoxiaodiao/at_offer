/*
*面试题01:赋值运算符函数
*作者:高小调
*日期:2017-03-17
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cstring>
class String{
public:
	//构造函数
	String(const char *str = NULL){
		if(str!=NULL){
			_str = new char[strlen(str)+1];
			strcpy(_str,str);
		}else{
			_str = new char[1];
			*_str = '\0';
		}
	}
	//拷贝构造
	String(const String& s)
		:_str(NULL){
			String tmp(s._str);
			std::swap(tmp._str,_str);
	}
	//赋值运算符重载
	String &operator=(const String &s){
		if(_str != s._str){
			String tmp(s);
			std::swap(tmp._str,_str);
		}
		return *this;
	}
	//析构函数
	~String(){
		if(_str!=NULL){
			delete[] _str;
			_str = NULL;
		}
	}
private:
	char *_str;
};

void TestString(){
	String s1("1357924680");
	String s2;
	String s3(NULL);
	String s4(s1);
	s3 = s2 = s1;

}