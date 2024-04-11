#include <bits/stdc++.h>
#define N 100034
#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
using namespace std;

const double eps = 1e-7;

struct node{
	double l, r;
	node (double lr = 0.0, double rr = 0.0): l(lr), r(rr) {}
}st[N << 2];

int n, q;

double readDouble(){
	int a, b;
	scanf("%d%d", &a, &b);
	return (double)a / (double)b;
}

node merge(const node l, const node r){
	node ret;
	double D = 1.0 - (1.0 - r.l) * l.r;
	if(D < eps){
		ret.l = 0.0; ret.r = r.r;
	}else{
		ret.l = l.l * r.l / D;
		ret.r = r.r + l.r * r.l * (1.0 - r.r) / D;
	}
	return ret;
}

void build(int id, int L, int R){
	if(L == R) {double p = readDouble(); st[id] = node(p, p); return;}
	segc; build(lc, L, M); build(rc, M + 1, R);
	st[id] = merge(st[lc], st[rc]);
}

void adj(int id, int L, int R, int h, double v){
	if(L == R) {st[id] = node(v, v); return;}
	segc; h <= M ? adj(lc, L, M, h, v): adj(rc, M + 1, R, h, v);
	st[id] = merge(st[lc], st[rc]);
}

node range(int id, int L, int R, int ql, int qr){
	if(ql <= L && R <= qr) return st[id];
	segc; node ret;
	if(ql <= M){
		ret = range(lc, L, M, ql, min(qr, M));
		if(qr > M) ret = merge(ret, range(rc, M + 1, R, max(ql, M + 1), qr));
	}else if(qr > M)
		ret = range(rc, M + 1, R, max(ql, M + 1), qr);
	return ret;
}

int main(){
	int op, u, v; double p;
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	for(; q; --q)
		if(scanf("%d", &op), op == 1){
			scanf("%d", &v); p = readDouble();
			adj(1, 1, n, v, p);
		}else{
			scanf("%d%d", &u, &v);
			p = range(1, 1, n, u, v).l;
			printf("%.10lf\n", p);
		}
	return 0;
}

/*
i . . . . . . . j j+1 . . . . . n n+1
l_1 ------------------->            |
r_1 |               --->            |
l_2 |               |  ---------------->
r_2 |               |  |            --->

     5   6   7
l_1  ---->     a
r_1  ---->     a
l_2      ----> b
r_2      ----> b

l_1 l_2 + l_1 (1 - l_2) r_1 l_2 + ...

a b + a (1 - b) a b + a (1 - b) a (1 - b) a b + ...

r_2 + (1 - r_2) r_1 l_2 + (1 - r_2) r_1 (1 - l_2) r_1 l_2 + ...
*/