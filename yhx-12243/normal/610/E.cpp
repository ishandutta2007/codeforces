#include <bits/stdc++.h>
#define N 256101
#define K 10
#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
using namespace std;

struct node{
	int c[K][K]; char l, r, tag;
	node (char p = 0): l(p), r(p), tag(0) {memset(c, 0, sizeof c);}
}st[N << 2];

int n, q, k;
int op, l, r;
char s[N];

node merge(const node l, const node r){
	int i, j;
	node ret; ret.l = l.l; ret.r = r.r;
	for(i = 0; i < k; ++i)
		for(j = 0; j < k; ++j)
			ret.c[i][j] = l.c[i][j] + r.c[i][j];
	++ret.c[l.r - 'a'][r.l - 'a'];
	return ret;
}

void build(int id, int L, int R){
	if(L == R) {st[id] = node(s[L]); return;}
	segc; build(lc, L, M); build(rc, M + 1, R);
	st[id] = merge(st[lc], st[rc]);
}

void push_down(int id, int lc, int rc, int lw, int rw){
	char v = st[id].tag;
	st[lc] = node(v); st[lc].tag = v; st[lc].c[v - 'a'][v - 'a'] = lw;
	st[rc] = node(v); st[rc].tag = v; st[rc].c[v - 'a'][v - 'a'] = rw;\
	st[id].tag = 0;
}

void adj(int id, int L, int R, int ql, int qr, char v){
	if(ql <= L && R <= qr){
		st[id] = node(v); st[id].tag = v;
		st[id].c[v - 'a'][v - 'a'] = R - L;
		return;
	}
	segc;
	if(st[id].tag) push_down(id, lc, rc, M - L, R - M - 1);
	if(ql <= M) adj(lc, L, M, ql, min(qr, M), v);
	if(qr > M) adj(rc, M + 1, R, max(ql, M + 1), qr, v);
	st[id] = merge(st[lc], st[rc]);
}

int main(){
	int i, j, ans;
	scanf("%d%d%d%s", &n, &q, &k, s + 1);
	build(1, 1, n);
	for(; q; --q)
		if(scanf("%d", &op), op == 1){
			scanf("%d%d%1s", &l, &r, s);
			adj(1, 1, n, l, r, *s);
		}else{
			scanf("%s", s);
			node &w = st[1]; ans = 0;
			for(i = 0; i < k - 1; ++i)
				for(j = i + 1; j < k; ++j)
					ans += w.c[s[i] - 'a'][s[j] - 'a'];
			printf("%d\n", n - ans);
		}
	return 0;
}