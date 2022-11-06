#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;



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
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int main() {
	int N, M; cin >> N >> M;
	vector<int>as;
	for (int i = 0; i < N; ++i) {
		int a;
		scanf("%d", &a);
		as.push_back(a);
	}
	UnionFind uf(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		uf.unionSet(a, b);
	}
	map<int, vector<int>>mp;
	for (int i = 0; i < N; ++i) {
		mp[uf.root(i)].push_back(as[i]);
	}
	for (auto &m : mp) {
		sort(m.second.begin(), m.second.end());
		reverse(m.second.begin(), m.second.end());

	}
	map<int, int>nums;
	vector<int>anss(N);
	for (int i = 0; i < N; ++i) {
		int a = mp[uf.root(i)][nums[uf.root(i)]++];
		anss[i] =a;
	}
	for (int i = 0; i < anss.size(); ++i) {
		printf("%d", anss[i]);
		if (i == anss.size() - 1)printf("\n");
		else printf(" ");
	}
	
	return 0;
}