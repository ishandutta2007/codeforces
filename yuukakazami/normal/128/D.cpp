/*
 * d.cpp
 *
 *  Created on: 2011-11-15
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <set>
#include <map>
#include <vector>
#include <utility>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
int n;
vector<int> a;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	if (n % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i + 1 < a.size(); ++i) {
		if (a[i + 1] - a[i] > 1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	map<int, int> cnt;
	for (int i = 0; i < a.size(); ++i) {
		cnt[a[i]]++;
	}
	vector<int> p;
	for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
		p.push_back(it->second);
	}
	for (int i = 1; i + 1 < p.size(); ++i) {
		if (p[i] < 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (int i = 1; i < p.size(); ++i) {
		p[i] -= p[i - 1];
		if (p[i] < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (p.back() != 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}