#include <bits/stdc++.h>
#define N 100034
using namespace std;

typedef long long ll;
const int MAX = 1000000007;

struct node {ll sum; int v, lc, rc;} st[N << 5];

int n, q, cnt = 1;
int h[N];

int add(int id, int L, int R, int h, int v){
	if(!id) id = ++cnt;
	if(L == R) {st[id].v += v; st[id].sum += (ll)L * v; return id;}
	int M = L + R - 1 >> 1;
	h <= M ? st[id].lc = add(st[id].lc, L, M, h, v) : (st[id].rc = add(st[id].rc, M + 1, R, h, v));
	st[id].v = st[id].lc[st].v + st[id].rc[st].v;
	st[id].sum = st[id].lc[st].sum + st[id].rc[st].sum;
	return id;
}

double query(int id, int L, int R, ll V){
	int M, oc = 0; ll need, oV = 0;
	for(; L < R && id; ){
		M = L + R - 1 >> 1;
		need = (ll)M * (st[id].lc[st].v + oc) - (st[id].lc[st].sum + oV);
		if(V > need){
			oc += st[id].lc[st].v; oV += st[id].lc[st].sum;
			id = st[id].rc; L = M + 1;
		}else {id = st[id].lc, R = M;}
	}
	return (double)(V + oV) / (double)oc;
}

int main(){
	int i, op; ll t0;
	scanf("%d%d", &n, &q);
	for(i = 1; i <= n; ++i) {scanf("%d", h + i); add(1, 0, MAX, h[i], 1);}
	for(; q; --q)
		if(scanf("%d", &op), op == 1){
			scanf("%d%d", &i, h);
			add(1, 0, MAX, h[i], -1);
			add(1, 0, MAX, h[i] = *h, 1);
		}else{
			scanf("%lld", &t0);
			printf("%.8lg\n", query(1, 0, MAX, t0));
		}
	return 0;
}