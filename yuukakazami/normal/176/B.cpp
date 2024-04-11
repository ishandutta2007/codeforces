/*
 * b.cpp
 *
 *  Created on: 2012-4-20
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MOD = 1000000007;
typedef long long int64;

string start, target;
const int MAX_N = 1000 + 10;

int n, k;

string rs[MAX_N];

const int64 LIMIT = LONG_LONG_MAX / 4;

vector<int64> merge(vector<int64> a, vector<int64> b) {
	vector<int64> ret(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int t = i + j;
			if (t >= n)
				t -= n;
			ret[t] += a[i] * b[j];
			if (ret[t] > LIMIT)
				ret[t] %= MOD;
		}
	}

	for (int i = 0; i < n; ++i) {
		ret[i] %= MOD;
	}

	return ret;
}

vector<int64> vecPow(vector<int64> a, int e) {
	if (!e) {
		vector<int64> ret(n);
		ret[0] = 1;
		return ret;
	}
	if (e % 2 == 0)
		return vecPow(merge(a, a), e >> 1);
	else
		return merge(vecPow(a, e - 1), a);
}

int main() {
	cin >> start >> target;
//	start = target = string(1000, 'a');
	cin >> k;
//	k = 10000;
	n = start.size();
	rs[0] = start;
	for (int i = 1; i < n; ++i) {
		rs[i] = rs[i - 1];
		rotate(rs[i].begin(), rs[i].begin() + 1, rs[i].end());
	}

	vector<int64> a(n, 1);
	a[0] = 0;
	vector<int64> ret = vecPow(a, k);

	int64 ans = 0;
	for (int i = 0; i < n; ++i) {
		if (rs[i] == target) {
			ans += ret[i];
			ans %= MOD;
		}
	}
	cout << ans << endl;

	return 0;
}