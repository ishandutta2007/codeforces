#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;
const int MAX_N = int(1e5) + 10, LOG = 20;
int n, k;
int anc[MAX_N][LOG], dep[MAX_N];
vector<int> E[MAX_N];
int seq[MAX_N], pt, at[MAX_N];

void dfs(int u, int p, int d) {
	anc[u][0] = p, dep[u] = d, seq[pt] = u, at[u] = pt++;
	for (int i = 1; i < LOG; ++i) {
		int go = anc[u][i - 1];
		anc[u][i] = go == -1 ? go : anc[go][i - 1];
	}
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e)
		if (*e != p)
			dfs(*e, u, d + 1);
}

int lca(int u, int v) {
	if (dep[u] < dep[v])
		swap(u, v);
	int up = dep[u] - dep[v];
	for (int i = 0; i < LOG; ++i) {
		if (up >> i & 1)
			u = anc[u][i];
	}
	if (u == v)
		return u;
	for (int i = LOG - 1; i >= 0; --i) {
		if (anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	}
	return anc[u][0];
}

set<int> st;

int add(int u) {
	if (st.empty())
		return 1;
	set<int>::iterator it = st.lower_bound(at[u]);
	int L, R;
	R = seq[it == st.end() ? *st.begin() : *it];
	L = seq[it == st.begin() ? *st.rbegin() : *--it];
	return dep[u] - dep[lca(u, L)] - dep[lca(u, R)] + dep[lca(L, R)];
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b), --a, --b, E[a].push_back(b), E[b].push_back(a);
	}
	dfs(0, -1, 0);
	int j = 0, now = 0; //[i,j)
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		while (now <= k) {
			ans = max(ans, j - i);
			if (j == n)
				break;
			now += add(j), st.insert(at[j]), ++j;
		}
		st.erase(at[i]), now -= add(i);
	}
	cout << ans << endl;
}