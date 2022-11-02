/*
 * c.cpp
 *
 *  Created on: 2012-10-1
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

const int MAX_N = 1000000 + 10;
int cnt[MAX_N];
typedef long long int64;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		cnt[a]++;
		cnt[b]++;
	}
	long long tot = 1LL * n * (n - 1) * (n - 2) / 6;
	long long bad = 0;
	for (int i = 0; i < n; ++i) {
		bad += 1LL * cnt[i] * (n - 1 - cnt[i]);
	}
	cout << tot - bad / 2 << endl;
	return 0;
}