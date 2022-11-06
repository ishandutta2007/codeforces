#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

namespace tree {
	void dfs(const int now, const vector<vector<int>>&edges, vector<int>&memo, int depth) {
		memo[now] = depth;
		for (auto e : edges[now]) {
			if (memo[e] == -1) {

				dfs(e, edges, memo, depth + 1);
			}
		}
	}

	vector<int> dia(const vector<vector<int>>&edges, const int from) {
		vector<int>memo(edges.size(), -1);
		{
			memo[from] = 0;
			dfs(from, edges, memo, 0);
		}
		auto it = max_element(memo.begin(), memo.end());
		{
			int start = it - memo.begin();
			vector<int>nmemo(edges.size(), -1);
			nmemo[start] = 0;
			dfs(start, edges, nmemo, 0);

			int k = max_element(nmemo.begin(), nmemo.end()) - nmemo.begin();

			vector<int>v{ k };
			for (int de = nmemo[k]; de >= 1; --de) {
				for (auto e : edges[k]) {
					if (nmemo[e] == de - 1) {
						v.push_back(e);
						k = e;
						break;
					}
				}
			}
			return v;
		}
	}
}
bool dfs(const vector<vector<int>>&edges,const int now, const int from, const int k) {
	vector<int>nexts;
	for (auto e : edges[now]) {
		if(e==from)continue;
		else {
			nexts.push_back(e);
		}
	}
	if (k == 0) {
		return nexts.empty();
	}
	else {
		if(nexts.size()<3)return false;
		else {
			bool aok=true;
			for (auto n : nexts) {
				if (!dfs(edges, n, now, k - 1)) {
					aok=false;
				}
			}
			return aok;
		}
	}
}
int main() {
	int N,M;cin>>N>>M;
	vector<vector<int>>edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int a,b;cin>>a>>b;a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	auto di=tree::dia(edges,0);
	bool ok=true;
	if (di.size() % 2 == 0) {
		ok=false;
	}
	else {
		int n=di[di.size()/2];
		ok=dfs(edges,n,-1,M);
	}
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}