/*
*������1:��ֵ���������
*����:��С��
*����:2017-3-15
*���ɿ�������:Microsoft Visual Studio 2010 
*PS:�¹ʶ�֪��,��д�ڶ�����֮ǰ,�ȸ�ϰ�������Ŀ
*/
#include<cstring>
class String{
public:
	//���캯��
	String(const char *str = NULL){
		if(str == NULL){
			_str = new char[1];
			*_str = '\0';
		}else{
			_str = new char[std::strlen(str)+1];
			std::strcpy(_str,str);
		}
	}
	//��������
	String(const String &s)
		:_str(NULL){
		String tmp(s._str);
		std::swap(_str,tmp._str);
	}
	//��ֵ���������
	String& operator=(const String &s){
		if(s._str!=_str){
			String tmp(s);
			std::swap(tmp._str,_str);
		}
		return *this;
	}
	//��������
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