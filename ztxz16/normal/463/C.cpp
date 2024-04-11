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

const int N = 2005;

long long n, a[N][N], ans[2], ansx[2], ansy[2];
long long v1[N << 2], v2[N << 2];

int main() {
	scanf("%I64d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%I64d", &a[i][j]);
			v1[i + j] += a[i][j];
			v2[i - j + 2000] += a[i][j];
		}
	}
	
	ans[0] = ans[1] = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = i + j & 1;
			long long s = v1[i + j] + v2[i - j + 2000] - a[i][j];
			if (s > ans[x]) {
				ans[x] = s;
				ansx[x] = i;
				ansy[x] = j;	
			}
		}
	}
	
	printf("%I64d\n", ans[0] + ans[1]);
	printf("%I64d %I64d %I64d %I64d\n", ansx[0], ansy[0], ansx[1], ansy[1]);
	return 0;
}