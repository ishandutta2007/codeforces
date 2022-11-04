#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int x, y, a, b;
vector <pair <int, int> > v;

int main() {
	scanf("%d %d %d %d", &x, &y, &a, &b);
	for (int i = a; i <= x; i++) {
		for (int j = b; j <= y; j++) {
			if (i > j) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	
	sort(v.begin(), v.end());
	printf("%d\n", (int)v.size());
	for (int i = 0; i < (int)v.size(); i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	
	return 0;
}