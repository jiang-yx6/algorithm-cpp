#pragma once
#include<iostream>
#include<vector>
using namespace std;
void heapInsert(vector<int>& arr, int i);
void heapify(vector<int>& arr, int root ,int heapSize);
void swap(vector<int>& arr, int i,int j);

/*
���±�0��ʼ�����ڸ��ڵ��±� i ,�ӽڵ��±�Ϊ 2*i+1 �� 2*i+2
			�����ӽڵ��±� i ,���ڵ��±�Ϊ (i-1)/2
			���ڸ��ڵ��±� 0 ,���ڵ��±�Ϊ -1/2 == 0
*/
void heapSort(vector<int>& arr) {
	
	if (arr.size() < 2 || arr.empty())
		return;

	for (int i = 0; i < arr.size(); i++) {
		heapInsert(arr, i); // һ��һ���壬ʵ�ֳ�ʼ�������
	}

	/*for (int i = arr.size()-1; i >= 0; i--) {
		heapify(arr, i, arr.size()); //�����һ��Ԫ��Ϊ����ʹ��heapify��������ѭ����ǰ
	}*/

	int heapSize = arr.size();

	swap(arr, 0, --heapSize);//������Ѹ��ڵ������һλ����λ�ã�heapSize-1

	while (heapSize > 0)
	{
		heapify(arr, 0,heapSize); //�Ӹ��ڵ㿪ʼ�����µ����������
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
	while (index * 2 + 1 < heapSize) //ѭ������Ҫ��������һ���ӽڵ�
	{
		//���������У�˭��ֵ���󣬰��±��largest
		int largest = index*2+2 < heapSize && arr[index * 2 + 1] < arr[index * 2 + 2] ? index * 2 + 2 : index * 2 + 1;
		
		//���ͽϴ���֮��Ƚϣ����Ĵ��˳������Ӵ󣬽���
		if (arr[index] > arr[largest])
			break;
		swap(arr, index, largest);
		//���¸��ڵ�
		index = largest;
	}
}