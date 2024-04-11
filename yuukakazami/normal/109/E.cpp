/*
 * E. Lucky Interval.cpp
 *
 *  Created on: 2011-9-1
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long int64;

inline int isLucky(int x) {
	return x == 4 || x == 7;
}

int countLucky(int64 x) {
	int ret = 0;
	while (x) {
		int d = x % 10;
		ret += isLucky(d);
		x /= 10;
	}
	return ret;
}

int getLen(int64 x) {
	int l = 0;
	while (x)
		x /= 10, l++;
	return l;
}

bool check(int64 cur, int cnt, int rest, int64 suffix, int64 suffixPow, int64 min) {
	if (cnt < 0 || cnt > rest)
		return false;
	for (int j = 0; j < rest - cnt; ++j) {
		cur = cur * 10 + 9;
	}
	for (int j = 0; j < cnt; ++j) {
		cur = cur * 10 + 7;
	}
	cur = cur * suffixPow + suffix;
	return cur > min;
}

int64 buildMin(int cnt, int64 suffix, int suffixLen, int64 min) {
	int64 suffixPow = 1;
	for (int j = 0; j < suffixLen; ++j) {
		suffixPow *= 10;
	}
	int cntCopy = cnt;
	for (int len = 0;; ++len) {
		int64 cur = 0;
		cnt = cntCopy;
		if (!check(cur, cnt, len, suffix, suffixPow, min))
			continue;
		for (int j = 0; j < len; ++j) {
			for (int digit = 0; digit < 10; ++digit) {
				int ncnt = cnt - isLucky(digit);
				int64 ncur = cur * 10 + digit;
				if (check(ncur, ncnt, len - 1 - j, suffix, suffixPow, min)) {
					cur = ncur, cnt = ncnt;
					break;
				}
			}
		}
		return cur * suffixPow + suffix;
	}
	return -1;
}

int64 doit(int64 a, int64 b) {
	int64 l = b - a + 1;
	if (l >= 10)
		return doit(a / 10, b / 10) * 10 + a % 10;
	int cnt[10] = { };
	for (int i = 0; i < l; ++i) {
		cnt[i] = countLucky(a + i);
	}
	for (int i = a + 1; i < 10000; ++i) {
		bool check = true;
		for (int j = 0; j < l; ++j) {
			if (countLucky(i + j) != cnt[j]) {
				check = false;
				break;
			}
		}
		if (check)
			return i;
	}
	//ans = ~~~~x99999yz
	int64 ans = LONG_LONG_MAX;
	for (int y = 0; y < 10; ++y) {
		for (int z = 0; z < 10; ++z) {
			for (int n9 = 0; n9 < 15; ++n9) {
				for (int x = 0; x < 9; ++x) {
					int num = isLucky(x) + isLucky(y) + isLucky(z);
					int need = cnt[0] - num;
					if (need < 0)
						continue;
					int64 suffix = x;
					for (int j = 0; j < n9; ++j) {
						suffix = suffix * 10 + 9;
					}
					suffix = suffix * 10 + y;
					suffix = suffix * 10 + z;
					int suffixLen = 3 + n9;
					bool check = true;
					for (int j = 0; j < l; ++j) {
						int me = need + countLucky(suffix + j);
						if (me != cnt[j]) {
							check = false;
							break;
						}
					}
					if (!check)
						continue;
					if (buildMin(need, suffix, suffixLen, a) < a) {
						cout << need << " " << suffix << " " << suffixLen << endl;
					}
					ans = min(ans, buildMin(need, suffix, suffixLen, a));
				}
			}
		}
	}
	return ans;
}

int main() {
	int64 a, l;
	cin >> a >> l;
	cout << doit(a, a + l - 1) << endl;
	return 0;
}