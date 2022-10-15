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
#define siz(o, c) sam[o].siz[c]
#define len(o) sam[o].len
#define link(o) sam[o].link
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e6 + 5, MOD = 1e9 + 7, INF = 0x3f3f3f3f;

struct State {
	int tr[26], siz[3], len, link;
} sam[N];
int n_cnt;
void Init() { link(0) = -1; }
int Insert(int lst, int c) {
	int np = 0, p = lst;
	if(!tr(p, c)) {
		np = ++n_cnt;
		len(np) = len(lst) + 1;
		for(; ~p && !tr(p, c); p = link(p))
			tr(p, c) = np;
	}
	if(p == -1) return link(np) = 0, np;
	else {
		int q = tr(p, c);
		if(len(q) == len(p) + 1)
			return np ? (link(np) = q, np) : q;
		else {
			int nq = ++n_cnt;
			len(nq) = len(p) + 1;
			for(int i = 0; i < 26; ++i)
				tr(nq, i) = tr(q, i);
			for(; ~p && tr(p, c) == q; p = link(p))
				tr(p, c) = nq;
			link(nq) = link(q); link(q) = nq;
			return np ? (link(np) = nq, np) : nq;
		}
	}
}
void Insert(char str[], int idx) {
	int cur_len = strlen(str + 1);
	for(int i = 1, lst = 0; i <= cur_len; ++i) {
		lst = Insert(lst, str[i] - 'a');
		++siz(lst, idx);
	}
}

char t[N]; int len_mn, d[N], cnt[N][3];
std::vector <int> E[N];
void Plus(int &x, int y) { x += y; x -= x >= MOD ? MOD : 0; }
void Minus(int &x, int y) { x -= y; x += x < 0 ? MOD : 0; }
void Dfs(int u) {
	for(int i = 0; i < 3; ++i)
		cnt[u][i] = siz(u, i);
	for(int v : E[u]) {
		Dfs(v);
		for(int i = 0; i < 3; ++i)
			cnt[u][i] += cnt[v][i];
	}
	int ans = 1;
	for(int i = 0; i < 3; ++i)
		ans = 1LL * ans * cnt[u][i] % MOD;
	Plus(d[len(link(u)) + 1], ans);
	Minus(d[len(u) + 1], ans);
}
void Calc() {
	for(int i = 1; i <= n_cnt; ++i)
		E[link(i)].push_back(i);
	Dfs(0);
	for(int i = 1; i <= len_mn; ++i)
		Plus(d[i], d[i - 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		Init();
		len_mn = INF;
		for(int i = 0; i < 3; ++i) {
			scanf("%s", t + 1);
			len_mn = std::min(len_mn, (int)strlen(t + 1));
			Insert(t, i);
		}
		Calc();
		for(int i = 1; i <= len_mn; ++i)
			printf("%d ", d[i]);
		printf("\n");
	} return 0;
}