/*
*面试题3:二维数组的查找
*作者:高小调
*日期:2017-03-15
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cassert>
/*
1  2  8   
2  4  9   
4  7  10  
6  8  11 
二维数组与一维数组下标转换关系
00 0
10 3
20 6
30 9
归纳法得:
arr[row][col] = arr[row*col]
arr[i][j] = arr[i*col+j]
*/
bool YangMatrixFind(int *arr,size_t row,size_t col,int key){
	assert(arr);
	int x = 0;
	int y = col-1;
	while(x<row && y>=0){
		if(arr[x*col+y] > key){
			y--;	//key小于右上角,剔除一列
		}else if(arr[x*col+y] < key){
			x++;	//key大于右上角,剔除一行
		}else{
			return true;	//找到返回真
		}
	}
	return false;		//未找到
}
void TestYangMatirx(){
	int arr1[4][4]={{1,2,8,9}
					,{2,4,9,12}
					,{4,7,10,13}
					,{6,8,11,15}};
	int arr2[4][3] = {{1,2,8}
					,{2,4,9}
					,{4,7,10}
					,{6,8,11}};
	int arr3[3][4] = {{1,2,8,9}
					,{2,4,9,12}
					,{4,7,10,13}};

	std::cout<<YangMatrixFind((int*)arr1,4,4,1)<<std::endl;				//找最小值
	std::cout<<YangMatrixFind((int*)arr1,4,4,15)<<std::endl;			//找最大值
	std::cout<<YangMatrixFind((int*)arr1,4,4,9)<<std::endl;				//找介于最小值与最大值之间
	std::cout<<YangMatrixFind((int*)arr1,4,4,-1)<<std::endl;			//不存在的最小值
	std::cout<<YangMatrixFind((int*)arr1,4,4,16)<<std::endl<<std::endl; //不存在的最大值

	std::cout<<YangMatrixFind((int*)arr2,4,3,1)<<std::endl;				 //找最小值
	std::cout<<YangMatrixFind((int*)arr2,4,3,11)<<std::endl;			 //找最大值
	std::cout<<YangMatrixFind((int*)arr2,4,3,7)<<std::endl;				 //找介于最小值与最大值之间
	std::cout<<YangMatrixFind((int*)arr2,4,3,-1)<<std::endl;			 //不存在的最小值
	std::cout<<YangMatrixFind((int*)arr2,4,3,16)<<std::endl<<std::endl; //不存在的最大值

	std::cout<<YangMatrixFind((int*)arr3,3,4,1)<<std::endl;				//找最小值
	std::cout<<YangMatrixFind((int*)arr3,3,4,13)<<std::endl;			//找最大值
	std::cout<<YangMatrixFind((int*)arr3,3,4,9)<<std::endl;				//找介于最小值与最大值之间
	std::cout<<YangMatrixFind((int*)arr3,3,4,-1)<<std::endl;			//不存在的最小值
	std::cout<<YangMatrixFind((int*)arr3,3,4,16)<<std::endl<<std::endl; //不存在的最大值

}
