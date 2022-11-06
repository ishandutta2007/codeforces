#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

const int T = 17;

typedef long long int Weight;
struct Edge {
	int src, dest;
	int rev;
	Weight weight;
	bool operator < (const Edge &rhs) const { return weight > rhs.weight; }
};

void add_edge( int src, int dest,  Weight weight, vector<vector<Edge>> &g) {
	g[src].push_back(Edge{ src, dest,  (int)g[dest].size(), weight });
	}

void solve(int t,int a,int b,int l, int r,vector<int>&ans) {
	{
		if (b <= l)return;
		if (r <= a)return;
		if (l <= a&&b <= r) {
			ans.push_back(t);
			return;
		}
		solve(2 * t + 1, a, (a + b) / 2, l, r, ans);
		solve(2 * t + 2, (a + b) / 2, b, l, r, ans);
	}
}

vector<long long int> djk(vector<vector<Edge>>&g, const int start, const int goal) {
	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>>que;
	que.emplace(0, start);
	vector<long long int>memo(g.size(),1e18);
	memo[start] = 0;

	while (!que.empty()) {
		auto p(que.top());
		que.pop();
		const int now(p.second);
		const Weight nowtime(p.first);

		for (auto e : g[now]) {
			const Weight nexttime(nowtime + e.weight);
			const int next(e.dest);
			if (memo[next] > nexttime) {
				memo[next] = nexttime;
				que.push(make_pair(nexttime, next));
			}
		}
	}
	return memo;
}

int main() {
	int N, Q, S; cin >> N >> Q >> S;
	S--;
	const int in = 0;
	const int normal = 0 + 2*(1 << T)-1;
	const int out = normal + (1 << T);
	vector<vector<Edge>>edges(out+2*(1<<T)-1);

	for (int i = 0; i < (1 << T)-1; ++i) {
		 {

			add_edge(in + i, in + (2 * i + 1),0, edges);
			add_edge(in + i, in + (2 * i + 2), 0, edges);

			add_edge(out + (2 * i + 1), out + i, 0, edges);
			add_edge(out + (2 * i + 2), out + i, 0, edges);
		}
	}
	for (int i = 0; i < (1 << T); ++i) {
		add_edge(in + (1 << T) - 1 + i, normal + i, 0 , edges);
		add_edge(normal + i, out + (1 << T) - 1 + i, 0, edges);
	}
	while(Q--){
		int t;
		cin >> t;
		if (t == 1) {
			int v, u, w; cin >> v >> u >> w;
			v--; u--;
			add_edge(normal + v, normal + u, w,edges);
		}
		else {
			int v, l, r, w; cin >> v >> l >> r >> w;
			v--;
			l--; 
			vector<int>ans;
			solve(0, 0, (1 << T), l, r, ans);
			for (int j = 0; j < ans.size(); ++j) {
				if (t == 2) {
					add_edge(  normal + v, in + ans[j], w, edges);
					
				}
				else {
					add_edge(  out + ans[j], normal + v, w, edges);
				}
			}
		}
	}
	auto ans(djk(edges, normal+S, 1));
	for_each(ans.begin(), ans.end(), [](long long int& a) {
		a=a >= 1e17 ? -1 : a;
	});
	for (int i = 0; i < N; ++i) {
		cout << ans[normal + i];
		if (i == N - 1)cout << endl;
		else cout << " ";
	}
	
	return 0;
}