#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int k, n, maxb, t;
const int MAX_N = 100000 + 10;
int b[MAX_N];

int a[MAX_N];

void update(register int p, register int x) {
	for (p++; p <= maxb; p += p & -p)
		if (x > a[p - 1])
			a[p - 1] = x;
}

int get(register int p) {
	register int r = 0;
	for (p++; p > 0; p -= p & -p)
		if (a[p - 1] > r)
			r = a[p - 1];
	return r;
}

int ans[MAX_N];

void work() {
	if (t >= maxb) {
		sort(b, b + n);
		cout << unique(b, b + n) - b << endl;
		return;
	}
	//t < maxb
	memset(a, 0, sizeof a);
	memset(ans, 0, sizeof ans);
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < n; ++j) {
			int x = get(b[j] - 1) + 1;
			if (x > ans[j]) {
				ans[j] = x;
				update(b[j], x);
			}
		}
	}
	cout << *max_element(ans, ans + n) << endl;
}

int main() {
	cin >> k >> n >> maxb >> t;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", b + j);
			--b[j];
		}
		work();
	}
	return 0;
}