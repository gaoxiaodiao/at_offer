/*
*������02:��ά����Ĳ���
*����:��С��
*����:2017-03-17
*���ɿ�������:Microsoft Visual Studio 2010 
*/
#pragma once
#include<cassert>
bool YangMatrixFind(int *arr,size_t row,size_t col,int key){
	assert(arr);
	int x = 0;
	int y = col-1;
	while(x<row && y>=0){
		if(arr[x*col+y] < key){
			++x;	//��ǰλ��С��key,ȥ��һ��
		}else if(arr[x*col+y] > key){
			--y;	//��ǰλ�ô���key,ȥ��һ��
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

	std::cout<<YangMatrixFind((int*)arr1,4,4,1)<<std::endl;				//����Сֵ
	std::cout<<YangMatrixFind((int*)arr1,4,4,15)<<std::endl;			//�����ֵ
	std::cout<<YangMatrixFind((int*)arr1,4,4,9)<<std::endl;				//�ҽ�����Сֵ�����ֵ֮��
	std::cout<<YangMatrixFind((int*)arr1,4,4,-1)<<std::endl;			//�����ڵ���Сֵ
	std::cout<<YangMatrixFind((int*)arr1,4,4,5)<<std::endl;				//�����ڽ�����Сֵ�����ֵ֮��
	std::cout<<YangMatrixFind((int*)arr1,4,4,16)<<std::endl<<std::endl; //�����ڵ����ֵ

	std::cout<<YangMatrixFind((int*)arr2,4,3,1)<<std::endl;				 //����Сֵ
	std::cout<<YangMatrixFind((int*)arr2,4,3,11)<<std::endl;			 //�����ֵ
	std::cout<<YangMatrixFind((int*)arr2,4,3,7)<<std::endl;				 //�ҽ�����Сֵ�����ֵ֮��
	std::cout<<YangMatrixFind((int*)arr2,4,3,-1)<<std::endl;			 //�����ڵ���Сֵ
	std::cout<<YangMatrixFind((int*)arr1,4,4,5)<<std::endl;				//�����ڽ�����Сֵ�����ֵ֮��
	std::cout<<YangMatrixFind((int*)arr2,4,3,16)<<std::endl<<std::endl;	//�����ڵ����ֵ

	std::cout<<YangMatrixFind((int*)arr3,3,4,1)<<std::endl;				//����Сֵ
	std::cout<<YangMatrixFind((int*)arr3,3,4,13)<<std::endl;			//�����ֵ
	std::cout<<YangMatrixFind((int*)arr3,3,4,9)<<std::endl;				//�ҽ�����Сֵ�����ֵ֮��
	std::cout<<YangMatrixFind((int*)arr3,3,4,-1)<<std::endl;			//�����ڵ���Сֵ
	std::cout<<YangMatrixFind((int*)arr1,4,4,5)<<std::endl;				//�����ڽ�����Сֵ�����ֵ֮��
	std::cout<<YangMatrixFind((int*)arr3,3,4,16)<<std::endl<<std::endl; //�����ڵ����ֵ

}
