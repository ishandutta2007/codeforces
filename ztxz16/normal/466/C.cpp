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

const int N = 500005;

int n, a[N], f[N];
long long s[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	
	if (s[n] % 3) {
		printf("0\n");
		return 0;
	}
	
	long long x = s[n] / 3;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if (s[i] == x) {
			f[i]++;
		}
	}
	
	long long ans = 0;
	for (int i = n; i >= 2; i--) {
		if (s[n] - s[i - 1] == x) {
			ans += f[i - 2];
		}
	}
	
	cout << ans << endl;
	return 0;
}