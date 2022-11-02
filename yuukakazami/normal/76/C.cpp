#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_N = 200000 + 10;
const int MAX_K = 22;

ll dp[1 << MAX_K];

int n, k, t;
char a[MAX_N];

int cst[MAX_K][MAX_K], del[MAX_K];

int mask[MAX_K];

int main() {
	cin >> n >> k >> t;
	scanf("%s", a);
	for (int i = 0; i < k; ++i) {
		cin >> del[i];
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> cst[i][j];
		}
	}
	memset(mask, -1, sizeof mask);
	for (int i = 0; i < n; ++i) {
		int me = a[i] - 'A';
		for (int j = 0; j < k; ++j) {
			if (mask[j] != -1) {
				int mid = mask[j], c = cst[j][me];
				dp[mid] += c;
				dp[mid | (1 << me)] -= c;
				dp[mid | (1 << j)] -= c;
				dp[mid | (1 << me) | (1 << j)] += c;

				mask[j] |= 1 << me;
			}
		}
		mask[me] = 0;
	}
	for (int i = 0; i < k; ++i) {
		dp[1 << i] += del[i];
	}

	int have = 0;
	for (int i = 0; i < n; ++i) {
		have |= 1 << (a[i] - 'A');
	}

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < 1 << k; ++j) {
			if (~j >> i & 1)
				dp[j | (1 << i)] += dp[j];
		}
	}

	int ans = 0;
	for (int i = 0; i < 1 << k; ++i) {
		if ((i & have) == i && dp[i] <= t)
			++ans;
	}
	cout << ans - 1 << endl;

	return 0;
}