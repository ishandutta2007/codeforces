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

const int MAX = 1000000;

int isNot[MAX + 5];
int n;

int main() {
	isNot[1] = 1;
	for (int i = 2; i * i <= MAX; i++) {
		if (isNot[i]) {
			continue;
		}
		
		for (int j = i * i; j <= MAX; j += i) {
			isNot[j] = 1;
		}
	}
	
	scanf("%d", &n);
	for (int i = 4; i <= n; i++) {
		if (isNot[i] && isNot[n - i]) {
			printf("%d %d\n", i, n - i);
			return 0;
		}
	}
	
	return 0;
}