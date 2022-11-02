/*
 * C. Lucky Tree.cpp
 *
 *  Created on: 2011-9-7
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
struct Edge {
	int t, c;
	Edge(int _t, int _c) :
			t(_t), c(_c) {
	}
};
typedef long long int64;
const int MAX_N = int(1e5) + 10;
vector<Edge> E[MAX_N];
int nV;
int64 ans;
int down[MAX_N], up[MAX_N];
int size[MAX_N];

bool isLucky(int x) {
	while (x) {
		int d = x % 10;
		if (d != 4 && d != 7)
			return false;
		x /= 10;
	}
	return true;
}

void dfsDown(int u, int fa) {
	size[u] = 1;
	down[u] = 0;
	foreach(e,E[u]) {
		if (e->t != fa) {
			dfsDown(e->t, u);
			size[u] += size[e->t];
			if (isLucky(e->c)) {
				down[u] += size[e->t];
			} else {
				down[u] += down[e->t];
			}
		}
	}
}

void dfsUp(int u, int fa) {
	foreach(e,E[u]) {
		if (e->t != fa) {
			if (isLucky(e->c)) {
				up[e->t] = nV - size[e->t];
			} else {
				up[e->t] = up[u] + down[u] - down[e->t];
			}
			dfsUp(e->t, u);
		}
	}
}

int main() {
	cin >> nV;
	for (int i = 0; i < nV - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		E[a].push_back(Edge(b, c));
		E[b].push_back(Edge(a, c));
	}
	ans = 0;
	dfsDown(0, -1);
	dfsUp(0, -1);
	for (int i = 0; i < nV; ++i) {
		int cnt = up[i] + down[i];
		ans += 1LL * cnt * (cnt - 1);
	}
	cout << ans << endl;
	return 0;
}