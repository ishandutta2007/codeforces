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

using namespace std;

const int mo = 1000000007;

const int N = 200005;

int f[N][16], g[N][16], n;
char str[N], a[N], now[N];
string b[N];

int main() {
	scanf("%s", str + 1);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", now);
		a[i] = now[0];
		b[i] = "";
		for (int j = 3; now[j]; j++) {
			b[i] += now[j];
		}
	}
	
	for (int i = 0; i <= 9; i++) {
		f[n + 1][i] = i;
		g[n + 1][i] = 10;
	}
	
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= 9; j++) {
			f[i][j] = f[i + 1][j];
			g[i][j] = g[i + 1][j];
		}
		
		int now = a[i] - '0';
		f[i][now] = 0;
		g[i][now] = 1;
		for (int j = 0; j < (int)b[i].size(); j++) {
			int x = b[i][j] - '0';
			f[i][now] = ((long long)f[i][now] * g[i + 1][x] % mo + f[i + 1][x]) % mo;
			g[i][now] = ((long long)g[i][now] * g[i + 1][x] %mo);
		}
	}
	
	int ans = 0;
	for (int i = 1; str[i]; i++) {
		int now = str[i] - '0';
		ans = ((long long)ans * g[1][now] % mo + f[1][now]) % mo;
	}
	
	printf("%d\n", ans);
	return 0;
}