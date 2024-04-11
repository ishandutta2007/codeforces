#include <bits/stdc++.h>
#define N 256101
using namespace std;

typedef long long ll;
typedef pair <int, int> pr;

struct seg{
	int l, r, y, w;
	seg (int l0 = 0, int r0 = 0, int y0 = 0, int w0 = 0): l(l0), r(r0), y(y0), w(w0) {}
	bool operator < (const seg &B) const {return y < B.y;}
};

pr D[N];
int F[N];
seg op[N << 1];
int cnt = 0;
int n, k, z;
int y[N];
int apr[N], last[N];
ll ans[N];

int Discretize(int n){
	int i, cnt = 0;
	sort(D, D + n);
	for(i = 0; i < n; ++i)
		if(i && D[i].first == D[i - 1].first)
			F[D[i].second] = cnt - 1;
		else{
			F[D[i].second] = cnt;
			D[cnt++] = D[i];
		}
	return cnt;
}

int main(){
	int i, u, v, w, h;
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; ++i){
		scanf("%d%d", &v, y + i);
		D[i] = pr(v, i);
		D[n + i] = pr(v + k, n + i);
	}
	z = Discretize(n << 1);
	for(i = 0; i < n; ++i){
		u = F[i]; v = F[n + i];
		op[cnt++] = seg(u, v, y[i], 1);
		op[cnt++] = seg(u, v, y[i] + k, -1);
	}
	sort(op, op + cnt);
	for(i = 0; i < cnt; ++i){
		for(v = op[i].l; v < op[i].r; ++v){
			w = D[v + 1].first - D[v].first;
			h = op[i].y - last[v];
			ans[apr[v]] += (ll)w * h;
			apr[v] += op[i].w;
			last[v] = op[i].y;
		}
	}
	for(i = 1; i <= n; ++i) printf("%I64d%c", ans[i], i == n ? 10 : 32);
	return 0;
}