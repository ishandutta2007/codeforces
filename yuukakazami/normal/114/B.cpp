#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> ns(n);
	for (int i = 0; i < n; ++i) {
		cin >> ns[i];
	}
	sort(ns.begin(), ns.end());
	int E[20] = { };
	for (int i = 0; i < m; ++i) {
		string a, b;
		cin >> a >> b;
		int x = find(ns.begin(), ns.end(), a) - ns.begin();
		int y = find(ns.begin(), ns.end(), b) - ns.begin();
		E[x] |= 1 << y;
		E[y] |= 1 << x;
	}
	int maxS = 0;
	for (int i = 0; i < (1 << n); ++i) {
		int c = 0;
		for (int j = 0; j < n; ++j) {
			if (i >> j & 1)
				++c;
		}
		bool ok = true;
		for (int k = 0; k < n; ++k) {
			if (i >> k & 1 && (E[k] & i)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			maxS = max(maxS, c);
		}
	}

	for (int i = 0; i < (1 << n); ++i) {
		int c = 0;
		for (int j = 0; j < n; ++j) {
			if (i >> j & 1)
				++c;
		}
		bool ok = true;
		for (int k = 0; k < n; ++k) {
			if ((i >> k & 1) && (E[k] & i)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			if (maxS == c) {
				cout << c << endl;
				for (int k = 0; k < n; ++k) {
					if (i >> k & 1) {
						cout << ns[k] << endl;
					}
				}
				return 0;
			}
		}
	}
	return 0;
}