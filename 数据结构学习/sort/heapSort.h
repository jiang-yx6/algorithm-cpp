#pragma once
#include<iostream>
#include<vector>
using namespace std;
void heapInsert(vector<int>& arr, int i);
void heapify(vector<int>& arr, int root ,int heapSize);
void swap(vector<int>& arr, int i,int j);

/*
从下标0开始，对于父节点下标 i ,子节点下标为 2*i+1 和 2*i+2
			对于子节点下标 i ,父节点下标为 (i-1)/2
			对于根节点下标 0 ,父节点下标为 -1/2 == 0
*/
void heapSort(vector<int>& arr) {
	
	if (arr.size() < 2 || arr.empty())
		return;

	for (int i = 0; i < arr.size(); i++) {
		heapInsert(arr, i); // 一个一个插，实现初始化大根堆
	}

	/*for (int i = arr.size()-1; i >= 0; i--) {
		heapify(arr, i, arr.size()); //从最后一个元素为根，使用heapify调整，并循环往前
	}*/

	int heapSize = arr.size();

	swap(arr, 0, --heapSize);//将大根堆根节点与最后一位交换位置，heapSize-1

	while (heapSize > 0)
	{
		heapify(arr, 0,heapSize); //从根节点开始，重新调整至大根堆
		swap(arr, 0, --heapSize);
	}
}

void heapInsert(vector<int>& arr, int index) {
	while (arr[(index - 1) / 2] < arr[index]) {
		swap(arr, (index - 1) / 2, index);
		index = (index - 1) / 2;
	}
}

void swap(vector<int>& arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void heapify(vector<int>& arr, int root,int heapSize)
{
	int index = root;
	while (index * 2 + 1 < heapSize) //循环条件要求至少有一个子节点
	{
		//两个孩子中，谁的值更大，把下标给largest
		int largest = index*2+2 < heapSize && arr[index * 2 + 1] < arr[index * 2 + 2] ? index * 2 + 2 : index * 2 + 1;
		
		//父和较大孩子之间比较，父的大，退出；孩子大，交换
		if (arr[index] > arr[largest])
			break;
		swap(arr, index, largest);
		//更新父节点
		index = largest;
	}
}