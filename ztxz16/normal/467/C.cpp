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

const int N = 5005;
const long long INF = (1LL << 60);

int n, m, k, p[N];
long long s[N], f[N][N];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		s[i] = s[i - 1] + p[i];
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			f[i][j] = -INF;
		}
	}
	
	f[m][1] = s[m];
	for (int i = m + 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			f[i][j] = max(f[i - 1][j], f[i - m][j - 1] + s[i] - s[i - m]);
		}
	}
	
	cout << f[n][k] << endl;
	return 0;
}