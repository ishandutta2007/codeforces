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

const int N = 1000005;

int n, tot, i, a[N], b[N], A[N], s1[N], s2[N], f[N], g[N];
long long ans;

void add(int a) {
	for (int i = a; i <= n; i += (i & -i)) {
		A[i]++;
	}
}

int ask(int a) {
	int ret = 0;
	for (int i = a; i; i -= (i & -i)) {
		ret += A[i];
	}
	
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	
	sort(b + 1, b + n + 1);
	tot = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++) {
		int now = lower_bound(b + 1, b + tot + 1, a[i]) - b;
		s1[now]++;
		f[i] = s1[now];
	}
	
	for (int i = n; i >= 1; i--) {
		int now = lower_bound(b + 1, b + tot + 1, a[i]) - b;
		s2[now]++;
		g[i] = s2[now];
	}
	
	for (int i = n; i >= 1; i--) {
		ans += ask(f[i] - 1);
		add(g[i]);
	}
	
	cout << ans << endl;
	return 0;
}