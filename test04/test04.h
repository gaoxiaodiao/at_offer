/*
*面试题04:替换空格
*作者:高小调
*日期:2017-03-16
*集成开发环境:Microsoft Visual Studio 2010 
*/
#include<cassert>
char* ReplaceBlank(char *str){
	assert(str);
	int count = 0;
	char *frontptr = str;
	//计算空格数目
	while(*frontptr!='\0'){
		if(*frontptr == ' '){
			++count;
		}
		++frontptr;
	}
	//尾指针计算
	char *blackptr = frontptr+count*(3-1);	//%20是3个字符,再减去原有的空格
	//开始复制
	while(blackptr>frontptr){
		if(*frontptr==' '){
			//遇到空格,用%20代替
			*blackptr-- = '0';
			*blackptr-- = '2';
			*blackptr-- = '%';
			--frontptr;		//这步不能省略!
		}else{
			//非空格情况,直接复制
			*blackptr-- = *frontptr--;
		}
	}
	return str;
}

void TestReplaceBlank(){
	char str1[30] = "we are happy";		//空格在中间
	char str2[30] = " we are happy";	//空格在开始
	char str3[30] = "we are happy ";	//空格在最后
	char str4[30] = "             ";	//连续空格
	char str5[30] = "Hello";			//没有空格
	char *str6 = NULL;					//空指针

	std::cout<<ReplaceBlank(str1)<<std::endl;
	std::cout<<ReplaceBlank(str2)<<std::endl;
	std::cout<<ReplaceBlank(str3)<<std::endl;
	std::cout<<ReplaceBlank(str4)<<std::endl;
	std::cout<<ReplaceBlank(str5)<<std::endl;
	std::cout<<ReplaceBlank(str6)<<std::endl;	//引发断言错误


}