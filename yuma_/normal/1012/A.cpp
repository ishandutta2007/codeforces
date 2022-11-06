#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

struct Edge {
	int u;
	int v;
	long long int cost;
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
int main() {
	int N;cin>>N;
	vector<long long int>v;
	for (int i = 0; i < N; ++i) {
		int a,b;scanf("%d %d",&a,&b);
		v.push_back(a);
		v.push_back(b);
	}
	sort(v.begin(),v.end());
	long long int answer=(v[N-1]-v[0])*(v[2*N-1]-v[N]);
	for (int l = 1; l < N; ++l) {
		int r=l+N-1;
		long long int nanswer=(v[2*N-1]-v[0])*(v[r]-v[l]);
		answer=min(answer,nanswer);
	}
	cout<<answer<<endl;
	return 0;
}