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

int n, m, s;
long double f[1000005];

long double C(int n, int m) {
	return f[n] / f[m] / f[n - m];
}

int main() {
	f[0] = 1.0;
	for (int i = 1; i <= 1000000; i++) {
		f[i] = f[i - 1] * (long double)i;
	}
	
	scanf("%d %d", &n, &m);
	if (n == 1) {
		printf("%.12f\n", 1.0);
		return 0;
	}
	
	s = n * m;
	//long double ans = ((long double)s * C(s - 1, n - 1) + (long double)n * (long double)m * (long double)(m - 1) * C(s - 2, n - 2)) / C(s, n) / (long double)n / (long double)n;
	long double ans = (long double)1.0 / (long double)n + (long double)m * (long double)(m - 1) * (long double)(n - 1) / (long double)s / (long double)(s - 1);
	printf("%.12f\n", (double)ans);
	return 0;
}