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

int n, m, k, a[55];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	if (k >= m) {
		printf("0\n");
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		k += (a[i] - 1);
		if (k >= m) {
			printf("%d\n", i);
			return 0;
		}
	}
	
	printf("-1\n");
	return 0;
}