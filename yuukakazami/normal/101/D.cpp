#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int64;

struct Edge {
	int t, c;
	Edge(int _t, int _c) :
			t(_t), c(_c) {
	}
};

const int MAX_N = int(1e5) + 10;

vector<Edge> E[MAX_N];

struct Result {
	int64 T, C, E, S;
	double e;
	Result() :
			T(0), C(0), E(0), S(0) {
	}
	void get() {
		e = 1.0 * (2 * E + C) / S;
	}
	bool operator<(const Result&r) const {
		return e < r.e;
	}
};

int nV;

Result dfs(int u, int fa) {
	Result ret;
	vector<Result> ch;
	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (e->t != fa) {
			Result t = dfs(e->t, u);
			t.E = e->c;
			t.get();
			ch.push_back(t);
		}
	}
	sort(ch.begin(), ch.end());
	int64 need = 0;
	ret.S = 1;
	for (vector<Result>::iterator e = ch.begin(); e != ch.end(); ++e) {
		ret.T += e->T + (need + e->E) * e->S;
		ret.C += e->E * 2 + e->C;
		ret.S += e->S;
		need += e->C + e->E * 2;
	}
	return ret;
}

int main() {
	cin >> nV;
	for (int i = 0; i < nV - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c), --a, --b;
		E[a].push_back(Edge(b, c));
		E[b].push_back(Edge(a, c));
	}
	Result ret = dfs(0, -1);
	printf("%0.10lf\n", 1.0 * ret.T / (nV - 1));
	return 0;
}