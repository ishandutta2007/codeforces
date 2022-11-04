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

long long n, m, k;

int ok(long long x) {
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		long long temp = x / i;
		if (temp * i == x) {
			s += min(temp - 1, m);
		} else {
			s += min(temp, m);
		}
	}
	
	if (s < k) {
		return 1;
	}
	
	return 0;
}

int main()
{
	cin >> n >> m >> k;
	long long l = 1, r = n * m;
	while (l < r) {
		long long mid = (l + r + 1) >> 1;
		if (ok(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	
	cout << l << endl;
	return 0;
}