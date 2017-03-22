/*
*面试题08:找旋转数组中最小的数
*作者:高小调
*日期:2017-03-22
*集成开发环境:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cassert>
//3 4 5 6 1 2 
int FindMinNumFromRotateArr(int *arr,size_t sz){
	assert(arr&&sz>0);
	int index1 = 0;
	int index2 = sz-1;
	int midIndex = 0;
	while(arr[index1]>=arr[index2]){
		if(index2-index1==1){
			midIndex = index2;
			break;
		}

		midIndex = (index1+index2)>>1;

		if(arr[index1]==arr[index2] && arr[midIndex] == arr[index1]){
			int ret = arr[index1];
			for(int i=index1+1; i<=index2; ++i){
				if(ret > arr[i]){
					ret = arr[i];
				}
			}
			return ret;
		}

		if(arr[midIndex] >= arr[index1]){
			index1 = midIndex;
		}else if(arr[midIndex] <= arr[index2]){
			index2 = midIndex;
		}

	}
	return arr[midIndex];
}

void TestFindMinNumFromRotateArr(){
	int arr1[] = {3,4,5,1,2};
	int arr2[] = {1,0,1,1,1};
	int arr3[] = {1,1,1,0,1};
	std::cout<<"旋转数组最小的数字为:";
	std::cout<<FindMinNumFromRotateArr(arr1,sizeof(arr1)/sizeof(arr1[0]))<<std::endl;
	std::cout<<FindMinNumFromRotateArr(arr2,sizeof(arr2)/sizeof(arr2[0]))<<std::endl;
	std::cout<<FindMinNumFromRotateArr(arr3,sizeof(arr3)/sizeof(arr3[0]))<<std::endl;
}