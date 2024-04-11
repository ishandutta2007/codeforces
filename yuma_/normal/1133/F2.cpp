#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;




struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

void dfs(int now, const vector<vector<int>>&edges, vector<int>&comes, vector<pair<int, int>>&answers) {

	for (auto e : edges[now]) {
		if(comes[e])continue;
		else {
			comes[e]=true;
			answers.emplace_back(now,e);
			dfs(e,edges,comes,answers);
		}
	}
}
signed main() {
	int N,M,W;cin>>N>>M>>W;
	UnionFind uf(N);
	vector<vector<int>>edges(N);
	for (int i = 0; i < M; ++i) {
		int a,b;scanf("%d %d",&a,&b);
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 1; i < N; ++i) {
		for (auto e : edges[i]) {
			if (e) {
				uf.unionSet(i,e);
			}
		}
	}
	set<int>aset;
	for (int i = 1; i < N; ++i) {
		aset.emplace(uf.root(i));
	}
	if(aset.size()>W||edges[0].size()<W)cout<<"NO"<<endl;
	else {
		vector<pair<int,int>>answers;
		int rest=W;
		vector<int>used(edges[0].size());
		for (int i=0;i<edges[0].size();++i) {
			if (aset.find(uf.root(edges[0][i])) == aset.end()) {

			}
			else {
				aset.erase(uf.root(edges[0][i]));
				used[i]=true;
				rest--;
			}
		}
		for (int i = 0; i<edges[0].size(); ++i) {
			if (!used[i]&&rest) {
				rest--;
				used[i]=true;
			}
		}

		vector<int>comes(N);
		comes[0] = true;
		for (int i = 0; i<edges[0].size(); ++i) {
			if (used[i]) {
				comes[edges[0][i]]=true;
			}
		}
		for (int i = 0; i<edges[0].size(); ++i) {
			if (used[i]) {
				answers.emplace_back(0,edges[0][i]);
				dfs(edges[0][i], edges, comes, answers);

			}
		}


		cout<<"YES"<<endl;
		assert(answers.size()==N-1);
		for (int i = 0; i < answers.size(); ++i) {
			printf("%d %d\n",1+answers[i].first,1+answers[i].second);
		}
	}
	return 0;
}