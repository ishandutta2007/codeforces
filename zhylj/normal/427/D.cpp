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
#define siz(o, i) sam[o].siz[i]
#define len(o) sam[o].len
#define link(o) sam[o].link
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5, INF = 0x3f3f3f3f;

struct State {
	int tr[26], siz[2], len, link;
} sam[N];
int n_cnt;
void Init() {
	n_cnt = 0;
	memset(sam, 0, sizeof(sam));
	link(0) = -1;
}
int Insert(int lst, int c) {
	int np = 0, p = lst;
	if(!tr(p, c)) {
		np = ++n_cnt;
		len(np) = len(p) + 1;
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
			for(; ~p && tr(p, c) == q; p = link(p))
				tr(p, c) = nq;
			for(int i = 0; i < 26; ++i)
				tr(nq, i) = tr(q, i);
			link(nq) = link(q); link(q) = nq;
			return np ? (link(np) = nq, np) : nq;
		}
	}
}
void Insert(char s[], int idx) {
	int len = strlen(s + 1);
	for(int i = 1, lst = 0; i <= len; ++i) {
		lst = Insert(lst, s[i] - 'a');
		++siz(lst, idx);
	}
}

char t[N];
int ans, cnt[N][2];
std::vector <int> E[N];
void Dfs(int u) {
	for(int i = 0; i < 2; ++i)
		cnt[u][i] += siz(u, i);
	for(int v : E[u]) {
		Dfs(v);
		for(int i = 0; i < 2; ++i)
			cnt[u][i] += cnt[v][i];
	}
	if(u && cnt[u][0] == 1 && cnt[u][1] == 1)
		ans = std::min(ans, len(link(u)) + 1);
}
void Calc() {
	ans = INF;
	for(int i = 1; i <= n_cnt; ++i) 
		E[link(i)].push_back(i);
	Dfs(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		Init();
		for(int i = 0; i < 2; ++i) {
			scanf("%s", t + 1);
			Insert(t, i);
		}
		Calc();
		printf("%d\n", ans == INF ? -1 : ans);
	} return 0;
}