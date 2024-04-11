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

const int N = 200005;

int n, l, x, y;
int a[N];
set <int> s;

int ok(int now) {
	if (now >= 0 && now <= l && (s.find(now - y) != s.end() || s.find(now + y) != s.end())) {
		return 1;
	}
	
	return 0;
}

int main() {
	scanf("%d %d %d %d", &n, &l, &x, &y);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}
	
	int tag1 = 0, tag2 = 0;
	for (int i = 1; i <= n; i++) {
		if (s.find(a[i] - x) != s.end() || s.find(a[i] + x) != s.end()) {
			tag1 = 1;
		}
		
		if (s.find(a[i] - y) != s.end() || s.find(a[i] + y) != s.end()) {
			tag2 = 1;
		}
	}
	
	if (tag1 && tag2) {
		printf("0\n");
		return 0;
	}
	
	if (tag1 || tag2) {
		if (tag1) {
			printf("1\n%d\n", y);
		} else {
			printf("1\n%d\n", x);
		}
		
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		int now = a[i];
		if (ok(now + x)) {
			printf("1\n%d\n", now + x);
			return 0;
		}
		
		if (ok(now - x)) {
			printf("1\n%d\n", now - x);
			return 0;
		}
	}
	
	printf("2\n%d %d\n", x, y);
	return 0;
}