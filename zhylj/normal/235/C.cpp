#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
#define tr(o, c) sam[o].tr[c]
#define pos(o) sam[o].pos
#define len(o) sam[o].len
#define link(o) sam[o].link
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2e6 + 5;

struct State {
	int tr[26], pos, len, link;
} sam[N];
int n_cnt, lst;
void Init() {
	n_cnt = lst = 0;
	memset(sam, 0, sizeof(sam));
	link(0) = -1;
}
void Insert(int c, int cur_len) {
	int np = ++n_cnt, p = lst; lst = np;
	len(np) = pos(np) = cur_len;
	for(; ~p && !tr(p, c); p = link(p))
		tr(p, c) = np;
	if(p == -1) link(np) = 0;
	else {
		int q = tr(p, c);
		if(len(q) == len(p) + 1) link(np) = q;
		else {
			int nq = ++n_cnt;
			len(nq) = len(p) + 1;
			for(int i = 0; i < 26; ++i)
				tr(nq, i) = tr(q, i);
			for(; ~p && tr(p, c) == q; p = link(p))
				tr(p, c) = nq;
			link(nq) = link(q); link(q) = link(np) = nq;
		}
	}
}

int cnt[N];
std::vector <int> E[N];
void Dfs(int u) {
	if(pos(u)) cnt[u] = 1;
	for(int v : E[u]) {
		Dfs(v);
		cnt[u] += cnt[v];
	}
}
void Build() {
	for(int i = 1; i <= n_cnt; ++i)
		E[link(i)].push_back(i);
	Dfs(0);
}

char str[N], t[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		Init();
		for(int i = 1; i <= n; ++i)
			Insert(str[i] - 'a', i);
		Build();
		int q; rd(q);
		while(q--) {
			scanf("%s", t + 1);
			int m = strlen(t + 1); ll ans = 0;
			memcpy(t + m + 1, t + 1, m * sizeof(int));
			std::set <int> vis;
			for(int i = 1, u = 0, j = 0; i < m << 1; ++i) {
				int c = t[i] - 'a';
				for(; u && !tr(u, c); u = link(u))
					j = len(link(u));
				u = tr(u, c); ++j;
				for(; len(link(u)) >= m; u = link(u))
					j = len(link(u));
				if(j >= m && !vis.count(u)) {
					vis.insert(u);
					ans += cnt[u];
				}
			}
			printf("%lld\n", ans);
		}
	} return 0;
}