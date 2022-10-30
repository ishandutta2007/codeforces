/*
 * E. Lucky Country.cpp
 *
 *  Created on: 2011-7-23
 *      Author: mac
 */

#include <climits>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = int(1e5) + 10;
int father[MAX_N], size[MAX_N], cnt[MAX_N];
int dp[MAX_N];

int find(int x) {
	return x == father[x] ? x : father[x] = find(father[x]);
}

bool isLucky(int x) {
	for (; x; x /= 10)
		if (x % 10 != 4 && x % 10 != 7)
			return false;
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		father[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		father[find(a)] = find(b);
	}
	for (int i = 1; i <= n; ++i) {
		size[find(i)]++;
	}
	for (int i = 1; i <= n; ++i) {
		cnt[size[i]]++;
	}
	fill(dp + 1, dp + n + 1, INT_MAX / 2);
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] > 0) {
			int num = cnt[i];
			for (int p = 1; num > 0; p <<= 1) {
				p = min(p, num);
				num -= p;
				int w = p * i;
				for (int j = n - w; j >= 0; --j) {
					dp[j + w] = min(dp[j + w], dp[j] + p);
				}
			}
		}
	}
	int ans = INT_MAX / 2;
	for (int i = 1; i <= n; ++i)
		if (isLucky(i)) {
			ans = min(ans, dp[i]);
		}
	if (ans == INT_MAX / 2)
		ans = -1;
	else
		--ans;
	cout << ans << endl;
	return 0;
}