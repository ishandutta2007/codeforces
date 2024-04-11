/*
 * c.cpp
 *
 *  Created on: 2012-3-27
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <cassert>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long int64;
bool solve(int64 a, int64 b) {
	if (a > b)
		swap(a, b);
	if (a == 0)
		return false;
	bool next = solve(a, b % a);
	if (!next) // mod it
		return true;
	int64 num = b / a;
	if (a % 2 == 1)
		return num % 2 == 1 ? false : true;
	else {
		int64 m = a + 1;
		num -= 1;
		int64 rem = num % m;
		if (rem == m - 1)
			return true;
		if (rem % 2 == 0)
			return false;
		else
			return true;
	}
}

int main() {
//	bool dp[100];
//	memset(dp, 0, sizeof dp);
//	dp[0] = true;
//	int n = 100;
//	int k;
//	cin >> k;
//	for (int i = 1; i < n; ++i) {
//		dp[i] = false;
//		for (int j = 1; j <= i; j *= k)
//			if (!dp[i - j])
//				dp[i] = true;
//	}
//	for (int i = 0; i < n; ++i) {
//		if (!dp[i]) {
//			cout << i - 1 << " ";
//		}
//	}
//	cout << endl;
//	cout << endl;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int64 a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		//a<=b
		puts(solve(a, b) ? "First" : "Second");
	}
	return 0;
}