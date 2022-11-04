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

int n, m, a, b, ans;

int main() {
	scanf("%d %d %d %d", &n, &m, &a, &b);
	ans = OO;
	for (int i = 0; i <= n; i++) {
		ans = min(ans, i * b + a * max(0, (n - m * i)));
		if (m * i >= n) {
			break;
		}
	}

	printf("%d\n", ans);
	return 0;
}