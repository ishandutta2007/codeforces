#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+c-48, c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=507, inf=0x3f3f3f3f;
const ll INF=1e18;
int n, m, u[N*N], v[N*N], w[N*N], dis[N][N];
inline void work() {
	n=read(), m=read();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			dis[i][j]=i==j?0:inf;
	for (int i=1; i<=m; i++) {
		u[i]=read(), v[i]=read(), w[i]=read();
		dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
	}
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				ckmin(dis[i][j], dis[i][k]+dis[k][j]);
	ll ans=INF;
	for (int i=1; i<=m; i++) {
		int num=min(dis[1][u[i]]+dis[v[i]][n], dis[1][v[i]]+dis[u[i]][n]);
		for (int x=1; x<=n; x++)
			ckmin(num, dis[1][x]+dis[x][n]+min(dis[u[i]][x], dis[v[i]][x])+1);
		ckmin(ans, (ll)w[i]*(num+1));
	}
	printf("%lld\n", ans);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}