#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
struct Node {
	
	vector<shared_ptr<Node>>chs;
	int id;

	Node(int _id) :id(_id) {

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

void solve(shared_ptr<Node>&now,vector<int>&anss) {
	if (now->id == -1) {
		solve(now->chs[0],anss);
		solve(now->chs[1],anss);
	}
	else {
		anss.push_back(now->id);
	}
}
int main() {
	int N;cin>>N;
	vector<shared_ptr<Node>>nodes;
	for (int i = 0; i < N; ++i) {
		nodes.push_back(make_shared<Node>(i));
	}

	UnionFind uf(N);
	for (int i = 0; i < N - 1; ++i) {
		int u,v;scanf("%d %d",&u,&v);
		u--;v--;
		shared_ptr<Node>anode(make_shared<Node>(-1));
		anode->chs.push_back(nodes[uf.root(u)]);
		anode->chs.push_back(nodes[uf.root(v)]);
		uf.unionSet(u,v);
		nodes[uf.root(u)]=anode;
	}
	int aroot=uf.root(0);
	vector<int>anss;
	solve(nodes[aroot],anss);
	for (int i = 0; i < anss.size(); ++i) {
		cout<<anss[i]+1<<" ";

	}
	cout<<endl;
	return 0;
}