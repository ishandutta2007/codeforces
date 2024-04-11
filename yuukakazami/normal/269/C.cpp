#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = int(2e5) + 10;
queue<int> que;

int n, m;
struct Edge {
	int t, c, id, w;
	Edge(int t, int c, int id, int w) :
			t(t), c(c), id(id), w(w) {
	}
};
vector<Edge> E[MAX_N];
int in[MAX_N], tot[MAX_N];

int which[MAX_N];

void send(int u) {
	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e)
		if (which[e->id] == -1) {
			in[e->t] += e->c;
			which[e->id] = e->w;
			if (e->t != 0 && e->t != n - 1 && in[e->t] == tot[e->t] / 2) {
				que.push(e->t);
			}
		}
}

int main() {
	cin >> n >> m;

	memset(which, -1, sizeof which);

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		E[a].push_back(Edge(b, c, i, 0));
		E[b].push_back(Edge(a, c, i, 1));
		tot[a] += c;
		tot[b] += c;
	}
	send(0);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		send(u);
	}

	for (int i = 0; i < m; ++i) {
		printf("%d\n", which[i]);
	}
	return 0;
}