#include<iostream>
void MatrixChain(int* p, int n, int** m, int** s)
{
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for (int r = 2; r <= n; r++)
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			m[i][j] = 0 + m[i][j - 1] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;

			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					s[i][j] = k;
					m[i][j] = t;
				}
			}
		}
		
	}
}

