#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue

int FASTBUFFER;

using namespace std;

const int N = 2005;
const long long OO = (1LL << 60);

int n, m, k, p, a[N][N];
long long row[N], col[N], f[N * N], g[N * N], ans = -OO;

void work(int n, int m, long long v[], long long f[]);

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &p);
	for (int i = 1; i <= n; i++)
	{
		row[i] = 0;
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]), row[i] += a[i][j];
	}
	
	work(n, m, row, f);
	for (int i = 1; i <= m; i++)
	{
		col[i] = 0;
		for(int j = 1; j <= n; j++)
			col[i] += a[j][i];
	}
	
	work(m, n, col, g);
	for (int i = 0; i <= k; i++)
		ans = max(ans, f[i] + g[k - i] - 1LL * (k - i) * i * p);
	cout << ans << endl;
	return 0;
}

void work(int n, int m, long long v[], long long f[])
{
	PQ <long long> q;
	for (int i = 1; i <= n; i++)
		q.push(v[i]);
	f[0] = 0;
	for (int i = 1; i <= k; i++) 
	{
		long long temp = q.top();
		q.pop();
		f[i] = f[i - 1] + temp;
		q.push(temp - m * p);
	}
	
	return;
}