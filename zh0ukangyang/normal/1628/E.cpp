#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1.2e6 + 7;
struct ST {
	int tp;
	int mx[21][N];
	void mk() {
		L(i, 1, 20) L(j, 1, tp - (1 << i) + 1) 
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
	}
} st;	
int lg[N];

int n, m, tot, fa[N];
struct edge {
	int u, v, w;
} e[N];
int f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
} 
vi E[N];
int idt, dfn[N], val[N], rp[N], arr[N];
void dfs1 (int x) {
	++idt, arr[idt] = x, dfn[x] = idt;
	for (const int &v : E[x]) 
		rp[v] = rp[x] + 1, dfs1 (v), ++idt, arr[idt] = x;
} 
int dis (int u, int v) {
	int l = dfn[u], r = dfn[v], p;
	if(l > r) swap(l, r); 
	p = lg[r - l + 1];
	return max(st.mx[p][l], st.mx[p][r - (1 << p) + 1]);
}


int cv[N], fr[N], mx[N], tag[N], lb[N];
void AD (int x, int w) {
	tag[x] = w;
	if(w == 0) mx[x] = -1, lb[x] = 0;
	else mx[x] = cv[x], lb[x] = fr[x];
}
void pushdown (int x) {
	if(tag[x] != -1) {
		AD(x << 1, tag[x]);
		AD(x << 1 | 1, tag[x]);
		tag[x] = -1;
	}
} 
void upd (int x) {
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
	if(lb[x << 1] && lb[x << 1 | 1]) mx[x] = max(mx[x], dis(lb[x << 1], lb[x << 1 | 1]));
	lb[x] = lb[x << 1] ? lb[x << 1] : lb[x << 1 | 1];
}
void build (int x, int L, int R) {
	fr[x] = L;
	if(L == R) return cv[x] = -1, mx[x] = -1, void ();
	int mid = (L + R) >> 1;
	build (x << 1, L, mid);
	build (x << 1 | 1, mid + 1, R);
	cv[x] = max(max(cv[x << 1], cv[x << 1 | 1]), dis(L, mid + 1));
} 
void add (int x, int L, int R, int l, int r, int w) {
	if (l <= L && R <= r) return AD(x, w), void ();
	int mid = (L + R) >> 1;
	pushdown(x);
	if(l <= mid) add (x << 1, L, mid, l, r, w);
	if(r > mid) add (x << 1 | 1, mid + 1, R, l, r, w);
	upd (x);
}
bool check(int x, int L, int R, int p) {
	if(L == R) return tag[x];
	pushdown (x);
	int mid = (L + R) >> 1;
	if(p <= mid) return check(x << 1, L, mid, p);
	else return check(x << 1 | 1, mid + 1, R, p);
} 

int main () { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m;
	L(i, 2, N - 1) lg[i] = lg[i >> 1] + 1;
	L(i, 1, n - 1) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e + 1, e + n, [&] (edge a, edge b) {
		return a.w < b.w;
	});
	L(i, 1, n * 2) {
		f[i] = i;
	}
	L(i, 1, n) val[i] = -1;
	tot = n; 
	L(i, 1, n - 1) {
		int u = find(e[i].u), v = find(e[i].v);
		assert (u != v);
		++tot, val[tot] = e[i].w, fa[u] = f[u] = tot, fa[v] = f[v] = tot;
		E[tot].push_back(u);
		E[tot].push_back(v);
	}
	dfs1 (tot);
	L(i, 1, idt) st.mx[0][i] = val[arr[i]];
	st.tp = idt, st.mk();
	me(mx, -1);
	build (1, 1, n);
	while (m--) {
		int op, l, r, x;
		cin >> op ;
		if(op == 3) {
			cin >> x;
			l = r = x;
			bool t = check(1, 1, n, x);
			if(!t) {
				add (1, 1, n, x, x, 1);
			}
			cout << mx[1] << '\n';
			if(!t) {
				add (1, 1, n, x, x, 0);
			}
		} else {
			cin >> l >> r;
			if(op == 1) {
				add (1, 1, n, l, r, 1);
			} else {
				add (1, 1, n, l, r, 0);
			}
		}
	} 
	return 0;
}