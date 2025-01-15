#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <cctype> // for std::isprint
#include <queue>
#include "paymoney.h"
using namespace std;


bool greaterSort(Coin x, Coin y) {
	return x.value > y.value;
}

/*付款问题，找到最少的钱币付款*/
void greedySelectorForPayMoney(int* coinValue, int* coinNum, int num, int money)
{
	std::vector<Coin>coins(num);
	for (int i = 0; i < num; i++)
	{
		coins[i].value = coinValue[i];
		coins[i].num = coinNum[i];
	}
	std::sort(coins.begin(), coins.end(), greaterSort);
	int sum = 0;
	vector<int>usedCoins(num, 0);
	for (int i = 0; i < num && sum < money; i++) {
		while (coins[i].num > 0 && sum + coins[i].value <= money)
		{
			sum += coins[i].value;
			coins[i].num--;
			usedCoins[i]++;
		}
	}
	if (sum == money) {
		for (int i = 0; i < num; i++) {
			cout << "The Money Value " << coins[i].value << "is used " << usedCoins[i] << endl;
		}
	}
	else {
		cout << "Can not pay the money" << endl;
	}

}




 