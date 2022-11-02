/*
 * c.cpp
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
#include <utility>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	int x = a.size() / 2, y = n - x;
	cout << x << endl;
	for (int i = 1; i < n; i += 2) {
		cout << a[i].second << " ";
	}
	cout << endl;
	cout << y << endl;
	for (int i = 0; i < n; i += 2) {
		cout << a[i].second << " ";
	}
	cout << endl;
	return 0;
}