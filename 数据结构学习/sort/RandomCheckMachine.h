#pragma once
#include<time.h>
#include<iostream>
#include<algorithm>
#include"quickSort.h"
#include"mergeSort.h"
#include <sys/timeb.h>
#define ARRAYSIZE(length)  (length*sizeof(int))

class SortCheckMachine
{
public:
	int times;
	int length;
	int minValue;
	int maxValue;
	timeb start;
	timeb end;
	SortCheckMachine(int t, int l, int min, int max) :times(t), length(l), minValue(min), maxValue(max) {};

	void mergeSortCheckMachine(void (*callback)(int*, int, int));
	
	void LinearTimeRandomSelectCheckMachine(int (*callback)(int*, int, int,int));

	bool SortCompare(int*, int*,int);
};

bool SortCheckMachine::SortCompare(int* originArr, int* nowArr,int length)
{
	sort(originArr, originArr + length);
	if (memcmp(originArr, nowArr, ARRAYSIZE(length)) == 0)
		return true;
	else
		return false;
}


void SortCheckMachine::mergeSortCheckMachine(void (*callback)(int*, int, int))
{

	srand(time(NULL));
	ftime(&start);
	int i;
	for (i = 0; i < times; i++)
	{
		int* array = new int[length];
		for (int j = 0; j < length; j++) {
			int value = minValue + rand() % (maxValue - minValue + 1);
			array[j] = value;
		}
		int* origin = new int[length];
		memcpy(origin, array, ARRAYSIZE(length));
		callback(array, 0, length - 1);
		if (!SortCompare(origin, array, length))
			break;
		delete[]origin;
		delete[]array;
	}
	ftime(&end);
	if(i==times)
		cout << "Successfully!" << endl;
	else
		cout << "Fucking Failed!" << endl;
	cout << "Sort time used is: " << (end.time - start.time) * 1000 + (end.millitm - start.millitm) << endl;
}

void SortCheckMachine::LinearTimeRandomSelectCheckMachine(int (*callback)(int*, int, int, int))
{
	srand(time(NULL));
	int i;
	ftime(&start);
	for (i = 0; i < times; i++) {
		int* array = new int[length];
		for (int j = 0; j < length; j++)
		{
			int value = minValue + rand() % (maxValue - minValue + 1);
			array[j] = value;
		}
		int randomIndex = 1 + rand() % (length);
		int* origin = new int[length];
		memcpy(origin, array, ARRAYSIZE(length));
		int targetValue = callback(array, 0, length - 1,randomIndex);
		sort(origin, origin + length);
		int TrueValue = origin[randomIndex - 1];
		if (targetValue != TrueValue)
		{
			cout << "The random index is:" << randomIndex << endl;
			cout << "The sorted array is: ";
			for (int i = 0; i < length; i++)
			{
				cout << array[i]<<" ";
			}
			cout << endl;
			cout << "True Value is:" << TrueValue << " targetValue is:" << targetValue << endl;
			break;
		}
		delete[]origin;
		delete[]array;
	}
	ftime(&end);
	if (i == times)
	{
		cout << "Successfully!" << endl;
		cout << "Sort time used is: " << (end.time - start.time) * 1000 + (end.millitm - start.millitm) << endl;
	}

	else
		cout << "Fucking Failed!" << endl;
}
