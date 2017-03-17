/*
*面试题02:二维数组的查找
*作者:高小调
*日期:2017-03-17
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cassert>
bool YangMatrixFind(int *arr,size_t row,size_t col,int key){
	assert(arr);
	int x = 0;
	int y = col-1;
	while(x<row && y>=0){
		if(arr[x*col+y] < key){
			++x;	//当前位置小于key,去掉一行
		}else if(arr[x*col+y] > key){
			--y;	//当前位置大于key,去掉一列
		}else{
			return true;
		}
	}
	return false;
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
	std::cout<<YangMatrixFind((int*)arr1,4,4,5)<<std::endl;				//不存在介于最小值与最大值之间
	std::cout<<YangMatrixFind((int*)arr1,4,4,16)<<std::endl<<std::endl; //不存在的最大值

	std::cout<<YangMatrixFind((int*)arr2,4,3,1)<<std::endl;				 //找最小值
	std::cout<<YangMatrixFind((int*)arr2,4,3,11)<<std::endl;			 //找最大值
	std::cout<<YangMatrixFind((int*)arr2,4,3,7)<<std::endl;				 //找介于最小值与最大值之间
	std::cout<<YangMatrixFind((int*)arr2,4,3,-1)<<std::endl;			 //不存在的最小值
	std::cout<<YangMatrixFind((int*)arr1,4,4,5)<<std::endl;				//不存在介于最小值与最大值之间
	std::cout<<YangMatrixFind((int*)arr2,4,3,16)<<std::endl<<std::endl;	//不存在的最大值

	std::cout<<YangMatrixFind((int*)arr3,3,4,1)<<std::endl;				//找最小值
	std::cout<<YangMatrixFind((int*)arr3,3,4,13)<<std::endl;			//找最大值
	std::cout<<YangMatrixFind((int*)arr3,3,4,9)<<std::endl;				//找介于最小值与最大值之间
	std::cout<<YangMatrixFind((int*)arr3,3,4,-1)<<std::endl;			//不存在的最小值
	std::cout<<YangMatrixFind((int*)arr1,4,4,5)<<std::endl;				//不存在介于最小值与最大值之间
	std::cout<<YangMatrixFind((int*)arr3,3,4,16)<<std::endl<<std::endl; //不存在的最大值

}
