/*
 * a.cpp
 *
 *  Created on: 2012-3-11
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
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 2000 + 10;
int n, d;

string make(string a, string b) {
	if (a > b)
		swap(a, b);
	return a + " " + b;
}

int a[MAX_N], b[MAX_N], t[MAX_N];
map<string, int> id;
vector<string> names;

bool ok[MAX_N][MAX_N];

int get(string a) {
	if (id.count(a))
		return id[a];
	int me = id.size();
	names.push_back(a);
	return id[a] = me;
}

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		string x, y;
		cin >> x >> y;
		a[i] = get(x);
		b[i] = get(y);
		cin >> t[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (i != j) {
				if (a[i] == b[j] && b[i] == a[j]) {
					if (t[j] > t[i] && t[j] <= t[i] + d) {
						ok[a[i]][b[i]] = ok[b[i]][a[i]] = true;
					}
				}
			}
	}

	int cnt = 0;
	for (int i = 0; i < id.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			cnt += ok[i][j];
		}
	}

	cout << cnt << endl;

	for (int i = 0; i < id.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (ok[i][j]) {
				cout << names[i] << " " << names[j] << endl;
			}
		}
	}
	return 0;
}