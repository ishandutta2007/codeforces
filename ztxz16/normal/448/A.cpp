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

int a1, a2, a3, b1, b2, b3, n;

int main() {
	scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &b1, &b2, &b3);
	scanf("%d", &n);
	if ((a1 + a2 + a3) / 5 + ((a1 + a2 + a3) % 5 > 0) + (b1 + b2 + b3) / 10 + ((b1 + b2 + b3) % 10 > 0) <= n) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}