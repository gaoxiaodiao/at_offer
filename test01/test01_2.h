/*
*面试题1:赋值运算符函数
*作者:高小调
*日期:2017-3-15
*集成开发环境:Microsoft Visual Studio 2010 
*PS:温故而知新,再写第二道题之前,先复习昨天的题目
*/
#include<cstring>
class String{
public:
	//构造函数
	String(const char *str = NULL){
		if(str == NULL){
			_str = new char[1];
			*_str = '\0';
		}else{
			_str = new char[std::strlen(str)+1];
			std::strcpy(_str,str);
		}
	}
	//拷贝构造
	String(const String &s)
		:_str(NULL){
		String tmp(s._str);
		std::swap(_str,tmp._str);
	}
	//赋值运算符重载
	String& operator=(const String &s){
		if(s._str!=_str){
			String tmp(s);
			std::swap(tmp._str,_str);
		}
		return *this;
	}
	//析构函数
	~String(){
		delete []_str;
	}
private:
	char *_str;
};
void TestString(){
	String s1("Hello");
	String s2(NULL);
	String s3;
	s2 = s3 = s1;

}