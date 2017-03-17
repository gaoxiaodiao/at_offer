/*
*面试题04:空格替换
*作者:高小调
*日期:2017-03-17
*集成开发环境:Microsoft Visual Studio 2010 
*/
#include<cassert>
/*
*函数功能:将字符串中空格替换为%20(需要预留足够的空间)
*函数参数:被替换的字符串
*返回值:源字符串首地址
*/
char *ReplaceBlank(char* str){
	assert(str);
	int count = 0;
	char *frontPtr = str;
	//1.计算空格数量
	while(*frontPtr){
		if(*frontPtr==' '){
			++count;
		}
		++frontPtr;
	}
	//2.计算尾指针
	char *backPtr = frontPtr + count*2;
	//3.开始复制
	while(backPtr>frontPtr){
		if(*frontPtr==' '){
			//空格情况
			*backPtr-- = '0';
			*backPtr-- = '2';
			*backPtr-- = '%';
			--frontPtr;
		}else{
			//非空格
			*backPtr-- = *frontPtr--;
		}
	}
	return str;
}

//测试函数
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