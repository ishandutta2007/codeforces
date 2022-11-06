#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

vector<vector<int>>graph;
vector<vector<pair<int, int>>>querys;
vector<long long int>anss;
vector<long long int>adds(600010);
void dfs(int now, int from, int depth, long long int sum) {
	for (auto q : querys[now]) {
		adds[depth] += q.second;
		adds[depth + q.first + 1] -= q.second;
	}
	sum += adds[depth];
	anss[now] = sum;
	for (auto e : graph[now]) {
		if (e == from)continue;
		dfs(e, now, depth + 1, sum);
	}
	for (auto q : querys[now]) {
		adds[depth] -= q.second;
		adds[depth + q.first + 1] += q.second;
	}
}
int main()
{
	int N; cin >> N;
	querys.resize(N);
	graph.resize(N);
	anss.resize(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int Q; cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		a--;
		b=min(b,int(300010));
		querys[a].push_back(make_pair(b, c));
	}
	dfs(0, -1, 0, 0);
	for (int i = 0; i<N; ++i)printf("%lld ", anss[i]);
	cout << endl;
	return 0;
}