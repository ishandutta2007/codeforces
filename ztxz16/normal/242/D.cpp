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

int FASTBUFFER;

const int N = 100005;

int n, m, tot, ans[N], now[N], q[N];
int e[N << 1], succ[N << 1], last[N], sum;
int v[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	int h = 1, t = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		if (!v[i]) {
			q[++t] = i;
		}
	}
	
	for (; h <= t; h++) {
		int d = q[h];
		if (now[d] == v[d]) {
			ans[++tot] = d;
			for (int x = last[d]; x; x = succ[x]) {
				now[e[x]]++;
				if (now[e[x]] == v[e[x]]) {
					q[++t] = e[x];
				}
			}
		}
	}
	
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) {
		printf("%d ", ans[i]);
	}
	
	printf("\n");
	return 0;
}