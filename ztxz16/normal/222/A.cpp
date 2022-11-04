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

const int N = 100005;

int n, k, sel, a[N];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);	
	}
	
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] != a[n]) {
			sel = i;
			break;
		}
	}

	if (sel == 0) {
		printf("%d\n", 0);
	} else {
		if (sel >= k) {
			printf("-1\n");
		} else {
			printf("%d\n", sel);
		}
	}
	
	return 0;
}