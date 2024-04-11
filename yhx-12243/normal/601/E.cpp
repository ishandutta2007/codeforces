#include <bits/stdc++.h>
#define N 34147
#define K 1034
#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
using namespace std;

typedef vector <int> vec;
typedef long long ll;
const ll base = 10000019, mod = 1000000007;

struct exhibit{
	int w, c, l, r;
	exhibit (int w0 = 0, int c0 = 0, int l0 = 1, int r0 = -1): w(w0), c(c0), l(l0), r(r0) {}
	exhibit * read(int l0 = 1) {scanf("%d%d", &c, &w); l = l0; return this;}
}e[N];

int n, q, t = 1, W;
int op, i;
ll __empty__[K];
vec st[N << 2];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}

void add(int id, int L, int R, int ql, int qr, int v){
	if(ql <= L && R <= qr) {st[id].push_back(v); return;}
	segc;
	if(ql <= M) add(lc, L, M, ql, min(qr, M), v);
	if(qr > M) add(rc, M + 1, R, max(ql, M + 1), qr, v);
}

void solve(int id, int L, int R, ll *f){
	int i, j, n = (int)st[id].size();
	ll g[K]; memcpy(g, f, sizeof g);
	for(i = 0; i < n; ++i){
		exhibit &t = e[st[id][i]];
		for(j = W; j >= t.w; --j)
			up(g[j], g[j - t.w] + t.c);
	}
	if(L == R){
		ll res = 0;
		for(i = W; i; --i) res = (res * base + g[i]) % mod;
		printf("%d\n", (int)res); return;
	}
	segc; solve(lc, L, M, g); solve(rc, M + 1, R, g);
}

int main(){
	scanf("%d%d", &n, &W);
	for(i = 1; i <= n; ++i) e[i].read();
	for(scanf("%d", &q); q; --q)
		switch(scanf("%d", &op), op){
			case 1: e[++n].read(t); break;
			case 2: scanf("%d", &i); e[i].r = t - 1; break;
			case 3: ++t; break;
		}
	--t;
	for(i = 1; i <= n; ++i)
		if(e[i].l <= (~e[i].r ? e[i].r : (e[i].r = t)))
			add(1, 1, t, e[i].l, e[i].r, i);
	solve(1, 1, t, __empty__);
	return 0;
}