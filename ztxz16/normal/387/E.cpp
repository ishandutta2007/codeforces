#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ
#define N 2000005

using namespace std;

int FASTBUFFER;

struct Node
{
	int val, pos;
	
	friend bool operator < (Node a, Node b)
	{
		return a.val < b.val;
	}
}b[N];

int n, k, i, now, tot, a[N];
int A[N], B[N], Hash[N], Left[N], Right[N];
long long ans;

void add(int a, int b, int A[]);
int ask(int a, int A[]);
void Add(int a, int b, int A[]);
int Ask(int a, int A[]);
int Ask2(int a, int A[]);

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	now = 1;
	for (i = 1; i <= k; i++)
	{
		scanf("%d", &b[i].val);
		while (a[now] != b[i].val)
			now++;
		Hash[now] = 1;
	}
	
	tot = 0;
	for (i = 1; i <= n; i++)
	{
		Hash[i] ^= 1;
		if (Hash[i])
			b[++tot].val = a[i], b[tot].pos = i;
	}
	
	for (i = 1; i <= n; i++)
		B[i] = 1;
	for (i = 1; i <= n; i++)
	{
		Left[i] = Ask(a[i], B);
		if (Hash[i] == 0)
			Add(a[i], i + 1, B);
	}
	
	for (i = 1; i <= n; i++)
		B[i] = n;
	for (i = n; i >= 1; i--)
	{
		Right[i] = Ask2(a[i], B);
		if (Hash[i] == 0)
			Add(a[i], i - 1, B);
	}
	
	for (i = 1; i <= n; i++)
		add(i, 1, A);
	sort(b + 1, b + tot + 1);
	for (i = 1; i <= tot; i++)
	{
		now = b[i].pos;
		ans += ask(Right[now], A) - ask(Left[now] - 1, A);
		add(now, -1, A);
	}
	
	cout << ans << endl;
	return 0;
}

void add(int a, int b, int A[])
{
	for (int i = a; i <= n; i += (i & (0 - i)))
		A[i] += b;
}

int ask(int a, int A[])
{
	int ret = 0, i;
	for (i = a; i > 0; i -= (i & (0 - i)))
		ret += A[i];
	return ret;
}

void Add(int a, int b, int A[])
{
	for (int i = a; i <= n; i += (i & (0 - i)))
		B[i] = b;
}

int Ask(int a, int A[])
{
	int ret = 0, i;
	for (i = a; i > 0; i -= (i & (0 - i)))
		ret = max(ret, A[i]);
	return ret;
}

int Ask2(int a, int A[])
{
	int ret = n, i;
	for (i = a; i > 0; i -= (i & (0 - i)))
		ret = min(ret, A[i]);
	return ret;
}