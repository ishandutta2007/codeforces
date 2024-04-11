#include <bits/stdc++.h>
using namespace std;
inline void up(int &x, int y) {
	if (x < y) x = y;
}
int read() {
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '?') return -1;
		c = getchar();
	}
	int x = 0;
	while (isdigit(c)) {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x;
}
const int N = 305;
const int inf = 0x3f3f3f3f;
int n, pre[N], cyc[N], id[N], p[N], rev[N * 2], max_pre[N];
int cnt_0[N];
bool mark[N];
set<int> pres[N];
pair<int, int> quest[N];
vector<int> pot_0[N]; 
vector<pair<int, int>> pot[N];
int s, t, tot, head[N * 2], cur_head[N * 2], dep[N * 2], cnt;
struct edge {
	int to, cap, nxt;
} e[222222];
inline void add_edge(int u, int v, int w) {
	e[++cnt] = {v, w, head[u]};
	head[u] = cnt;
}
inline void add(int u, int v, int w) {
	add_edge(u, v, w);
	add_edge(v, u, 0);
}
bool bfs() {
	memset(dep, -1, (tot + 1) * 4);
	dep[s] = 0;
	queue<int> que;
	que.emplace(s);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = head[u]; i; i = e[i].nxt) {
			if (!e[i].cap) continue;
			int v = e[i].to;
			if (dep[v] == -1) {
				dep[v] = dep[u] + 1;
				que.emplace(v);
			}
		}
	}
	if (dep[t] == -1) return false;
	memcpy(cur_head, head, (tot + 1) * 4);
	return true; 
} 
int dfs(int u, int f) {
	if (u == t) return f;
	int rest = f;
	for (int &i = cur_head[u]; i && rest; i = e[i].nxt) {
		int v = e[i].to, w = e[i].cap;
		if (!w || dep[v] != dep[u] + 1) continue;
		int cur = dfs(v, min(rest, w));
		if (!cur) {
			dep[v] = -1;
		} else {
			rest -= cur;
			e[i].cap -= cur;
			e[i ^ 1].cap += cur;
		}
	}
	return f - rest;
}
int Dinic() {
	int res = 0;
	while (bfs())
		res += dfs(s, inf);
	return res;
}
void check() {
	tot = 0, cnt = 1;
	memset(head, 0, sizeof head);
	for (int i = 1; i <= n; ++i) {
		max_pre[i] = cnt_0[i] = 0;
		pres[i].clear();
	}
//	puts("info :: ");
//	for (int i = 1; i <= n; ++i)
//		printf("%d %d\n", pre[i], cyc[i]);
	int required = 0, rest = 0;
	vector<int> frees;
	for (int i = 1; i <= n; ++i) {
		if (~cyc[i] && ~pre[i]) {
			if (!pre[i]) {
				++cnt_0[cyc[i]];
			} else {
				pres[cyc[i]].insert(pre[i]);
				up(max_pre[cyc[i]], pre[i]);
			}
		} else {
			++rest;
			frees.emplace_back(i);
		}
	}
	for (int l = 1; l <= n; ++l) {
		if (!mark[l]) continue;
		int x = !cnt_0[l] ? l : ((l - cnt_0[l] % l) % l);
		if (x > 0) {
			quest[++tot] = {l, 0};
			add(s, tot, x);
			required += x;
			if (required > rest) return;
		}
		for (int i = 1; i < max_pre[l]; ++i) {
			if (pres[l].count(i)) continue;
			quest[++tot] = {l, i};
			add(s, tot, 1);
			required += 1;
			if (required > rest) return;
		}
	}
	int all = tot;
	t = ++tot;	
	auto match = [&](pair<int, int> p, int i) {
		return (cyc[i] == -1 || cyc[i] == p.first) && (pre[i] == -1 || pre[i] == p.second);	
	};
	for (auto i : frees) {
		id[i] = ++tot;
		rev[id[i]] = i;
		add(id[i], t, 1);
		for (int j = 1; j <= all; ++j)
			if (match(quest[j], i)) add(j, id[i], 1);
	}
	if (Dinic() != required) return;
	for (int u = 1; u <= all; ++u) {
		for (int i = head[u]; i; i = e[i].nxt) {
			if (e[i].cap) continue;
			int cur = rev[e[i].to];
			tie(cyc[cur], pre[cur]) = quest[u];
		}
	}
//	for (int i = 1; i <= n; ++i)
//		printf("cur :: %d %d\n", pre[i], cyc[i]);
	auto tmp = frees;
	frees.clear();
	for (auto i : tmp) {
		if (~pre[i] && ~cyc[i]) continue;
		if (pre[i] == -1 && ~cyc[i]) {
			pre[i] = ++max_pre[cyc[i]];
		} else {
			assert(cyc[i] == -1);
			frees.emplace_back(i);
		}
	}
	int pos = max_element(max_pre + 1, max_pre + n + 1) - max_pre;
	for (auto i : frees) {
		assert(cyc[i] == -1);
		if (pre[i] <= 0) {
			pre[i] = 0;
			cyc[i] = 1;
		} else {
			cyc[i] = pos;
		}
	}
	for (int i = 1; i <= n; ++i) {
		assert(~pre[i] && ~cyc[i]);
		if (pre[i] == 0) pot_0[cyc[i]].emplace_back(i);
		else pot[cyc[i]].emplace_back(pre[i], i);
	}
//	for (int i = 1; i <= n; ++i)
//		printf("nxt :: %d %d\n", pre[i], cyc[i]);
	for (int l = 1; l <= n; ++l) {
		if (pot_0[l].empty()) continue;
		auto v0 = pot_0[l];
		auto v1 = pot[l];
		assert((int) v0.size() % l == 0);
		for (int i = 0; i < (int) v0.size(); i += l) {
			for (int j = 0; j < l - 1; ++j)
				p[v0[i + j]] = v0[i + j + 1];
			p[v0[i + l - 1]] = v0[i];	
		}
		int last = v0[0];
		sort(v1.begin(), v1.end());
		for (int i = 0, j; i < (int) v1.size(); i = j) {
			for (j = i; j < (int) v1.size() && v1[j].first == v1[i].first; ++j)
				p[v1[j].second] = last;
			last = v1[i].second;
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", p[i], " \n"[i == n]);
	exit(0);
}
int main() {
	scanf("%d", &n);
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		pre[i] = read(), cyc[i] = read();
		if (~cyc[i]) mark[cyc[i]] = true;
		if (~cyc[i] && ~pre[i]) mx = max(mx, pre[i]);
	}
	vector<int> pot;
	for (int i = 1; i <= n; ++i) {
		if (~cyc[i] || pre[i] <= mx) continue;
		pot.emplace_back(i);
	}
	if (!mark[1]) {
		mark[1] = true;
		for (auto i : pot)
			cyc[i] = 1;
		check();
		mark[1] = false;
	}
	for (int l = 1; l <= n; ++l) {
		if (!mark[l]) continue;
		for (auto i : pot)
			cyc[i] = l;
		check();
	}
	puts("-1");
	return 0;
}