#include<iostream>

bool* link[];
int x[];
bool is_OK(int k, int n) {
	for (int i = 0; i < n; i++) {
		if (link[i][k] && x[i] == x[k]) return false;
	}
	return true;

}
void coloring(int m, int n) {
	for (int i = 0; i <= n; i++) {
		x[i] = 0;
	} //初始化着色，0为未着色
	for (int k = 1; k < n; k++) { //从k=1 开始，即从第一个着色块开始着色
		x[k] += 1; //x[k]代表第k个块的颜色为x[k]

		while (x[k] <= m && is_OK(k, n))  //如果成功着色（着色数小于最大着色数 && 邻接矩阵没有颜色冲突）
			x[k] += 1;
		if(x[k] <= m) {
			if (k == n) break; //如果k==n成功，直接退出
		}
		else { //如果大于着色数,说明所有颜色都不能满足要求，重置并回溯
			x[k] = 0;
			k--;
		}
	}
}



void coloring_s(int m, int n,int k) {//从第k个着色块开始着色
	if (k > n) {
		for (int i = 1; i <= n; i++) {
			std::cout << x[i];
		}
		return; 
	}
	for (int i = 1; i <= m; i++) {
		x[k] = i;
		if (is_OK(k, n)) coloring_s(m, n, k + 1);
		x[k] = 0;
	}
}



/*-------------------------------------------*/

int x[];
int w[];
bool bound(int k, int i ,int j) {}
void backpack_01(int k,int j,int n){
	if (k > n) {
		//输出结果
		return;
	}
	for (int i = 0; i <= 1; i++) {
		x[k] = i;
		if (bound(k, i, j)) {
			backpack_01(k + 1, j - i * w[k]);
		}
	}
}