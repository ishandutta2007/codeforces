/*
 * d.cpp
 *
 *  Created on: 2012-3-12
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <map>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

bool contain(int l, int r, int mid) {
	return l <= mid && mid <= r;
}

void shift(int&l, int&r) {
	for (int i = 30; i >= 0; --i) {
		int mid = 1 << i;
		if (contain(l, r, mid)) {
			return;
		}
		if (l >= mid)
			l -= mid;
		if (r >= mid)
			r -= mid;
	}
}

map<pair<pair<int, int> ,pair<int, int> > ,int> memo[31];

int solve(int l, int r, int L, int R, int pw) {
	if (l > r || L > R)
		return 0;
	shift(l, r);
	shift(L, R);

	if (pw == 1) {
		return 1;
	}

	int is = min(r, R) - max(l, L) + 1;
	int mx = min(r - l + 1, R - L + 1);
	if (is == mx)
		return is;

	pair<int, int> a = make_pair(l, r), b = make_pair(L, R);
	pair<pair<int, int> ,pair<int, int> > key = make_pair(a, b);
	if (memo[pw].count(key))
		return memo[pw][key];

	int&ret = memo[pw][key] = 0;

	int mid = 1 << (pw - 1);
	if (!contain(l, r, mid)) {
		if (!contain(L, R, mid)) {
			return ret = solve(l, r, L, R, pw - 1);
		} else {
			return ret = max(solve(l, r, L, mid - 1, pw - 1), solve(l, r, mid + 1, R, pw - 1));
		}
	} else {
		if (!contain(L, R, mid)) {
			return ret = max(solve(l, mid - 1, L, R, pw - 1), solve(mid + 1, r, L, R, pw - 1));
		} else {
			ret = min(r, R) - max(L, l) + 1;
			ret = max(ret, solve(l, mid - 1, L, mid - 1, pw - 1));
			ret = max(ret, solve(l, mid - 1, mid + 1, R, pw - 1));
			ret = max(ret, solve(mid + 1, r, L, mid - 1, pw - 1));
			ret = max(ret, solve(mid + 1, r, mid + 1, R, pw - 1));
			return ret;
		}
	}
}

int main() {
	int l, r, L, R;
	cin >> l >> r >> L >> R;
	cout << solve(l, r, L, R, 30) << endl;
	return 0;
}