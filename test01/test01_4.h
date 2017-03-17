/*
*������01:��ֵ���������
*����:��С��
*����:2017-03-17
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cstring>
class String{
public:
	//���캯��
	String(const char *str = NULL){
		if(str!=NULL){
			_str = new char[strlen(str)+1];
			strcpy(_str,str);
		}else{
			_str = new char[1];
			*_str = '\0';
		}
	}
	//��������
	String(const String& s)
		:_str(NULL){
			String tmp(s._str);
			std::swap(tmp._str,_str);
	}
	//��ֵ���������
	String &operator=(const String &s){
		if(_str != s._str){
			String tmp(s);
			std::swap(tmp._str,_str);
		}
		return *this;
	}
	//��������
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