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
#define link(o) sam[o].link
#define len(o) sam[o].len
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5;

struct state {
	int tr[26], pos, link, len;
} sam[N];
int n_cnt, lst;
void Init() {
	memset(sam, 0, sizeof(sam));
	n_cnt = lst = 0;
	link(0) = -1; len(0) = pos(0) = 0;
	for(int c = 0; c < 26; ++c)
		tr(0, c) = 0;
}
void Insert(int c, int idx) {
	int np = ++n_cnt, p = lst;
	pos(np) = len(np) = idx;
	for(; ~p && !tr(p, c); p = link(p))
		tr(p, c) = np;
	if(p == -1) link(p) = 0;
	else {
		int q = tr(p, c);
		if(len(q) == len(p) + 1) link(np) = q;
		else {
			int nq = ++n_cnt;
			len(nq) = len(p) + 1;
			for(int i = 0; i < 26; ++i)
				tr(nq, i) = tr(q, i);
			link(nq) = link(q); link(q) = link(np) = nq;
			for(; ~p && tr(p, c) == q; p = link(p))
				tr(p, c) = nq;
		}
	}
	lst = np;
}
std::vector <int> ch[N];
int cnt[N]; ll ans = 0;
void Dfs(int u) {
	cnt[u] = (pos(u) != 0);
	for(int v : ch[u]) {
		Dfs(v);
		cnt[u] += cnt[v];
	}
	if(u) ans += 1LL * (len(u) - len(link(u))) * cnt[u] * cnt[u];
}
void Calc() {
	memset(cnt, 0, sizeof(cnt)); ans = 0;
	for(int i = 0; i <= n_cnt; ++i) ch[i].clear();
	for(int i = 1; i <= n_cnt; ++i)
		ch[link(i)].push_back(i);
	Dfs(0);
}

char s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		Init();
		for(int i = 1; i <= len; ++i)
			Insert(s[i] - 'a', i);
		Calc();
		printf("%lld\n", ans);
	} return 0;
}