/*
 * f.cpp
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
#include <string>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 2000 + 10;
string a[MAX_N];
int n, k;

const int INF = ~0U >> 2;

int lcp(string a, string b) {
	int k = 0;
	for (int i = 0; i < a.size() && i < b.size(); ++i) {
		if (a[i] == b[i]) {
			++k;
		} else
			break;
	}
	return k;
}

int ls[MAX_N];

vector<int> solve(int l, int r) {
	//[l,r)
	if (l + 1 == r) {
		vector<int> ret(2, 0);
		return ret;
	}

	int m = l;
	for (int i = l; i + 1 < r; ++i) {
		if (ls[i] < ls[m])
			m = i;
	}

	//cut by (m,m+1)

	vector<int> a = solve(l, m + 1), b = solve(m + 1, r);
	vector<int> ret(r - l + 1, -INF);

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			ret[i + j] = max(ret[i + j], a[i] + b[j] + ls[m] * i * j);
		}
	}

	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);

	for (int i = 0; i < n - 1; ++i) {
		ls[i] = lcp(a[i], a[i + 1]);
	}

	vector<int> ret = solve(0, n);
	cout << ret[k] << endl;
	return 0;
}