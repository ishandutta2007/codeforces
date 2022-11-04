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

const int mo = 1000000007;

const int N = 2005;

int n, h, a[N];

int main() {
	scanf("%d %d", &n, &h);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int ans = 1, now = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > h) {
			printf("0\n");
			return 0;
		}
		
		if (i > 1) {
			now = h - a[i - 1];
		}
		
		if (h - a[i] == now - 1) {
			ans = (long long)ans * now % mo;
		} else if (h - a[i] == now) {
			ans = (long long)ans * (now + 1) % mo;
		} else if (h - a[i] == now + 1) {
			continue;
		} else {
			printf("0\n");
			return 0;
		}
	}
	
	now = h - a[n];
	if (now > 1) {
		ans = 0;
	}
	
	printf("%d\n", ans);
	return 0;
}