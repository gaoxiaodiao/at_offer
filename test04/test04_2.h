/*
*������04:�ո��滻
*����:��С��
*����:2017-03-17
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#include<cassert>
/*
*��������:���ַ����пո��滻Ϊ%20(��ҪԤ���㹻�Ŀռ�)
*��������:���滻���ַ���
*����ֵ:Դ�ַ����׵�ַ
*/
char *ReplaceBlank(char* str){
	assert(str);
	int count = 0;
	char *frontPtr = str;
	//1.����ո�����
	while(*frontPtr){
		if(*frontPtr==' '){
			++count;
		}
		++frontPtr;
	}
	//2.����βָ��
	char *backPtr = frontPtr + count*2;
	//3.��ʼ����
	while(backPtr>frontPtr){
		if(*frontPtr==' '){
			//�ո����
			*backPtr-- = '0';
			*backPtr-- = '2';
			*backPtr-- = '%';
			--frontPtr;
		}else{
			//�ǿո�
			*backPtr-- = *frontPtr--;
		}
	}
	return str;
}

//���Ժ���
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