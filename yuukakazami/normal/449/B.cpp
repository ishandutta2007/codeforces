#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;
typedef long long int64;
const int64 INF = 1LL << 60;

struct Edge {
	int t, c;
	Edge(int t, int c) :
			t(t), c(c) {
	}
};

vector<Edge> E[MAX_N];
int n, m, k;
vector<int> trainAt[MAX_N];

void dijkstra(int64 dist[], bool useTrain) {
	for (int i = 0; i < n; ++i) {
		dist[i] = INF;
	}
	dist[0] = 0;
	if (useTrain) {
		for (int i = 0; i < n; ++i) {
			for (auto d : trainAt[i])
				dist[i] = min(dist[i], (int64) d);
		}
	}
	priority_queue<pair<int64, int> > que;
	static bool used[MAX_N];
	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}
	for (int i = 0; i < n; ++i) {
		que.push(make_pair(-dist[i], i));
	}

	while (!que.empty()) {
		int u = que.top().second;
		que.pop();
		if (used[u])
			continue;
		used[u] = true;
		for (auto e : E[u])
			if (dist[u] + e.c < dist[e.t]) {
				dist[e.t] = dist[u] + e.c;
				que.push(make_pair(-dist[e.t], e.t));
			}
	}
}

int64 dist1[MAX_N], dist2[MAX_N];
int ord[MAX_N];

bool cmp(int a, int b) {
	return dist1[a] < dist1[b];
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c), --u, --v;
		E[u].push_back(Edge(v, c));
		E[v].push_back(Edge(u, c));
	}
	for (int i = 0; i < k; ++i) {
		int y, s;
		scanf("%d%d", &y, &s), --y;
		trainAt[y].push_back(s);
	}

	dijkstra(dist1, true);
	for (int i = 0; i < n; ++i) {
		ord[i] = i;
	}
	sort(ord, ord + n, cmp);
	int tot = 0;
	for (int i = 1; i < n; ++i) {
		int me = ord[i];
		int64 train = INF;
		if (!trainAt[me].empty()) {
			train = *min_element(trainAt[me].begin(), trainAt[me].end());
		}
		bool can = false;
		for (auto e : E[me])
			if (dist1[e.t] + e.c == dist1[me]) {
				can = true;
			}
//		cout << can << endl;
		if (can) {
			tot += trainAt[me].size();
		} else {
			tot += trainAt[me].size() - 1;
		}
	}
	cout << tot << endl;
	return 0;
}