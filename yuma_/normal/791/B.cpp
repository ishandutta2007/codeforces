#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

void dfs(const int now,vector<int>&v,int num,const vector<vector<int>>&edges) {
	v[now] = num;
	for (auto e : edges[now]) {
		if (v[e] == 0)dfs(e, v, num, edges);
	}
}

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>>edges(N, vector<int>());
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<int>types(N);
	int num = 1;
	for (int i = 0; i < N; ++i) {
		if (types[i] == 0) {
			dfs(i, types,num,edges);
			num++;
		}
	}
	vector<long long int>ver_nums(num);
	vector<long long int>edge_nums(num);
	for (int i = 0; i < N; ++i) {
		int k = types[i] - 1;
		ver_nums[k]++;
		edge_nums[k] += edges[i].size();
	}
	bool ok = true;
	for (int i = 0; i < num; ++i) {
		if (edge_nums[i] == ver_nums[i] * (ver_nums[i] - 1)) {

		}
		else {
			ok = false;
		}
	}
	if (ok)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}