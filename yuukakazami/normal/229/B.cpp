/*
 * b.cpp
 *
 *  Created on: 2012-10-1
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = int(1e5) + 10;
int n, m;
struct Edge {
	int t, c;
	Edge(int _t, int _c) :
			t(_t), c(_c) {
	}
};
vector<Edge> E[MAX_N];
int d[MAX_N];
bool used[MAX_N];
vector<int> bad[MAX_N];
const int INF = ~0U >> 1;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		E[a].push_back(Edge(b, c));
		E[b].push_back(Edge(a, c));
	}
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int t;
			scanf("%d", &t);
			bad[i].push_back(t);
		}
	}
	fill(d, d + n, INF);
	d[0] = 0;
	priority_queue<pair<int, int> > que;
	que.push(make_pair(-d[0], 0));
	while (!que.empty()) {
		int u = que.top().second; //arrive time
		que.pop();
		if (used[u])
			continue;
		used[u] = true;
		vector<int>&my = bad[u];
		int go = d[u];
		if (!my.empty()) {
			while (binary_search(my.begin(), my.end(), go)) {
				++go;
			}
		}
		for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
			if (go + e->c < d[e->t]) {
				d[e->t] = go + e->c;
				que.push(make_pair(-d[e->t], e->t));
			}
		}
	}
	if (d[n - 1] == INF)
		puts("-1");
	else
		cout << d[n - 1] << endl;
	return 0;
}