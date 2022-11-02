/*
 * a.cpp
 *
 *  Created on: 2012-2-24
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
	int n, m;
	cin >> n >> m;
	int score[101][101], mx[101] = { };
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			score[i][j] = s[j] - '0';
			mx[j] = max(mx[j], score[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		bool ok = 0;
		for (int j = 0; j < m; ++j) {
			if (score[i][j] == mx[j])
				ok = 1;
		}
		cnt += ok;
	}
	cout << cnt << endl;
	return 0;
}