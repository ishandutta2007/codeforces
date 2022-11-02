#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <string>
#include <map>
using namespace std;
const int MAX_N = 15, INF = ~0U >> 3;
int n;
string a[MAX_N];
map<string, int> id;
int bitcnt[1 << MAX_N];
const int MAX_LEN = int(5e5) + 10;

int work() {
	int k;
	cin >> k;
	static int dp[1 << MAX_N][MAX_N * (MAX_N - 1) / 2 + 1];
	static int nxt[MAX_LEN][MAX_N];
	fill(dp[0], dp[1 << n], INF);
	int cnt = 0;
	memset(nxt, -1, sizeof nxt);
	for (int i = 0; i < k; ++i) {
		static char buf[MAX_LEN + 10];
		scanf(" ");
		scanf("%s", buf);
		if (id.count(buf)) {
			nxt[cnt][id[buf]] = cnt;
			++cnt;
		}
	}
	for (int i = cnt - 2; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			if (nxt[i][j] == -1)
				nxt[i][j] = nxt[i + 1][j];
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j <= n * (n - 1) / 2; ++j) {
			int c = dp[i][j];
			if (c == INF)
				continue;
			for (int k = 0; k < n; ++k) {
				if (~i >> k & 1) {
					int nc = nxt[c][k];
					if (nc != -1) {
						dp[i | (1 << k)][j + (bitcnt[i >> k])] = min(dp[i | (1 << k)][j + (bitcnt[i >> k])], nc);
					}
				}
			}
		}
	}
	for (int i = 0; i <= n * (n - 1) / 2; ++i) {
		if (dp[(1 << n) - 1][i] != INF)
			return n * (n - 1) / 2 - i + 1;
	}
	return -1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		id[a[i]] = i;
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			bitcnt[i] += (i >> j & 1);
		}
	}
	int m;
	cin >> m;
	int ans = -1;
	int who;
	for (int i = 0; i < m; ++i) {
		int cur = work();
		if (cur > ans) {
			ans = cur;
			who = i;
		}
	}
	if (ans == -1) {
		puts("Brand new problem!");
		return 0;
	}
	printf("%d\n", who + 1);
	printf("[:");
	for (int j = 0; j < ans; ++j) {
		printf("|");
	}
	printf(":]");
	puts("");
	return 0;
}