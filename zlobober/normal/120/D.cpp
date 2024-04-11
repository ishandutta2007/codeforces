#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 55;
int A[N][N];
int B[N][N];
int n, m;

void reswap()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			B[j][i] = A[i][j];
	memcpy(A, B, sizeof(A));
	swap(m, n);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> QQ;
	QQ.push_back(a);
	QQ.push_back(b);
	QQ.push_back(c);
	sort(QQ.begin(), QQ.end());
	int ans = 0;
	vector<int> UU;
	for (int iter = 0; iter < 2; iter++)
	{
		for (int x = 1; x < m - 1; x++)
			for (int y = x + 1; y < m; y++)
			{
				UU.clear();
				int p = 0, q = 0, r = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < x; j++)
						p += A[i][j];
					for (int j = x; j < y; j++)
						q += A[i][j];
					for (int j = y; j < m; j++)
						r += A[i][j];
				}
				UU.push_back(p);
				UU.push_back(q);
				UU.push_back(r);
				sort(UU.begin(), UU.end());
				if (QQ == UU)
					ans++;
			}
		reswap();
	}
	cout << ans;
}