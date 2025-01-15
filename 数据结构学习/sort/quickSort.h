#pragma once
#include<iostream>
#include<vector>

using namespace std;

int partition(int* nums, int left, int right);

void quickSort(int* nums, int left, int right) {
	if (left >= right) //递归到底直接返回
		return;

	int pivot = partition(nums, left, right); //找到基准位置，分为左右两块分别作排序

	quickSort(nums, left, pivot - 1);  //左部分排序
	quickSort(nums, pivot + 1, right); //右部分排序
}


int partition(int* nums, int left, int right)
{
	int i = left;
	int j = right;

	while (i < j) {
		//注意两个循环顺序不能换，先让j--找到比基准数小的，这样无论i++能否找到比基准数大的，最后如果i==j跳出循环后进行交换仍能确保和基准数交换的数小于等于基准数
		while (i < j && nums[j] >= nums[left])
			j--;

		while (i < j && nums[i] <= nums[left])
			i++;
		swap(nums[i], nums[j]);
	}

	swap(nums[j], nums[left]);
	return j;
}


//int main() {
//	vector<int>nums = { 5,6,5,8,9,1 };
//	quickSort(nums, 0, 5);
//	for (int index = 0; index < nums.size(); index++) {
//		cout << nums[index] << " ";
//	}
//}