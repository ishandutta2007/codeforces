/*
 * D. Horse Races.cpp
 *
 *  Created on: 2011-7-23
 *      Author: mac
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MOD = int(1e9) + 7;
const int MAX_LEN = 1000 + 10;
typedef long long int64;

int cnt[MAX_LEN][MAX_LEN], t, k;

int64 evalAll(const string&s) {
	int64 ret = 0;
	for (int i = 0; i < s.length(); ++i) {
		(ret = ret * 10 + s[i] - '0') %= MOD;
	}
	return ret;
}

int64 evalBad(const string&s, bool inclusive) {
	int64 ret = 0;
	int need = 0;
	for (int diffAt = 0; diffAt < s.length(); ++diffAt) {
		int maxDigit = s[diffAt] - '0';
		for (int digit = 0; digit <= maxDigit; ++digit) {
			int nNeed;
			if (digit == 4 || digit == 7) {
				if (need > 0)
					nNeed = -1;
				else
					nNeed = k;
			} else {
				nNeed = max(0, need - 1);
			}
			if (digit < maxDigit) {
				if (nNeed >= 0)
					(ret += cnt[s.length() - diffAt - 1][nNeed]) %= MOD;
			} else {
				if (nNeed == -1)
					return ret;
				need = nNeed;
			}
		}
	}
	if (inclusive)
		(++ret) %= MOD;
	return ret;
}

int main() {
	cin >> t >> k;
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i <= k; ++i) {
		cnt[0][i] = 1;
	}
	for (int len = 1; len < MAX_LEN; ++len) {
		for (int i = 1; i <= k; ++i) {
			cnt[len][i] = 8LL * cnt[len - 1][i - 1] % MOD;
		}
		cnt[len][0] = (8LL * cnt[len - 1][0] + 2LL * cnt[len - 1][k]) % MOD;
	}
	for (int i = 0; i < t; ++i) {
		string left, right;
		cin >> left >> right;
		int64 total = evalAll(right) - evalAll(left) + 1;
		int64 bad = evalBad(right, true) - evalBad(left, false);
		int64 ans = total - bad;
		ans = (ans % MOD + MOD) % MOD;
		cout << ans << endl;
	}
	return 0;
}