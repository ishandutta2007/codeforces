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

int n, a[N], rev[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int s = a[n];
	for (int i = n - 1; i >= 1; i--) {
		if (s < a[i]) {
			rev[i] = 1;
			s = a[i] - s;
		} else {
			s -= a[i];
		}
	}
	
	int now = 0;
	for (int i = 1; i <= n; i++) {
		now ^= rev[i];
		now ^= (i == n);
		printf("%c", now ? '+' : '-');
	}
	
	return 0;
}