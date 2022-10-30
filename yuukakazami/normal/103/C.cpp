/*
 * c.cpp
 *
 *  Created on: 2011-8-7
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long int64;
int main() {
	int64 n, k;
	int nQ;
	vector<int64> qs;
	cin >> n >> k >> nQ;
	if (n == k) {
		for (int i = 0; i < nQ; ++i) {
			cout << "X";
		}
		cout << endl;
		return 0;
	}
	if (k == 0) {
		for (int i = 0; i < nQ; ++i) {
			cout << ".";
		}
		cout << endl;
		return 0;
	}
	int64 X = k, D = n - X;
	int64 b = min(X, D);
	if (b % 2 != D % 2)
		--b;
	int64 c = D - b;
	if (c == 0) {
		c = 1;
		--b;
	} else {
		if (b >= 1) {
			--b;
			c += 1;
		}
	}
	for (int i = 0; i < nQ; ++i) {
		int64 x;
		cin >> x;
		if (x <= c) {
			cout << ".";
		} else {
			x -= c;
			if (x <= 2 * b + 1) {
				if (x % 2 == 1)
					cout << "X";
				else
					cout << ".";
			} else {
				cout << "X";
			}
		}
	}
	cout << endl;
}