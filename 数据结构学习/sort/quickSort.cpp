//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int partition(vector<int>& nums, int left, int right);
//
//void quickSort(vector<int>& nums, int left, int right) {
//	if (left >= right)
//		return;
//	
//	int pivot = partition(nums, left, right);
//
//	quickSort(nums, left, pivot-1);
//	quickSort(nums, pivot+1, right);
//}
//
//
//int partition(vector<int>& nums, int left, int right)
//{
//	int i = left;
//	int j = right;
//
//	while (i < j) {
//		//ע������ѭ��˳���ܻ�������j--�ҵ��Ȼ�׼��С�ģ���������i++�ܷ��ҵ��Ȼ�׼����ģ�������i==j����ѭ������н�������ȷ���ͻ�׼����������С�ڵ��ڻ�׼��
//		while (i < j && nums[j] >= nums[left])
//			j--;
//
//		while (i < j && nums[i] <= nums[left])
//			i++;
//
//		
//		swap(nums[i], nums[j]);
//	}
//
//	swap(nums[j], nums[left]);
//	return j;
//}
//
//
////int main() {
////	vector<int>nums = { 5,6,5,8,9,1 };
////	quickSort(nums, 0, 5);
////	for (int index = 0; index < nums.size(); index++) {
////		cout << nums[index] << " ";
////	}
////}