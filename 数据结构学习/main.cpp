#include<fstream>
#include"./sort/mergeSort.h"
#include"./sort/RandomCheckMachine.h"
#include"./sort/RandomSelect.h"
#include"./sort/heapSort.h"
#include"./sort/Comparator.h"
#include"./dp/matrix.hpp"
#include"./dp/0-1bag.h"
#include "./dp/maxSubSeq.h"
#include"./dp/lcs.h"
#include"./greedy/paymoney.h"
#include"./greedy/huffman.h"
#include<random>
#include <sstream>
using namespace std;

void test1()
{
	int times, length, minValue, maxValue;
	cout << "input times, length, minValue, maxValue" << endl;
	cin >> times >> length >> minValue >> maxValue;
	SortCheckMachine mergeMachine(times, length, minValue, maxValue);
	mergeMachine.mergeSortCheckMachine(Process);
}

void test2()
{
	int times, length, minValue, maxValue;
	cout << "input times, length, minValue, maxValue" << endl;
	cin >> times >> length >> minValue >> maxValue;
	SortCheckMachine Machine(times, length, minValue, maxValue);
	Machine.LinearTimeRandomSelectCheckMachine(RandomizedSelectThreeParts);
	Machine.LinearTimeRandomSelectCheckMachine(RandomizedSelectTwoParts);
}

void test3()
{
	int array[] = { 2,3,6,4,1,7,8 };
	int value = RandomizedSelectThreeParts(array, 0, 6, 5);
	cout << value;
}

void test4()
{
	vector<int>arr = { 1,3,4,7,5,1,0,4 };
	heapSort(arr);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}

// 最长公共子序列
void readFileIntoStrings(const string& filename, vector<string>& strings) {
	ifstream file(filename);
	if (file.is_open()) {
		string line;
		string currentData;
		while (getline(file, line)) {
			if (line.empty()) { //遇到空行
				if (!currentData.empty()) {
					strings.push_back(currentData);
					currentData.clear();
				}
			}
			else {
				int len = line.length();
				if (line != "A:" && line != "B:" && line != "C:" && line != "D:") {
						currentData.append(line);
				}
			}
		}
		if (!currentData.empty()) {
			strings.push_back(currentData);
		}
		file.close();
	}
	else {
		cerr<< "Failed to open file: " << filename << endl;
	}
}


void test5(char* x, char* y)
{
	
	int m = strlen(x);
	int n = strlen(y);

	int** c = new int* [m+1];
	
	for (int i = 0; i <= m; ++i) {
		c[i] = new int[n+1];
	}

	int** b = new int* [m+1];

	for (int i = 0; i <= m; ++i) {
		b[i] = new int[n+1];
	}
	LCSLength(m, n, x, y, c, b);
	LCS(m, n, x, b);
	cout << std::endl;

	for (int i = 0; i <= m; i++) {
		delete[] c[i];
		delete[] b[i];
	}
	delete[] c;
	delete[] b;
}


void test6() {
	
	std::vector<std::string> data;
	readFileIntoStrings("test.txt", data);
	std::string A,B,C,D;
	
	if (data.size() >= 4) {
		A = data[0];
		B = data[1];
		C = data[2];
		D = data[3];

		// 输出字符串以验证读取结果
		std::cout << "A is: " << A << std::endl;
		std::cout << "B is: " << B << std::endl;
		std::cout << "C is: " << C << std::endl;
		std::cout << "D is: " << D << std::endl;
	}
	else {
		std::cerr << "The file does not contain enough data sections." << std::endl;
	}

	test5((char*)A.c_str(), (char*)B.c_str());
	test5((char*)C.c_str(), (char*)D.c_str());
	test5((char*)A.c_str(), (char*)D.c_str());
	test5((char*)C.c_str(), (char*)B.c_str());
}


//最大字段和
void test7() {
    int array[] = { 1,2,-5,4,9,-8,6,3,-3,2,-1 };
	int length = sizeof(array) / sizeof(array[0]);
    int Sum = maxSumOfSubsequence(length, array);
    cout << Sum;
}


void test8() {
	int value[] = { 60,100,120,140 };
	int weight[] = { 2,3,4,5 };
    int maxWeight = 10;
	int n = sizeof value / sizeof(int);
	int** dp = new int* [n];
	bool** include = new bool* [n];
    for (int i = 0; i < n; i++) {
		dp[i] = new int[maxWeight+1];
        include[i] = new bool[maxWeight+1];
		for (int j = 0; j <= maxWeight; j++) {
			dp[i][j] = 0;
            include[i][j] = false;
		}
	}
	backpack(value,weight,maxWeight,n,dp,include);
	for (int i = 0; i < n; i++) {
		delete[] dp[i];
	}
	delete[] dp;
}
void readData(vector<int>& vectorValue) {
	// 读取整行输入
	std::string line;
	if (std::getline(std::cin, line)) {
		std::istringstream iss(line);
		int number;
		// 逐个读取整数
		while (iss >> number) {
			vectorValue.push_back(number);
		}
	}
}
void test9() {
		vector<int> itemsWeight;
		vector<int> itemsValue;
		int bagCapcity;//背包容量
        cout << "Enter the bag capacity: ";
		cin >> bagCapcity;
		getchar();
		cout << "Enter the items weight: ";
        readData(itemsWeight);
        cout << "Enter the items value: ";
        readData(itemsValue);

		int n = itemsWeight.size();
		int* itemsWeightArray = new int[n];
		int* itemsValueArray = new int[n];
        for (int i = 0; i < n; i++) {
			itemsWeightArray[i] = itemsWeight[i];
			itemsValueArray[i] = itemsValue[i];
		}

		int** dp = new int* [n];
		bool** include = new bool* [n];
		for (int i = 0; i < n; i++) {
			dp[i] = new int[bagCapcity + 1];
			include[i] = new bool[bagCapcity + 1];
			for (int j = 0; j <= bagCapcity; j++) {
				dp[i][j] = 0;
				include[i][j] = false;
			}
		}
		Knapsack(itemsValueArray, itemsWeightArray, bagCapcity, n, dp, include);
		for (int i = 0; i < n; i++) {
			delete[] dp[i];
			delete[] include[i];
		}
		delete[] dp;
        delete[] itemsWeightArray;
        delete[] itemsValueArray;
        delete[] include;
}

void test10() {
	int coinValue[] = { 1,2,5,8,10 };
	int coinNum[] = { 5,4,3,2,1 };
	greedySelectorForPayMoney(coinValue, coinNum, 5, 21);
}

void test11() {
	greedySelectorForHaffman();
}


int main()
{
	test11();
	return 0;
}