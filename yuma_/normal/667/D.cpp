#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>>edges(N),revedges(N);
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b; a--; b--;
		edges[a].push_back(b);
		revedges[b].push_back(a);
	}
	vector<vector<int>>diss(N, vector<int>(N, -1));
	vector<vector<int>>lens(N),revlens(N);
	for (int i = 0; i < N; ++i) {
		diss[i][i] = 0;
		queue<int>que;
		que.push(i);
		vector<int>came(N);
		came[i] = true;
		while (!que.empty()) {
			int atop(que.front());
			que.pop();
			for (auto e : edges[atop]) {
				if (!came[e]) {
					diss[i][e] = diss[i][atop] + 1;
					came[e] = true;
					que.push(e);
					lens[i].push_back(e);
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		queue<int>que;
		que.push(i);
		vector<int>came(N);
		came[i] = true;
		while (!que.empty()) {
			int atop(que.front());
			que.pop();
			for (auto e : revedges[atop]) {
				if (!came[e]) {
					came[e] = true;
					que.push(e);
					revlens[i].push_back(e);
				}
			}
		}
	}
	int ans = -1;
	vector<int>cities;
	for (int amid1 = 0; amid1 < N; ++amid1) {
		for (int amid2 = 0; amid2 < N; ++amid2) {
			if (amid1 == amid2)continue;
			if (diss[amid1][amid2] == -1) continue;
			int nans = 0;
			for (int i = 0; i < min(int(revlens[amid1].size()),3); ++i) {
				for (int j = 0; j < min(int(lens[amid2].size()), 3); ++j) {
					int nsum = 0;
					const int start = revlens[amid1][revlens[amid1].size() - i - 1];
					const int goal = lens[amid2][lens[amid2].size() - j - 1];
					if (start == amid2)continue;
					if (goal == amid1)continue;
					if (start == goal)continue;
					if (diss[start][amid1] == -1 || diss[amid2][goal] == -1)assert(false);
					nsum = diss[start][amid1] + diss[amid1][amid2] + diss[amid2][goal];
					if (ans < nsum) {
						ans = nsum;
						cities = vector<int>{ start,amid1,amid2,goal };
					}
				}
			}
		}
	}
	for (int i = 0; i < 4; ++i) {
		cout << cities[i]+1;
		if (i != 3)cout << " ";
		else cout << endl;
	}
	return 0;
}