#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	int N; cin >> N;
	int x, y; cin >> x >> y;
	vector<vector<pair<int, char>>>vs(8);
	for (int i = 0; i < N; ++i) {
		char c; int ax, ay; cin >> c >> ax >> ay;
		int dx = x - ax, dy = y - ay;
		if (abs(dx)==abs(dy)) {
			int num = (dx > 0) * 2 + (dy > 0);
			int dis = abs(dx);
			vs[num].push_back(make_pair(dis, c));
		}
		else if (dx == 0) {
			int num = 4 + (dy > 0);
			int dis = abs(dy);
			vs[num].push_back(make_pair(dis, c));
		}
		else if (dy == 0) {
			int num = 6 + (dx > 0);
			int dis = abs(dx);
			vs[num].push_back(make_pair(dis, c));
		}

	}
	for (int i = 0; i < 8; ++i) {
		sort(vs[i].begin(), vs[i].end());
	}
	bool ok = false;
	for (int i = 0; i < 8; ++i) {
		if (i < 4) {
			if (!vs[i].empty()) {
				auto p(vs[i][0]);
				if (p.second == 'Q' || p.second == 'B')ok = true;
			}
		}
		else {
			if (!vs[i].empty()) {
				auto p(vs[i][0]);
				if (p.second == 'Q' || p.second == 'R')ok = true;
			}
		}
	}
	if (ok)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}