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
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;
const int mo = 1000000009;

using namespace std;

struct Matrix
{
	int n;
	int a[4][4];
	
	Matrix () {}
	
	Matrix (int n) : n(n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = 0;
	}
	
	friend Matrix operator * (Matrix a, Matrix b)
	{
		int n = a.n;
		Matrix ret(n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					(ret.a[i][j] += (long long)a.a[i][k] * b.a[k][j] % mo) %= mo;
		return ret;
	}
};

const int N = 1200005;

int n, m, ans;
int a[N], Left[N], Right[N], ta[N], tb[N], sum[N];
Matrix mi[N];

void make(int l, int r, int i)
{
	int mid = ((l + r) >> 1);
	Left[i] = l, Right[i] = r;
	if (l == r)
	{
		sum[i] = a[l];
		return;
	}
	
	int lc = (i << 1), rc = (lc | 1);
	make(l, mid, lc);
	make(mid + 1, r, rc);
	sum[i] = (sum[lc] + sum[rc]) % mo;
}

void ins(int i, int aa, int bb)
{
	int l = Left[i], r = Right[i];
	(sum[i] += ((long long)aa * mi[r - l + 1].a[1][3] + (long long)bb * mi[r - l + 1].a[2][3]) % mo) %= mo;
	(ta[i] += aa) %= mo;
	(tb[i] += bb) %= mo;
	return;
}

void down(int i)
{
	if (Left[i] == Right[i])
		return;
	int lc = (i << 1), rc = (lc | 1);
	ins(lc, ta[i], tb[i]);
	int x = Left[rc] - Left[lc], aa, bb;
	aa = ((long long)ta[i] * mi[x].a[1][1] + (long long)tb[i] * mi[x].a[2][1]) % mo;
	bb = ((long long)ta[i] * mi[x].a[1][2] + (long long)tb[i] * mi[x].a[2][2]) % mo;
	ins(rc, aa, bb);
	ta[i] = tb[i] = 0;
	return;
}

void ask(int l, int r, int i)
{
	if (l > Right[i] || r < Left[i])
		return;
	if (l <= Left[i] && r >= Right[i])
	{
		(ans += sum[i]) %= mo;
		return;
	}
	
	down(i);
	ask(l, r, (i << 1));
	ask(l, r, ((i << 1) | 1));
}

void add(int l, int r, int i, int a, int b)
{
	if (l > Right[i] || r < Left[i])
		return;
	if (l <= Left[i] && r >= Right[i])
	{
		int x = Left[i] - l, aa, bb;
		if (l == Left[i])
			aa = a, bb = b;
		else
		{
			aa = ((long long)a * mi[x].a[1][1] + (long long)b * mi[x].a[2][1]) % mo;
			bb = ((long long)a * mi[x].a[1][2] + (long long)b * mi[x].a[2][2]) % mo;
		}
		
		ins(i, aa, bb);
		return;
	}
	
	down(i);
	int lc = (i << 1), rc = (lc | 1);
	add(l, r, lc, a, b);
	add(l, r, rc, a, b);
	sum[i] = (sum[lc] + sum[rc]) % mo;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	make(1, n, 1);
	mi[0].n = 3;
	for (int i = 1; i <= 3; i++)
		mi[0].a[i][i] = 1;
	mi[1].n = 3;
	mi[1].a[2][1] = mi[1].a[1][2] = mi[1].a[1][3] = mi[1].a[2][2] = mi[1].a[3][3] = 1;
	for (int i = 2; i <= n + 1; i++)
		mi[i] = mi[i - 1] * mi[1];
	for (int i = 1; i <= m; i++)
	{
		int type, l, r;
		scanf("%d %d %d", &type, &l, &r);
		if (type == 1)
			add(l, r, 1, 1, 1);
		else
			ans = 0, ask(l, r, 1), printf("%d\n", ans);
	}
	
	return 0;
}