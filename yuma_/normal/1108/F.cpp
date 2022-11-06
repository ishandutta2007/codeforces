#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

struct Edge {
	int u;
	int v;
	int w;
	bool operator <(const Edge&r)const {
		return this->w<r.w;
	}
};


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

int main()
{
	int N,M;cin>>N>>M;
	map<int,vector<Edge>>mp;
	for (int i = 0; i < M; ++i) {
		int a,b,w;cin>>a>>b>>w;
		a--;b--;
		mp[w].push_back(Edge{ a,b,w });
	}
	UnionFind uf(N);
	int answer=0;
	for (auto m : mp) {
		vector<Edge>es=m.second;

		int valid_e_cnt=0;
		for (auto e : es) {
			if (uf.root(e.u) == uf.root(e.v)) {

			}
			else {
				valid_e_cnt++;
			}
		}
		int use_e_cnt=0;
		for (auto e : es) {
			use_e_cnt+=uf.unionSet(e.u,e.v);
		}
		answer+=valid_e_cnt-use_e_cnt;
	}
	cout<<answer<<endl;
	return 0;
}