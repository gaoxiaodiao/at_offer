/*
*������1:��ֵ���������
*����:��С��
*����:2017-3-14
*���ɿ�������:Microsoft Visual Studio 2010 
*PS:ԭ��ĿֻҪ��д����ֵ��������غ���,�����ڴ�������չ,дһ�������String��
*/
#pragma once
#include<cstring>
class String{
public:
	//���캯��
	String(const char *str=NULL )
		:_str(NULL){
			if(str!=NULL){
				_str = new char[std::strlen(str)+1];	//���ٿռ�(strlen���ַ�����������\0,��˶࿪��һ���ռ��\0)
				std::strcpy(_str,str);					//�����ַ�
			}else{
				_str = new char[1];  //�࿪һ���ռ䷽��ͳһ��delete[]����
				*_str = '\0';		 //Ĭ��Ϊ�մ�
			}
	}
	//��������
	String(const String &s)
		:_str(NULL){	//***�˴������ʼ��_strΪ��,������ʱ��������ʱ��delete[]���ֵ,�������
			String tmp(s._str);		//���ù��캯��
			std::swap(tmp._str,_str);	//����ָ��
	}
	//��ֵ���������
	String &operator=(const String &s){
		if(s._str!=_str){	//�ж��Ƿ����Ҹ�ֵ
			//��ֵ��������صļ��д��
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
	String s1("Hello");	//�в�
	String s2(NULL);	//����
	String s3;			//�޲�
	s2 = s1;			//��ֵ���������
	String s4(s2);		//��������
}