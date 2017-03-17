/*
*������04:�滻�ո�
*����:��С��
*����:2017-03-16
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#include<cassert>
char* ReplaceBlank(char *str){
	assert(str);
	int count = 0;
	char *frontptr = str;
	//����ո���Ŀ
	while(*frontptr!='\0'){
		if(*frontptr == ' '){
			++count;
		}
		++frontptr;
	}
	//βָ�����
	char *blackptr = frontptr+count*(3-1);	//%20��3���ַ�,�ټ�ȥԭ�еĿո�
	//��ʼ����
	while(blackptr>frontptr){
		if(*frontptr==' '){
			//�����ո�,��%20����
			*blackptr-- = '0';
			*blackptr-- = '2';
			*blackptr-- = '%';
			--frontptr;		//�ⲽ����ʡ��!
		}else{
			//�ǿո����,ֱ�Ӹ���
			*blackptr-- = *frontptr--;
		}
	}
	return str;
}

void TestReplaceBlank(){
	char str1[30] = "we are happy";		//�ո����м�
	char str2[30] = " we are happy";	//�ո��ڿ�ʼ
	char str3[30] = "we are happy ";	//�ո������
	char str4[30] = "             ";	//�����ո�
	char str5[30] = "Hello";			//û�пո�
	char *str6 = NULL;					//��ָ��

	std::cout<<ReplaceBlank(str1)<<std::endl;
	std::cout<<ReplaceBlank(str2)<<std::endl;
	std::cout<<ReplaceBlank(str3)<<std::endl;
	std::cout<<ReplaceBlank(str4)<<std::endl;
	std::cout<<ReplaceBlank(str5)<<std::endl;
	std::cout<<ReplaceBlank(str6)<<std::endl;	//�������Դ���


}