#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;


vector<int>s_sizes;
int get_size(const Graph&g,const int now) {
	if (s_sizes[now] == -1) {
		s_sizes[now] = 1;
		for (auto e : g[now]) {
			s_sizes[now] += get_size(g, e.dst);
		}
		return s_sizes[now];
	}
	else {
		return s_sizes[now];
	}
}
	

//rest : dist-a min
int dfs(const int now, long long int rest,const Graph &g,vector<long long int>&as) {
	
		if (rest >as[now]) {
			return s_sizes[now];
		}
		int num = 0;
		for (auto e : g[now]) {
			int a_rest =max(0ll, rest + e.weight);
			num += dfs(e.dst, a_rest, g, as);
		}
		return num;
	
}
int main() {
	int N; cin >> N;
	s_sizes.resize(N);
	fill(s_sizes.begin(), s_sizes.end(), -1);
	vector<long long int >as(N);
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
	}
	Graph g(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b; cin >> a >> b;
		g[a-1].push_back(Edge(a-1,i+1,b));
	}
	get_size(g, 0);
	int ans = dfs(0, 0, g, as);
	cout << ans << endl;
	return 0;
}