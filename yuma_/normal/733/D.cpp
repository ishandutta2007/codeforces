#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

void pus(map < pair<int, int>, vector<pair<int,int>>>&mp, int a, int b, int c,int w) {
	mp[make_pair(a, b)];
	
	auto it = mp.find(make_pair(a, b));
	it->second.push_back(make_pair(c,w));
	sort(it->second.begin(), it->second.end());
	if (it->second.size() >= 3)it->second.erase(it->second.begin());
}

int main() {
	int N; cin >> N;
	map<pair<int, int>, vector<pair<int,int>>>mp;
	pair<int, vector<int>>ans(-1, vector<int>());
	vector<vector<int>>rects;
	for (int i = 0; i < N; ++i) {
		vector<int>ls(3);
		cin >> ls[0] >> ls[1] >> ls[2];
		sort(ls.begin(), ls.end());
		rects.push_back(ls);
		auto aans = make_pair(ls[0], vector<int>(1, i+1));
		ans = max(ans, aans);
		if (ls[0] == ls[2]) {
			pus(mp, ls[0], ls[0], ls[0],i+1);
		}
		else if (ls[0] == ls[1]) {
			pus(mp, ls[0], ls[0], ls[2], i + 1);
			pus(mp, ls[0], ls[2], ls[0], i + 1);
		}
		else if (ls[1] == ls[2]) {
			pus(mp, ls[0], ls[1], ls[1], i + 1);
			pus(mp, ls[1], ls[1], ls[0], i + 1);
		}
		else {
			pus(mp, ls[0], ls[1], ls[2], i + 1);
			pus(mp, ls[0], ls[2], ls[1], i + 1);
			pus(mp, ls[1], ls[2], ls[0], i + 1);
		}
	}
	vector<vector<int>>p;
	for (auto m : mp) {
		if (m.second.size() == 2) {
			int a = m.first.first;
			int  b = m.first.second;
			int c = m.second[0].first + m.second[1].first;
		
			if (min(min(a, b), c) > ans.first) {
				ans.first = min(min(a, b), c);
				ans.second = vector<int>{ m.second[0].second,m.second[1].second };
			}
		}
	}
	if (ans.second.size() == 1) {
		cout << 1 << endl;
		cout << ans.second[0] << endl;
	}
	else {
		cout << 2 << endl;
		cout << ans.second[0] << " " << ans.second[1] << endl;
	}
	return 0;
}