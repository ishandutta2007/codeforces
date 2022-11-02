#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[1100][1100];
int aa[1100][1100];
int b[1100][1100];
int mb[1100];
int c[1100][1100];
int mc[1100];
int tmp1[1100][1100];
int tmp2[1100][1100];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d",&a[i][j]);
			tmp1[i][j] = tmp2[j][i] = aa[j][i] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		sort(tmp1[i], tmp1[i] + m); int sz = unique(tmp1[i], tmp1[i] + m) - tmp1[i];
		mb[i] = sz;
		for (int j = 0; j < m; j++)b[i][j] = lower_bound(tmp1[i], tmp1[i] + sz, a[i][j])-tmp1[i] + 1;
	}
	for (int i = 0; i < m; i++)
	{
		sort(tmp2[i], tmp2[i] + n); int sz = unique(tmp2[i], tmp2[i] + n) - tmp2[i];
		mc[i] = sz;
		for (int j = 0; j < n; j++)c[i][j] = lower_bound(tmp2[i], tmp2[i] + sz, aa[i][j]) - tmp2[i] + 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] >= c[j][i])
			{
				cout << max(mb[i], mc[j] + b[i][j] - c[j][i]) << " ";
			}
			else
			{
				cout << max(mc[j], mb[i] + c[j][i] - b[i][j]) << " ";
			}
		}
		cout << endl;
	}
}