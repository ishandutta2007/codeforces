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

int n;
int a[5005];

int dfs(int l, int r, int x) {
	int now = a[l], ans = r - l + 1;
	if (l == r) {
		return 1;
	}
	
	for (int i = l; i <= r; i++) {
		now = min(now, a[i]);
	}
	
	int s = now - x, last = l - 1;
	for (int i = l; i <= r; i++) {
		if (a[i] == now) {
			if (last != i - 1) {
				s += dfs(last + 1, i - 1, now);
			}
			
			last = i;
		}
	}
	
	if (last != r) {
		s += dfs(last + 1, r, now);
	}
	
	return min(ans, s);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]);
	}
	
	printf("%d\n", dfs(1, n, 0));
	return 0;
}