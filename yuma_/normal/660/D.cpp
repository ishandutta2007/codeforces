#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"

//

int main() {
	int  N; cin >> N;
	vector<pair<int, int>>ps;
	for (int i = 0; i < N; ++i) {
		int a, b; cin >> a >> b;
		ps.emplace_back(a, b);
	}
	map<pair<int, int>, int>mp;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int dx = ps[i].first - ps[j].first;
			int dy = ps[i].second - ps[j].second;
			if (dx < 0) {
				dx = -dx;
				dy = -dy;
			}
			else if (dx == 0 && dy < 0) {
				dx = -dx;
				dy = -dy;
			}
			mp[make_pair(dx, dy)]++;
		}
	}
	int ans = 0;
	for (auto m : mp) {
		ans += (m.second)*(m.second - 1) / 2;
	}
	cout << ans/2 << endl;
	return 0;
}