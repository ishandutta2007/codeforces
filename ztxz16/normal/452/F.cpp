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
#define left LEFT
#define right RIGHT

int FASTBUFFER;

using namespace std;

const int N = 300005;
const int base = 131;

int n;
long long mi[N];
long long ans, temp;

struct seg {
	int left[N * 4], right[N * 4];
	long long hash[N * 4];
	
	void make(int l, int r, int i) {
		int mid = (l + r) >> 1;
		left[i] = l, right[i] = r;
		hash[i] = 0;
		if (l == r) {
			return;
		}
		
		make(l, mid, (i << 1));
		make(mid + 1, r, (i << 1) | 1);
	}
	
	void add(int l, int r, int i) {
		if (l > right[i] || r < left[i]) {
			return;
		}
		
		hash[i] += mi[right[i] - l + 1];
		if (l <= left[i] && r >= right[i]) {
			return;
		}
		
		add(l, r, (i << 1));
		add(l, r, ((i << 1) | 1));
	}
	
	void ask(int l, int r, int i) {
		if (l > right[i] || r < left[i]) {
			return;
		}
		
		if (l <= left[i] && r >= right[i]) {
			ans = ans * mi[right[i] - left[i] + 1] + hash[i];
			return;
		}
		
		ask(l, r, (i << 1));
		ask(l, r, ((i << 1) | 1));
	}
} A, B;

int main() {
	mi[0] = 1;
	for (int i = 1; i <= 300000; i++) {
		mi[i] = mi[i - 1] * base;
	}
	
	scanf("%d", &n);
	A.make(1, n, 1);
	B.make(1, n, 1);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		int y = min(x - 1, n - x);
		ans = 0;
		A.ask(x - y, x - 1, 1);
		temp = ans, ans = 0;
		B.ask(n - x - y + 1, n - x, 1);
		if (temp != ans) {
			printf("YES\n");
			return 0;
		}
			
		A.add(x, x, 1);
		B.add(n - x + 1, n - x + 1, 1);
	}
	
	printf("NO\n");
	return 0;
}