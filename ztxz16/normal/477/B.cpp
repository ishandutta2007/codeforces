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

int a[10005][5];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	a[1][1] = 1, a[1][2] = 2, a[1][3] = 3, a[1][4] = 5;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 4; j++) {
			a[i][j] = a[i - 1][j] + 6;
		}
	}
	
	printf("%d\n", a[n][4] * k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 4; j++) {
			printf("%d ", a[i][j] * k);
		}
		
		printf("\n");
	}
	
	return 0;
}