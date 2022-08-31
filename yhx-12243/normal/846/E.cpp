#include <bits/stdc++.h>
#define N 100034
#define M 256101
using namespace std;

typedef long long ll;
const ll INF = 0x188434861e654c51ll;

int n, i;
int p[N], fc[N], nc[N];
ll a[N], b[N], k[N];
ll f[N], limit[N];

inline void link(int x, int px) {nc[x] = fc[px]; fc[px] = x;}

void dfs(int x){
	int y;
	f[x] = b[x] - a[x];
	for(y = fc[x]; y; y = nc[y]){
		dfs(y);
		if(f[y] >= 0) f[x] += f[y];
		else f[y] <= -limit[y] ? f[x] = -INF : (f[x] += f[y] * k[y]);
		f[x] < -INF ? f[x] = -INF : 0;
		assert(f[x] >= -INF);
	}
}

int main(){
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) scanf("%I64d", b + i);
	for(i = 1; i <= n; ++i) scanf("%I64d", a + i);
	for(i = 2; i <= n; ++i){
		scanf("%d%I64d", p + i, k + i);
		link(i, p[i]); limit[i] = INF / k[i];
	}
	dfs(1);
	puts(f[1] >= 0 ? "YES" : "NO");
	return 0;
}