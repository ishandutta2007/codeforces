#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1007, M=1e6+7;
int n, m, a[N], mat[N], val[M];
bool vis[N];
vector<int>G[M];
bool dfs(int x) {
	for (int y:G[x]) {
		if (vis[y]) continue; vis[y]=true;
		if (!mat[y] || dfs(mat[y])) return mat[y]=x, true;
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read();
	for (int i=1; i<=n; i++) {
		a[i]=read();
		for (int j=1; j<=n; j++) val[++m]=a[i]*j;
	}
	sort (val+1, val+m+1), m=unique(val+1, val+m+1)-val-1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) G[lower_bound(val+1, val+m+1, a[i]*j)-val].push_back(i);
	ll ans=0;
	for (int i=1, c=0; c<n; i++)
		if (dfs(i)) c++, ans+=val[i], fill(vis+1, vis+n+1, 0);
	printf("%lld\n", ans);
	return 0;
}