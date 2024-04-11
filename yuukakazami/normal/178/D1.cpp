/*
 * cd.cpp
 *
 *  Created on: 2012-4-28
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

int n;
int a[100];

int main() {
	cin >> n;
	for (int i = 0; i < n * n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n * n);
	do {
		int x[4][4];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				x[i][j] = a[i * n + j];
			}
		}
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += x[0][i];
		}

		bool ok = true;
		for (int r = 0; r < n; ++r) {
			if (accumulate(x[r], x[r] + n, 0) != sum) {
				ok = false;
				break;
			}
		}
		for (int c = 0; c < n; ++c) {
			int t = 0;
			for (int r = 0; r < n; ++r) {
				t += x[r][c];
			}
			if (t != sum)
				ok = false;
		}
		int A = 0, B = 0;
		for (int r = 0; r < n; ++r) {
			A += x[r][r];
			B += x[r][n - 1 - r];
		}
		if (A != sum || B != sum)
			ok = false;
		if (ok) {
			cout << sum << endl;
			for (int r = 0; r < n; ++r) {
				for (int c = 0; c < n; ++c) {
					cout << x[r][c] << " ";
				}
				cout << endl;
			}
			cout << endl;
			return 0;
		}
	} while (next_permutation(a, a + n * n));
	return 0;
}