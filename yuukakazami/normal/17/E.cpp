/*
 * cd.cpp
 *
 *  Created on: 2012-11-8
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

void palindrome(char cs[], int len[], int n) { //len[i] means the max palindrome length centered i/2
	for (int i = 0; i < n * 2; ++i) {
		len[i] = 0;
	}
	for (int i = 0, j = 0, k; i < n * 2; i += k, j = max(j - k, 0)) {
		while (i - j >= 0 && i + j + 1 < n * 2 && cs[(i - j) / 2] == cs[(i + j + 1) / 2])
			j++;
		len[i] = j;
		for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] != j - k; k++) {
			len[i + k] = min(len[i - k], j - k);
		}
	}
}

const int MAX_N = int(2e6) + 10;
int n;

const int MOD = 51123987;
char buf[MAX_N];
int len[MAX_N * 2];
int sL[MAX_N], sR[MAX_N];

int main() {
	cin >> n;
	scanf("%s", buf);
	palindrome(buf, len, n);
	for (int i = 0; i < 2 * n; ++i) {
		if (i % 2 == 0) {
			int a = (len[i] + 1) / 2;
			int x = i / 2;
			sL[x - a + 1] += 1, sL[x + 1] -= 1;
			sR[x] += 1, sR[x + a] -= 1;
		} else {
			int x = i / 2, y = i / 2 + 1;
			int a = len[i] / 2;
			sL[x - a + 1] += 1, sL[x + 1] -= 1;
			sR[y] += 1, sR[y + a] -= 1;
		}
	}
	for (int i = 0; i <= n; ++i) {
		sL[i] += sL[i - 1];
		sR[i] += sR[i - 1];
	}
	long long tot = accumulate(sL, sL + n, 0LL) % MOD;
	long long ans = 0;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		ans += sum * sL[i];
		ans %= MOD;
		sum += sR[i];
	}
	ans = tot * (tot - 1) / 2 - ans;
	ans %= MOD;
	if (ans < 0)
		ans += MOD;
	cout << ans << endl;
	return 0;
}