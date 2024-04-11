/*
 * E. Lostborn.cpp
 *
 *  Created on: 2011-7-8
 *      Author: mac
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

const int MAX_K = 100 + 10;
const int CUT = 300000 + 10;

typedef long long int64;
int64 memo[MAX_K][CUT], n;
int a[MAX_K], k;

int64 rec(int at, int64 n) {
	if (!n)
		return 0;
	if (at < 0)
		return n;
	if (n < CUT) {
		if (memo[at][n] != -1)
			return memo[at][n];
	}
	int64 ret = rec(at - 1, n) - rec(at - 1, n / a[at]);
	if (n < CUT) {
		memo[at][n] = ret;
	}
	return ret;
}

int main() {
	memset(memo, -1, sizeof memo);
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
	}
	sort(a, a + k);
	cout << rec(k - 1, n) << endl;
}