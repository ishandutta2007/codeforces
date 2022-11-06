#include "bits/stdc++.h"

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
struct Edge {
	int u;
	int v;
	int cost;
};

int main() {
	int N,M,K;cin>>N>>M>>K;
	vector<int>special_vertics(K);
	for (int i = 0; i < K; ++i) {
		int a;cin>>a;a--;
		special_vertics[i]=a;
	}
	UnionFind uf(N);
	vector<Edge>edges(M);
	for (int i = 0; i < M; ++i) {
		int a,b,c;cin>>a>>b>>c;
		a--;b--;c--;
		edges.push_back(Edge{ a,b,c });
	}
	sort(edges.begin(), edges.end(), [](const Edge&l, const Edge&r) {
		return l.cost<r.cost;
	});
	map<int,int>nums;
	for(auto a:special_vertics)nums[a]=1;
	int answer=0;
	for (auto e : edges) {
		int l=nums[uf.root(e.u)];
		int r=nums[uf.root(e.v)];
		if(uf.root(e.u)==uf.root(e.v))continue;
		uf.unionSet(e.u,e.v);
		nums[uf.root(e.u)]=l+r;
		if (l + r == K) {
			answer=e.cost;
			break;
		}
	}
	for (int i = 0; i < K; ++i) {
		cout<<answer+1;
		if(i==K-1)cout<<endl;
		else cout<<" ";
	}
	return 0;
}