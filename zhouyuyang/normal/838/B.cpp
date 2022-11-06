#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5L + 11, M = N * 2;
int a[M], b[M], c[M];
int back[M];
struct SegTree {
	ll flag[N * 8];
	ll val[N * 4];
	void push(int x) {
		val[x] += flag[x];
		flag[2 * x] += flag[x];
		flag[2 * x + 1] += flag[x];
		flag[x] = 0;
	}
	#define m (l + r) / 2
	void change(int l, int r, int ql, int qr, int c, int x = 1) {
		//if(x == 1) cout << l << ' ' << r << ' ' << ql << ' ' << qr << '\n';
		push(x);
		if(ql == l && qr == r) {
			flag[x] = c;
			push(x);
		} else {
			if(qr <= m) {
				change(l, m, ql, qr, c, 2 * x);
				push(2 * x + 1);
			} else if(ql >= m) {
				push(2 * x);
				change(m, r, ql, qr, c, 2 * x + 1);
			} else {
				change(l, m, ql, m, c, 2 * x);
				change(m, r, m, qr, c, 2 * x + 1);
			}
			val[x] = min(val[2 * x], val[2 * x + 1]);
		}
	}
	ll query(int l, int r, int ql, int qr, int x = 1) {
		push(x);
		if(ql == l && qr == r)
			return val[x];
		if(qr <= m)
			return query(l, m, ql, qr, 2 * x);
		else if(ql >= m)
			return query(m, r, ql, qr, 2 * x + 1);
		else
			return min(query(l, m, ql, m, 2 * x),
				query(m, r, m, qr, 2 * x + 1));
	}
	#undef m
}st;
vector <int> e[N];
int cnt = 0;
int in[N], out[N], id[N];
void dfs(int x) {
	id[x] = ++ cnt;
	in[x] = cnt;
	for(int i : e[x])
		dfs(i);
	out[x] = cnt;
}
int n;
ll query(int x) {
	return st.query(1, n + 1, id[x], id[x] + 1) - back[x];
}
int main() {
	int q; cin >> n >> q;
	for(int i = 1; i <= 2 * n - 2; i ++) {
		scanf("%d%d%d", a + i, b + i, c + i);
		if(i <= n - 1) e[a[i]].push_back(b[i]);
		else back[a[i]] = c[i];
	}
	dfs(1);
	for(int i = 1; i <= n - 1; i ++)
		st.change(1, n + 1, in[b[i]], out[b[i]] + 1, c[i]);
	for(int i = 2; i <= n; i ++)
		st.change(1, n + 1, id[i], id[i] + 1, back[i]);
	
	while(q --) {
		int t, u, v; scanf("%d%d%d", &t, &u, &v);
		if(t == 1) {
			int i = u, w = v;
			if(i <= n - 1) {
				st.change(1, n + 1, in[b[i]], out[b[i]] + 1, w - c[i]);
				c[i] = w;
			} else {
				st.change(1, n + 1, id[a[i]], id[a[i]] + 1, w - c[i]);
				back[a[i]] = w;
				c[i] = w;
			}
		} else {
			ll ans = st.query(1, n + 1, in[u], out[u] + 1) - query(u) + query(v);
			if(id[v] >= in[u] && id[v] <= out[u])
				ans = min(ans, query(v) - query(u));
			printf("%lld\n", ans);
		}
	}
}