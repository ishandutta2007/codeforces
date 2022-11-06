#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

void dfs(const int now, vector<int>&used,const vector<vector<int>>&edges) {
	used[now] = true;
	for (auto e : edges[now]) {
		if (!used[e]) {
			dfs(e, used, edges);
		}
	}
}

int main() {
	int N, M; 
	cin >> N >> M;
	map<pair<int, int>, long long int>edge_mp;
	vector<vector<int>>edges(N);
	vector<int>edge_num(N);
	long long int self_cnt = 0;
	for (int i = 0; i < M; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		a--; b--; if (a>b)swap(a, b);
		if (a == b) {
			self_cnt++;
		}
		else {

			edge_mp[make_pair(a, b)]++;
			edge_num[a]++;
			edge_num[b]++;
		}
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	bool ok = true;
	{
		vector<int>used(N);
		bool flag = false;
		for (int i = 0; i < N; ++i) {
			if (!edges[i].empty()) {
				if (!flag) {
					dfs(i, used, edges);
					flag = true;
				}
				else {
					if (!used[i])ok = false;
					
				}
			}
		}
	}
	if (!ok)cout << 0 << endl;
	else {
		long long int ans = 0;
		for (auto m : edge_mp) {
			{
				const int a = m.first.first;
				const int b = m.first.second;
				ans += edge_num[a] + edge_num[b] - 2;
			}
		}
		ans /= 2;
		ans += self_cnt*(M-self_cnt)+(self_cnt)*(self_cnt-1)/2;
		cout << ans << endl;
	}
	
	return 0;
}