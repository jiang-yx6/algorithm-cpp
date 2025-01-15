#pragma once
#include<iostream>
void merge(int* arr, int left, int mid, int right);

void Process(int* arr, int left, int right)
{
	if (left == right) {
		return;
	} //如果数组长度为1,直接返回空
	int mid = left + ((right - left) >> 1); //求中点
	Process(arr, left, mid); //递归调用，左段排序
	Process(arr, mid + 1, right); //递归调用，右段排序
	merge(arr, left, mid, right); //合并两段
}

void merge(int* arr, int left, int mid, int right)
{
	int* help = new int[right - left + 1]; 
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	/*
	比较两个数组当前位置，小的部分那个放入临时数组，两者后移一位
	直到有一方全部进入临时数组
	*/
	while (p1 <= mid && p2 <= right) 
		help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++]; 
	//将有剩余的一方全部放入临时数组
	while (p1 <= mid)
		help[i++] = arr[p1++];
	while (p2 <= right)
		help[i++] = arr[p2++];
	for (int j = 0; j < right - left + 1; j++)//拷贝到原始数组
		arr[j + left] = help[j];
}



// 小和问题

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
