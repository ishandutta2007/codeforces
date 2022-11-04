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
const int N = 5005;

int n, a, b, k;
int f[N][N], s[N];

int main() {
	scanf("%d %d %d %d", &n, &a, &b, &k);
	f[0][a] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			s[j] = (s[j - 1] + f[i - 1][j]) % mo;
		}
		
		if (a > b) {
			int l, r = n;
			for (int j = b + 1; j <= n; j++) {
				l = j - (j - b + 1) / 2 + 1;
				f[i][j] = (s[r] - s[l - 1] + mo) % mo;
				f[i][j] = (f[i][j] - f[i - 1][j] + mo) % mo;
			}
		} else {
			int l = 1, r;
			for (int j = b - 1; j >= 1; j--) {
				r = j + (b - j + 1) / 2 - 1;
				f[i][j] = (s[r] - s[l - 1] + mo) % mo;
				f[i][j] = (f[i][j] - f[i - 1][j] + mo) % mo;
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		(ans += f[k][i]) %= mo;
	}
	
	printf("%d\n", ans);
	return 0;
}