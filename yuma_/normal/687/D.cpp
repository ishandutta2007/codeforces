#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"


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

struct edge {
	int src;
	int dst;
	int cost;
	int id;
	edge(int a, int b, int c,int d) :src(a), dst(b), cost(c),id(d) {

	}
};
int main() {
	int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
	vector<edge>es;
	for (int i = 0; i < M; ++i) {
		int a, b,c; 
		scanf("%d %d %d", &a, &b, &c); a--; b--;
		es.emplace_back(a, b,c,i);
	}
	sort(es.begin(), es.end(), [](const edge&l, const edge&r) {
		return l.cost > r.cost;
	});
	for (int i = 0; i < Q; ++i) {
		int l, r;
		scanf("%d %d", &l, &r); l--; r--;
		UnionFind uf(2 * N);
		int ans = -1;
		for (int n = 0; n <M; ++n) {
			if (es[n].id >= l&&es[n].id <= r) {
				edge e(es[n]);
				const int a = e.src;
				const int b = e.dst;
				const int c = e.cost;

				if (uf.root(a) == uf.root(b)) {
					ans = c;
					break;
				}
				else {
					uf.unionSet(a, b + N);
					uf.unionSet(b, a + N);
				}
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
}