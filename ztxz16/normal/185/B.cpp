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

int s, a, b, c;

int main() {
	scanf("%d %d %d %d", &s, &a, &b, &c);
	if (a + b + c == 0) {
		printf("%d %d %d\n", a, b, c);
	} else {
		double ss = a + b + c;
		printf("%.20f %.20f %.20f\n", (double)a / ss * s, (double)b / ss * s, (double)c / ss * s);
	}
	
	return 0;
}