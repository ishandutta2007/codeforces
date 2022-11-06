#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int main() {
	int H, W; cin >> H >> W;
	vector<vector<int>>field(H, vector<int>(W));
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			cin >> field[y][x];
		}
	}
	vector<pair<int, int>>ps;
	for (int x = 0; x < W; ++x) {
		int fromy = 0;
		for (int y = 1; y < H; ++y) {
			if (field[y][x]<field[y - 1][x]) {
				ps.emplace_back(fromy, y - 1);
				fromy = y;
			}
		}
		ps.emplace_back(fromy, H - 1);
	}
	sort(ps.begin(), ps.end());
	vector<int>v(H);
	for (auto p : ps) {
		v[p.first] = max(v[p.first], p.second);
	}
	for (int i = 0; i < H - 1; ++i) {
		v[i + 1] = max(v[i], v[i + 1]);
	}

	int Q; cin >> Q;
	while (Q--) {
		int u, d; cin >> u >> d; u--; d--;
		if (d > v[u])cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}