#include "bits/stdc++.h"
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


long long int solve(const vector<vector<int>>&edges,
	const vector<long long int>&as,bool flag) {
	vector<pair<long long int,int>>ps;
	for (int i = 0; i < as.size(); ++i) {
		ps.emplace_back(as[i],i);
	}
	sort(ps.begin(),ps.end());
	if(flag)reverse(ps.begin(),ps.end());
	UnionFind uf(edges.size());

	long long int ans=0;

	vector<int>used(edges.size());
	for (auto p : ps) {
		const int now(p.second);
		const long long int cost(p.first);

		long long int sum=1;
		long long int num=0;
		for (auto e : edges[now]) {
			if (used[e]) {
				sum+=uf.size(e);
				num+=static_cast<long  long int>(uf.size(e))*(uf.size(e)+1)/2;
			}
		}
		ans+=cost*(sum*(sum+1)/2-num);
		for (auto e : edges[now]) {
			if (used[e]) {
				uf.unionSet(e,now);
			}
		}

		used[now]=true;
	}
	return ans;
}

int main() {
	long long int N;cin>>N;
	vector<long long int>as(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d",&as[i]);
	}
	vector<vector<int>>edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int a,b;scanf("%d %d",&a,&b);a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	long long int ans=0;
	ans=solve(edges,as,false);
	ans-=solve(edges,as,true);
	cout<<ans<<endl;
	return 0;
}