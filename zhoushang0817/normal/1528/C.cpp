#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)
#define mid ((l + r) >> 1)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 3e5 + 10;

struct ST {
	struct Node {
		int v, l;
		Node() {l = -1;}
	}	o[N << 2];
	void Update(int p, int v) {
		o[p].v = o[p].l = v;
	}
	void PushDown(int p) {
		if (o[p].l != -1) {
			Update(p << 1, o[p].l);
			Update(p << 1 | 1, o[p].l);
			o[p].l = -1;
		}
	}
	void Mdf(int p, int l, int r, int tl, int tr, int v) {
		if (tl <= l && r <= tr) return Update(p, v); PushDown(p);
		if (tl <= mid) Mdf(p << 1, l, mid, tl, tr, v);
		if (tr > mid) Mdf(p << 1 | 1, mid + 1, r, tl, tr, v);
	}
	int Qry(int p, int l, int r, int x) {
		if (l == r) return o[p].v; PushDown(p);
		if (x <= mid) return Qry(p << 1, l, mid, x);
		else return Qry(p << 1 | 1, mid + 1, r, x);
	}
	void Build(int p, int l, int r) {
		o[p].l = -1, o[p].v = 0;
		if (l == r) return;
		Build(p << 1, l, mid);
		Build(p << 1 | 1, mid + 1, r);
	}
	void Output(int p, int l, int r) {
		if (l == r) return cout << o[p].v << " ", void();
		PushDown(p);
		Output(p << 1, l, mid);
		Output(p << 1 | 1, mid + 1, r);
	}
}	st;

vector <int> G1[N], G2[N];
int T, n, L[N], R[N], cur_dfn, ans = 1;

void dfs2(int x) {
	L[x] = ++cur_dfn;
	for (int v : G2[x])
		dfs2(v);
	R[x] = cur_dfn;
}

void dfs1(int x, int temp) {
	for (int v : G1[x]) {
		int t = st.Qry(1, 1, n, L[v]);
		if (!t) temp++;
		ans = max(ans, temp);
		if (t) st.Mdf(1, 1, n, L[t], R[t], 0);
		st.Mdf(1, 1, n, L[v], R[v], v);
		dfs1(v, temp);
		if (!t) temp--;
		st.Mdf(1, 1, n, L[v], R[v], 0);
		if (t) st.Mdf(1, 1, n, L[t], R[t], t);
	}
}

void init () {
	cur_dfn = 0, st.Build(1, 1, n);
	ans = 1;
	for (int i = 1; i <= n; i++)
		G1[i].clear(), G2[i].clear();
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	for (read(T); T; T--) {
		read(n), init();
		for (int i = 2; i <= n; i++) {
			int x; read(x);
			G1[x].pb(i);
		}
		for (int i = 2; i <= n; i++) {
			int x; read(x);
			G2[x].pb(i);
		}
		dfs2(1), dfs1(1, 0);
		print(ans, '\n');
	}
	return 0;
}