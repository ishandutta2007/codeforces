/*
 * a.cpp
 *
 *  Created on: 2013-7-31
 *      Author: 
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
typedef long long int64;
int64 n;

typedef pair<int64, int> pr;

map<pr, pr> memo;

pr solve(int64 n, int mx) {
	if (n == 0)
		return make_pair(0, 0);
	if (n < 10) {
		pr ans = make_pair(1, 0);
		if (mx > n)
			ans.second = mx - n;
		return ans;
	}
	pr key = make_pair(n, mx);
	if (memo.count(key))
		return memo[key];

	int64 pw = 1;
	while (pw <= n / 10)
		pw *= 10;

	pr ret = make_pair(0, 0);

	while (true) {
		int d = n / pw;
		int nmx = max(d, mx);
		pr t = solve(n % pw, nmx);
		n -= n % pw;
		ret.first += t.first;
		if (t.second > 0) {
			n -= t.second;
		} else {
			n -= nmx;
			if (nmx > 0)
				++ret.first;
		}
		if (d == 0)
			break;
	}
	ret.second = -n;
	return memo[key] = ret;
}

int main() {
	int64 n;
	cin >> n;
	cout << solve(n, 0).first << endl;
	return 0;
}