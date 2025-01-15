#pragma once
#include<iostream>
void merge(int* arr, int left, int mid, int right);

void Process(int* arr, int left, int right)
{
	if (left == right) {
		return;
	} //������鳤��Ϊ1,ֱ�ӷ��ؿ�
	int mid = left + ((right - left) >> 1); //���е�
	Process(arr, left, mid); //�ݹ���ã��������
	Process(arr, mid + 1, right); //�ݹ���ã��Ҷ�����
	merge(arr, left, mid, right); //�ϲ�����
}

void merge(int* arr, int left, int mid, int right)
{
	int* help = new int[right - left + 1]; 
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	/*
	�Ƚ��������鵱ǰλ�ã�С�Ĳ����Ǹ�������ʱ���飬���ߺ���һλ
	ֱ����һ��ȫ��������ʱ����
	*/
	while (p1 <= mid && p2 <= right) 
		help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++]; 
	//����ʣ���һ��ȫ��������ʱ����
	while (p1 <= mid)
		help[i++] = arr[p1++];
	while (p2 <= right)
		help[i++] = arr[p2++];
	for (int j = 0; j < right - left + 1; j++)//������ԭʼ����
		arr[j + left] = help[j];
}



// С������

int mergeOfSum(int* arr, int left, int mid, int right);
int ProcessOfSum(int* arr, int left, int right)
{
	if (left >= right)
		return 0;
	int mid = left + ((right - left) >> 1);
	return ProcessOfSum(arr, left, mid) +
		ProcessOfSum(arr, mid + 1, right) + 
		mergeOfSum(arr, left, mid, right);
}

int mergeOfSum(int* arr, int left, int mid, int right)
{
	int* help = new int[right - left + 1];
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	int res = 0;
	while (p1 <= mid && p2 <= right) {
		res += arr[p1] < arr[p2] ? (right - p2 + 1) * arr[p1] : 0;
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= mid) {
		help[i++] = arr[p1++];
	}
	while (p2 <= mid) {
		help[i++] = arr[p2++];
	}
	return res;
}
