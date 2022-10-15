#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
#define len(x) st[x].len
#define link(x) st[x].link
#define nxt(x, c) st[x].nxt[c]
#define pos(x) st[x].pos
#define val(x) seg[x].val
#define lc(x) seg[x].lc
#define rc(x) seg[x].rc
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 2e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, q; char str[kN], t[kN];

struct State {
	int len, link, pos, nxt[30];
} st[kN << 1];
std::vector <int> ch[kN << 1];
int cnt, lst;
void Init() { st[cnt = lst = 0] = (State) { 0, -1, 0, { } }; }
void Insert(char o_c) {
	int cur = ++cnt, c = o_c - 'a', p = lst;
	len(cur) = len(lst) + 1; pos(cur) = len(cur);
	for(; ~p && !nxt(p, c); p = link(p)) nxt(p, c) = cur;
	if(p == -1) link(cur) = 0;
	else {
		int q = nxt(p, c);
		if(len(q) == len(p) + 1) link(cur) = q;
		else {
			int nq; st[nq = ++cnt] = (State) { len(p) + 1, link(q), pos(q), { } };
			for(int i = 0; i < 26; ++i) nxt(nq, i) = nxt(q, i);
			for(; ~p && nxt(p, c) == q; p = link(p)) nxt(p, c) = nq;
			link(q) = link(cur) = nq;
		}
	}
	lst = cur;
}
void GetCh() { for(int i = 1; i <= cnt; ++i) ch[link(i)].push_back(i); }

struct Node {
	bool val; int lc, rc;
} seg[kN * 50];
int rt[kN << 1], cnt_node;
void Update(int o) { val(o) = (val(lc(o)) || val(rc(o))); }
void Merge(int &o, int A, int l, int r) {
	if(!o || !A) {
		o ^= A;
	} else {
		seg[++cnt_node] = seg[o];
		o = cnt_node;
		if(l == r) return;
		int mid = (l + r) >> 1;
		Merge(lc(o), lc(A), l, mid);
		Merge(rc(o), rc(A), mid + 1, r);
		Update(o);
	}
}
void Modify(int &o, int l, int r, int p) {
	if(!o) o = ++cnt_node;
	if(l == r) val(o) = true;
	else {
		int mid = (l + r) >> 1;
		if(p <= mid) Modify(lc(o), l, mid, p);
		else Modify(rc(o), mid + 1, r, p);
		Update(o);
	}
}
bool QueryExist(int o, int l, int r, int ql, int qr) {
	if(!o) return false;
	if(ql <= l && r <= qr) return val(o);
	int mid = (l + r) >> 1;
	if(ql <= mid && QueryExist(lc(o), l, mid, ql, qr)) return true;
	if(qr > mid && QueryExist(rc(o), mid + 1, r, ql, qr)) return true;
	return false;
}

void Dfs(int u) {
	if(pos(u) == len(u)) Modify(rt[u], 1, n, pos(u));
	for(auto v : ch[u]) {
		Dfs(v); Merge(rt[u], rt[v], 1, n);
	}
}

char vad_nxt[kN];
void Query(int l, int r, char t[]) {
	int m = strlen(t + 1), p = 0, cur_len;
	for(int i = 0; i <= m; ++i) vad_nxt[i] = 0;
	for(cur_len = 0; cur_len < m; ++cur_len) {
		for(int i = t[cur_len + 1] - 'a' + 1; i < 26; ++i) {
			if(nxt(p, i) && QueryExist(rt[nxt(p, i)], 1, n, l + cur_len, r)) {
				vad_nxt[cur_len] = i + 'a'; break;
			}
		}
		if(nxt(p, t[cur_len + 1] - 'a')) p = nxt(p, t[cur_len + 1] - 'a');
		else break;
	}
	if(cur_len == m) {
		for(int i = 0; i < 26; ++i) {
			if(nxt(p, i) && QueryExist(rt[nxt(p, i)], 1, n, l + cur_len, r)) {
				vad_nxt[cur_len] = i + 'a'; break;
			}
		}
	}
	for(int i = cur_len; ~i; --i) {
		if(vad_nxt[i]) {
			for(int j = 1; j <= i; ++j) printf("%c", t[j]);
			printf("%c\n", vad_nxt[i]);
			return;
		}
	}
	printf("-1\n");
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		scanf("%s", str + 1);
		n = strlen(str + 1);
		Init();
		for(int i = 1; i <= n; ++i) Insert(str[i]);
		GetCh(); Dfs(0);
		rd(q);
		while(q--) {
			int l, r; rd(l, r);
			scanf("%s", t + 1);
			Query(l, r, t);
		}
	} return 0;
}