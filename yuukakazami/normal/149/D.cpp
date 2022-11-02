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
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
string a;
int n;
int pr[1000];
typedef long long ll;
ll memo[800][800][3][3];

const int MOD = int(1e9) + 7;

ll rec(int l, int r, int cl, int cr) {
	if (l > r)
		return 1;
	ll &ret = memo[l][r][cl][cr];
	if (ret != -1)
		return ret;
	ret = 0;
	int m = pr[l];
	if (m == r) {
		for (int c = 0; c < 2; ++c) {
			if (c != cl) {
				ret += rec(l + 1, r - 1, c, 2);
			}
			if (c != cr) {
				ret += rec(l + 1, r - 1, 2, c);
			}
		}
		return ret %= MOD;
	}
	for (int c = 0; c < 2; ++c) {
		if (c != cl)
			ret += rec(l + 1, m - 1, c, 2) * rec(m + 1, r, 2, cr);
		ret += rec(l + 1, m - 1, 2, c) * rec(m + 1, r, c, cr);
	}
	return ret %= MOD;
}

int main() {
	cin >> a;
	n = a.size();
	vector<int> stk;
	for (int i = 0; i < n; ++i) {
		if (a[i] == '(')
			stk.push_back(i);
		else {
			int p = stk.back();
			stk.pop_back();
			pr[p] = i;
			pr[i] = p;
		}
	}
	memset(memo, -1, sizeof memo);
	cout << rec(0, n - 1, 2, 2) << endl;
	return 0;
}