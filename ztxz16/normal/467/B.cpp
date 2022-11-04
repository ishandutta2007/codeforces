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

int n, m, k, ans, x[2005];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m + 1; i++) {
		scanf("%d", &x[i]);
	}
	
	for (int i = 1; i <= m; i++) {
		int now = x[i] ^ x[m + 1], s = 0;
		for (; now; now -= (now & -now)) {
			s++;
		}
		
		if (s <= k) {
			ans++;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}