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

vector <pair <int, int> > a;

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a.push_back(make_pair(x, y));
	}
	
	sort(a.begin(), a.end());
	int last = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].second >= last) {
			last = a[i].second;
		} else {
			last = a[i].first;
		}
	}
	
	printf("%d\n", last);
	return 0;
}