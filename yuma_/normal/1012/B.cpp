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
int main() {
	int H,W,Q;cin>>W>>H>>Q;
	UnionFind uf(H+W);
	for (int i = 0; i < Q;++i) {
		int x,y;scanf("%d %d",&x,&y);
		x--;y--;
		uf.unionSet(x,y+W);
	}
	set<int>aset;
	for (int i = 0; i < H + W; ++i) {
		aset.emplace(uf.root(i));
	}
	int answer=aset.size()-1;
	cout<<answer<<endl;
	return 0;
}