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
int l[N], r[N];
int n, ll, rr;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}
	
	ll = l[1], rr = r[1];
	for (int i = 2; i <= n; i++) {
		ll = min(ll, l[i]);
		rr = max(rr, r[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		if (l[i] == ll && r[i] == rr) {
			printf("%d\n", i);
			return 0;
		}
	}
	
	printf("-1\n");
	return 0;
}