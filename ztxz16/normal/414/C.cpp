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

using namespace std;

struct x
{	
	struct Node
	{
		int val, *pos;
		
		friend bool operator < (Node a, Node b)
		{
			return a.val < b.val;
		}
	}px[2000005];
	
	int tot;
	
	x ()
	{
		tot = 0;
	}
	
	void Push(int val, int *pos)
	{
		px[++tot].val = val;
		px[tot].pos = pos;
	}
	
	int Run()
	{
		int Now = 0, i;
		sort(px + 1, px + tot + 1);
		for (i = 1; i <= tot; i++)
		{
			if (i == 1 || px[i].val != px[i - 1].val)
				Now++;
			*px[i].pos = Now;
		}
		
		return Now;
	}
}lsh;

void Add(int a, int b);
long long Ask(int a);

int n, i, len, x, j, k, ceng, m, q, a[2000005];
long long ans, f[30][5], A[2000005];

int main()
{
	scanf("%d", &n);
	len = (1 << n);
	for (i = 1; i <= len; i++)
		scanf("%d", &a[i]), lsh.Push(a[i], &a[i]);
	lsh.Run();
	for (x = 1, ceng = 1; x < len; x += x, ceng++)
	{
		for (j = 1; j <= len; j += (x + x))
		{
			for (k = j; k <= j + x - 1; k++)
				Add(a[k], 1);
			for (k = j + x; k <= j + x + x - 1; k++)
			{
				f[ceng][1] += Ask(a[k] - 1);
				f[ceng][2] += Ask(len) - Ask(a[k]);
			}
			
			for (k = j; k <= j + x - 1; k++)
				Add(a[k], -1);
		}	
	}
	
	for (i = 1; i <= ceng; i++)
		ans += f[i][2];
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &q);
		for (j = q; j >= 1; j--)
			ans -= f[j][2], ans += f[j][1], swap(f[j][1], f[j][2]);
		printf("%I64d\n", ans);
	}
	
	return 0;
}

void Add(int a, int b)
{
	for (int i = a; i <= len; i += (i & (0 - i)))
		A[i] += b;
}

long long Ask(int a)
{
	long long ret = 0;
	for (int i = a; i > 0; i -= (i & (0 - i)))
		ret += A[i];
	return ret;
}