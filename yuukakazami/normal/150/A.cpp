/*
 * a.cpp
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
#include <vector>
#include <map>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef long long ll;

map<ll, bool> memo;

bool calc(ll a) {
	if (memo.count(a))
		return memo[a];
	bool&ret = memo[a];
	ret = false;
	bool has = false;
	for (ll i = 2; i * i <= a; ++i) {
		if (a % i == 0) {
			has = true;
			if (!calc(a / i))
				return ret = true;
			if (!calc(i))
				return ret = true;
		}
	}
	if (!has)
		return ret = true;
	return ret;
}

int main() {
	ll q;
	cin >> q;
	if (calc(q)) {
		cout << 1 << endl;
		bool has = false;
		for (ll i = 2; i * i <= q; ++i) {
			if (q % i == 0) {
				has = true;
				if (!calc(q / i)) {
					cout << q / i << endl;
					break;
				}
				if (!calc(i)) {
					cout << i << endl;
					break;
				}
			}
		}
		if (!has)
			cout << 0 << endl;
	} else {
		cout << 2 << endl;
	}
	return 0;
}