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

typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src_, int dst_, Weight weight_) :
		src(src_), dst(dst_), weight(weight_) { }
	Edge(int src_, int dst_) :
		src(src_), dst(dst_) {

	}
};
pair<bool, vector<Weight>> spfa(const int v_num, const vector<vector<Edge>>&es, const int start) {
	vector<Weight>diss(v_num, INT_MAX);
	queue<int>que;
	vector<bool>use(v_num);
	vector<int>count(v_num);
	que.emplace(start);
	diss[start] = 0;
	while (!que.empty()) {
		int src(que.front());
		que.pop();
		use[src] = false;
		for (auto e : es[src]) {
			const int d = e.dst;
			if (diss[src] + e.weight < diss[d]) {
				diss[d] = diss[src] + e.weight;
				if (!use[d]) {
					use[d] = true;
					count[d]++;
					if (count[d] >= v_num)return make_pair(false, vector<Weight>());
					que.emplace(d);
				}
			}
		}
	}
	return make_pair(true, diss);
}

int main() {
	int N; cin >> N;
	vector<vector<Edge>>es(N);
	for (int i = 0; i < N-1; ++i) {
		int a; cin >> a; a--;
		es[i].push_back(Edge(i,i+1,1));
		es[i].push_back(Edge(i, a, 1));
		if (i) {
			es[i].push_back(Edge(i, i - 1, 1));
		}
	}
	{
		int a; cin >> a; a--;
		es[N - 1].push_back(Edge(N - 1, N - 2, 1));
	}
	auto p = spfa(N, es, 0);
	for (int i = 0; i < N; ++i) {
		cout << p.second[i];
		if (i == N - 1)cout << endl;
		else cout << " ";
	}
	return 0;
	
}