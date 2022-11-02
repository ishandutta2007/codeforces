/*
 * b.cpp
 *
 *  Created on: 2012-3-4
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

int main() {
	int n;
	cin >> n;
	int cnt[5] = { };
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	int ans = cnt[4];
	cnt[4] = 0;
	int by = min(cnt[1], cnt[3]);
	ans += by;
	cnt[1] -= by, cnt[3] -= by;
	ans += cnt[3];
	cnt[3] = 0;
	//1,2
	int num = cnt[1] + cnt[2] * 2;
	if (num > 0)
		ans += (num - 1) / 4 + 1;
	cout << ans << endl;
	return 0;
}