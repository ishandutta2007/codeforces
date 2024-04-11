/*
 * b.cpp
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
#include <set>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MOD = 1000000007;
int n, m, k;
int mark[2001];

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		mark[i] = i;
	}
	long long ans = 1;
	for (int i = 0; i + k <= n; ++i) {
		int l = i, r = i + k - 1;
		for (; l <= r; l++, r--) {
			if (mark[l] != mark[r]) {
				int ol = mark[l];
				for (int x = 0; x < n; ++x) {
					if (mark[x] == ol)
						mark[x] = mark[r];
				}
			}
		}
	}
	set<int> st(mark, mark + n);
	for (int i = 0; i < st.size(); ++i) {
		ans = ans * m % MOD;
	}
	cout << ans << endl;
	return 0;
}