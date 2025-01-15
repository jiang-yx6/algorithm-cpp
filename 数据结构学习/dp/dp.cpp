#include "0-1bag.h"
#include "lcs.h"
#include "maxSubSeq.h"
void Knapsack(int* value, int* weight, int c, int n, int** dp, bool** include) {
	int sumWeight = 0;
	// 初始化最后一行
	for (int j = 0; j <= c; j++) {
		if (j < weight[n - 1]) {
			dp[n - 1][j] = 0; // 最后一个物品不能放
			include[n - 1][j] = false;
		}
		else {
			dp[n - 1][j] = value[n - 1]; // 最后一个物品能放一定会放
			include[n - 1][j] = true;
		}
	}

	// 填充 dp 表
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= c; j++) {
			if (j < weight[i]) {
				dp[i][j] = dp[i + 1][j]; // 当前物品不能放
				include[i][j] = false;
			}
			else {
				if (dp[i + 1][j] > dp[i + 1][j - weight[i]] + value[i]) {
					dp[i][j] = dp[i + 1][j]; // 当前物品不能放
					include[i][j] = false;
				}
				else {
					dp[i][j] = dp[i + 1][j - weight[i]] + value[i]; // 当前物品能放
					include[i][j] = true;
				}
			}
		}
	}

	// 输出结果
	int remainingCapacity = c;
	for (int i = 0; i < n; i++) {
		if (include[i][remainingCapacity]) {
			sumWeight += weight[i];
			cout << "Item " << i + 1 << " is included (weight: " << weight[i] << ", value: " << value[i] << ")" << endl;
			remainingCapacity -= weight[i];
		}
	}
	cout << "Maximum value in Knapsack: " << dp[0][c] << endl;
	cout << "Total weight: " << sumWeight << endl;

}

void backpack(int* value, int* weight, int c, int n,int **dp, bool**include) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= c; j++) {
			dp[i][j] = dp[i - 1][j]; 
			if (j >= weight[i])//背包容量大于当前物品
				dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i][j]);
		}
	}
	cout << "Maximum value in Knapsack: " << dp[n - 1][c] << endl;
}
void LCSLength(int m, int n, char* x, char* y, int** c, int** b)
{
	for (int i = 0; i <= m; i++)c[i][0] = 0;
	for (int i = 0; i <= n; i++)c[0][i] = 0;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else {
				if (c[i - 1][j] >= c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = 2;
				}
				else
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = 3;
				}
			}
		}

	}
}

void LCS(int i, int j, char* x, int** b)
{
	if (i == 0 || j == 0)return;
	if (b[i][j] == 1)
	{
		LCS(i - 1, j - 1, x, b);
		std::cout << x[i - 1];
	}
	else if (b[i][j] == 2)
		LCS(i - 1, j, x, b);
	else
		LCS(i, j - 1, x, b);
}


int maxSumOfSubsequence(int n, int* array) {
	int sum = 0;
	int* b = new int[n];
	b[0] = array[0];
	for (int i = 1; i < n; i++) {
		b[i] = b[i - 1] + array[i] < array[i] ? array[i] : b[i - 1] + array[i];
		sum = sum > b[i] ? sum : b[i];
	}
	return sum;
}