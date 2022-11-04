#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

const double PI = acos(-1.0);
const int N = 100005;

int n;
double a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		double x, y;
		scanf("%lf %lf", &x, &y);
		a[i] = atan2(y, x);
	}
	
	sort(a + 1, a + n + 1);
	double ans = PI * 2;
	for (int i = 1; i < n; i++) {
		ans = min(ans, PI * 2.0 - (a[i + 1] - a[i]));
	}
	
	ans = min(ans, PI * 2.0 - (a[1] + PI * 2.0 - a[n]));
	printf("%.12f\n", ans / PI * 180.0);
	return 0;
}