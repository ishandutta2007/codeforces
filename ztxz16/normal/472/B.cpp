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

int n, k, f[2005], dp[2005];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
		f[i]--;
	}
	
	sort(f + 1, f + n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + (f[i] << 1);
		for (int j = 0; j < i; j++) {
			if (i - j <= k) {
				dp[i] = min(dp[i], dp[j] + (f[i] << 1));
			}
		}
	}
	
	printf("%d\n", dp[n]);
	return 0;
}