#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
bool check(const vector<pair<int, int>>&ps, ld amid) {
	ld x1=-1e14;
	ld x2=1e14;
	for (auto p : ps) {
		if (p.second > amid * 2)return false;
		else {
			ld k = p.second - amid;
			ld dis = sqrt(p.second*(2*amid-p.second));

			x1=max(x1,p.first-dis);
			x2=min(x2,p.first+dis);
		}
	}
	return x1+1e-9<=x2;
}
int main() {
	int N; cin >> N;
	vector<pair<int, int>>ps;
	for (int i = 0; i < N; ++i) {
		int x, y; cin >> x >> y;
		ps.emplace_back(x, y);
	}
	if (all_of(ps.begin(), ps.end(), [](const pair<int, int>p) {return p.second < 0; })) {
		for (auto&p : ps)p.second = -p.second;
	}
	if (any_of(ps.begin(), ps.end(), [](const pair<int, int>p) {return p.second < 0; })) {
		cout << -1 << endl;
	}
	else {
		ld amin = 0;
		ld amax = 1e18;
		int rest = 150;
		while (rest--) {
			ld amid((amin + amax) / 2);
			if (check(ps, amid)) {
				amax = amid;
			}
			else {
				amin = amid;
			}
		}
		cout << setprecision(30) << fixed << amin << endl;
	}
	return 0;
}