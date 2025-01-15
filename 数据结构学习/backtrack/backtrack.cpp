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
	} //��ʼ����ɫ��0Ϊδ��ɫ
	for (int k = 1; k < n; k++) { //��k=1 ��ʼ�����ӵ�һ����ɫ�鿪ʼ��ɫ
		x[k] += 1; //x[k]�����k�������ɫΪx[k]

		while (x[k] <= m && is_OK(k, n))  //����ɹ���ɫ����ɫ��С�������ɫ�� && �ڽӾ���û����ɫ��ͻ��
			x[k] += 1;
		if(x[k] <= m) {
			if (k == n) break; //���k==n�ɹ���ֱ���˳�
		}
		else { //���������ɫ��,˵��������ɫ����������Ҫ�����ò�����
			x[k] = 0;
			k--;
		}
	}
}



void coloring_s(int m, int n,int k) {//�ӵ�k����ɫ�鿪ʼ��ɫ
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
		//������
		return;
	}
	for (int i = 0; i <= 1; i++) {
		x[k] = i;
		if (bound(k, i, j)) {
			backpack_01(k + 1, j - i * w[k]);
		}
	}
}