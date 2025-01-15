#pragma once
#include <iostream>
struct Coin {
	int value;
	int num;
};

bool greaterSort(Coin x, Coin y);

void greedySelectorForPayMoney(int* coinValue, int* coinNum, int num, int money);
