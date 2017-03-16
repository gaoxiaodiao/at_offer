/*
*面试题01:赋值运算符重载
*作者:高小调
*日期:2017-03-16
*集成开发环境:Microsoft Visual Studio 2010 
*/
#include<cstring>
class String{
public:
	//构造函数
	String(const char* str=NULL){
		if(str!=NULL){
			_str = new char[std::strlen(str)+1];
			std::strcpy(_str,str);
		}else{
			_str = new char[1];
			*_str = '\0';
		}
	}
	//拷贝构造
	String(const String &s)
		:_str(NULL){
			String tmp(s._str);
			std::swap(tmp._str,_str);
	}
	//赋值运算符重载
	String &operator=(const String &s){
		if(_str!=s._str){
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
	String s1("123456789");
	String s2(NULL);
	String s3;
	String s4(s1);
	s3 = s2 = s1;
}