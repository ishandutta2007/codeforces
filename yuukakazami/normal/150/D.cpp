/*
 * d.cpp
 *
 *  Created on: 2012-2-17
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <cassert>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 150 + 10;
int memoCalc[MAX_N][MAX_N][MAX_N];
int memoCalcL[MAX_N][MAX_N][MAX_N];
char str[MAX_N];
int n;
int v[MAX_N];
const int INF = ~0U >> 3;

int memo[MAX_N][MAX_N];
bool chk[MAX_N][MAX_N];

int calc(int, int, int);
int calc(int, int);
int calcL(int, int, int);

int calc(int l, int r) {
	int&ret = memo[l][r];
	if (l > r)
		return 0;
	if (ret != -1)
		return ret;
	ret = 0;
	if (chk[l][r])
		ret = max(ret, v[r - l + 1]);
	for (int k = l; k < r; ++k) {
		ret = max(ret, calc(l, k) + calc(k + 1, r));
	}
	if (str[l] == str[r] && l < r)
		ret = max(ret, calc(l, r, 2));
	return ret;
}

int memoMust[MAX_N][MAX_N];

int must(int l, int r) {
	int&ret = memoMust[l][r];
	if (l > r)
		return 0;
	if (ret != -1)
		return ret;
	ret = -INF;
	if (chk[l][r])
		ret = max(ret, v[r - l + 1]);
	for (int k = l; k < r; ++k) {
		ret = max(ret, must(l, k) + must(k + 1, r));
	}
	if (str[l] == str[r] && l < r)
		ret = max(ret, calc(l, r, 2));
	return ret;
}

int calc(int l, int r, int cnt) {
	assert(cnt>0 && str[l]==str[r]);
	int&ret = memoCalc[l][r][cnt];
	if (ret != -1)
		return ret;
	ret = -INF;
	if (l > r)
		return ret = v[cnt];
	ret = max(ret, v[cnt] + must(l + 1, r - 1));
	for (int k = l + 1; k < r; ++k) {
		ret = max(ret, must(l + 1, k - 1) + calcL(k, r, cnt));
		ret = max(ret, must(l + 1, k - 1) + must(k + 1, r - 1) + v[cnt + 1]);
	}
	return ret;
}

int calcL(int l, int r, int cnt) {
	int&ret = memoCalcL[l][r][cnt];
	if (ret != -1)
		return ret;
	if (l > r)
		return ret = -INF;
	ret = -INF;
	for (int k = r - 1; k > l; --k) {
		if (str[l] == str[k])
			ret = max(ret, calc(l, k, cnt + 2) + must(k + 1, r - 1));
	}
	return ret;
}

int main() {
	cin >> n;
	v[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		if (v[i] == -1)
			v[i] = -INF;
	}
	scanf("%s", str);
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			chk[i][j] = true;
			for (int l = i, r = j; l <= r; l++, r--)
				if (str[l] != str[r])
					chk[i][j] = false;
		}
	}
	memset(memo, -1, sizeof memo);
	memset(memoCalc, -1, sizeof memoCalc);
	memset(memoCalcL, -1, sizeof memoCalcL);
	memset(memoMust, -1, sizeof memoMust);
	cout << calc(0, n - 1) << endl;
	return 0;
}