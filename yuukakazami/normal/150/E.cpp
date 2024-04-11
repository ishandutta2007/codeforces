#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const int MAX_N = 100000;
const int INF = ~0U >> 3;
struct Edge {
	int t, c;
};
vector<Edge> E[MAX_N];
int n, pl, pr;
bool del[MAX_N];

int size[MAX_N], ord[MAX_N], cur, cnt[MAX_N], dep[MAX_N], fa[MAX_N];
void dfs(int u, int par, int chk, int d, int c) {
	dep[u] = d, cnt[u] = c, size[u] = 1, ord[cur++] = u, fa[u] = par;
	foreach(e,E[u])
		if (!del[e->t] && e->t != par) {
			dfs(e->t, u, chk, d + 1, c + (e->c >= chk ? 1 : -1));
			size[u] += size[e->t];
		}
}

int ansU, ansV, ans;

int mx[MAX_N], who[MAX_N], maxd;
int nmx[MAX_N], nwho[MAX_N], nmaxd;

bool cmp(int a, int b) {
	return size[a] < size[b];
}

int lstU, lstV;

bool check() {
	static int que[MAX_N];
	int qh = 0, qt = 0;
	int l = maxd;

	for (int i = 1; i <= nmaxd; ++i) {
		while (l + i >= pl && l >= 0) {
			while (qh < qt && mx[que[qt - 1]] <= mx[l])
				--qt;
			que[qt++] = l;
			--l;
		}
		while (qh < qt && que[qh] + i > pr)
			++qh;
		if (qh < qt) {
			if (mx[que[qh]] + nmx[i] >= 0) {
				lstU = who[que[qh]];
				lstV = nwho[i];
				return true;
			}
		}
	}
	return false;
}

void solve(int rt) {
	cur = 0;
	dfs(rt, -1, -1, 0, 0);
	int mi = INF, sp;
	for (int i = 0; i < cur; ++i) {
		int u = ord[i];
		int opt = size[rt] - size[u];
		foreach(e,E[u])
			if (!del[e->t] && e->t != fa[u])
				opt = max(opt, size[e->t]);
		if (opt < mi)
			mi = opt, sp = u;
	}

	rt = sp;
	cur = 0, dfs(rt, -1, -1, 0, 0);
	//cout << "ROOT:" << rt << endl;
	del[rt] = true;
	static int ch[MAX_N];
	int nCh = 0;
	foreach(e,E[rt])
		if (!del[e->t])
			ch[nCh++] = e->t;
	sort(ch, ch + nCh, cmp);
	int l = -1, r = 1e9 + 1;
	for (;;) {
		int m = (l + r) >> 1;
		foreach(e,E[rt])
			if (!del[e->t])
				cnt[e->t] = e->c >= m ? 1 : -1;
		bool ok = false;
		maxd = 0;
		mx[0] = 0, who[0] = rt;
		for (int it = 0; it < nCh; ++it) {
			int u = ch[it];
			cur = 0, dfs(u, -1, m, 1, cnt[u]);
			nmaxd = 0;
			for (int i = 0; i < cur; ++i) {
				nmaxd = max(nmaxd, dep[ord[i]]);
			}
			for (int i = 0; i <= nmaxd; ++i) {
				nmx[i] = -INF;
			}
			for (int i = 0; i < cur; ++i) {
				int v = ord[i];
				if (cnt[v] > nmx[dep[v]])
					nmx[dep[v]] = cnt[v], nwho[dep[v]] = v;
			}
			if (check()) {
				ok = true;
				break;
			}
			for (int i = 0; i <= nmaxd; ++i) {
				if (i > maxd || nmx[i] > mx[i])
					mx[i] = nmx[i], who[i] = nwho[i];
			}
			maxd = max(maxd, nmaxd);
		}
		if (l + 1 == r)
			break;
		if (ok)
			l = m;
		else
			r = m;
	}
	if (l > ans)
		ans = l, ansU = lstU, ansV = lstV;
	foreach(e,E[rt])
		if (!del[e->t])
			solve(e->t);
}

int main() {
	cin >> n >> pl >> pr;
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c), --a, --b;
		E[a].push_back((Edge) {b,c});
		E[b].push_back((Edge) {a,c});
	}
	ans = -1;
	solve(0);
	cout << ansU + 1 << " " << ansV + 1 << endl;
	return 0;
}