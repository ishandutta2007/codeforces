/*
 * tmp.cpp
 *
 *  Created on: 2011-9-3
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

bool isLucky(int x) {
	while (x) {
		int d = x % 10;
		if (d != 4 && d != 7)
			return false;
		x /= 10;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int prev[26] = { };
	memset(prev, -1, sizeof prev);
	string ans;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (prev[j] == -1 || isLucky(i - prev[j])) {
				prev[j] = i;
				ans += char('a' + j);
				break;
			}
		}
	}
	cout << ans << endl;
}