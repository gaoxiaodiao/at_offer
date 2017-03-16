/*
*������01:��ֵ���������
*����:��С��
*����:2017-03-16
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#include<cstring>
class String{
public:
	//���캯��
	String(const char* str=NULL){
		if(str!=NULL){
			_str = new char[std::strlen(str)+1];
			std::strcpy(_str,str);
		}else{
			_str = new char[1];
			*_str = '\0';
		}
	}
	//��������
	String(const String &s)
		:_str(NULL){
			String tmp(s._str);
			std::swap(tmp._str,_str);
	}
	//��ֵ���������
	String &operator=(const String &s){
		if(_str!=s._str){
			String tmp(s);
			std::swap(_str,tmp._str);
		}
		return *this;
	}
	//��������
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