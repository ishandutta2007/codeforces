#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=19, M=1<<N|7;
int n, m, popcnt[M];
ll f[N][M], g[N][M], h[400], ans[M], tmp[N][M];
char str[N][N];
map<vector<int>, int>id;
inline void FWT_or(ll *f, int op) {
	for (int len=2, p=1; len<=(1<<n); p=len, len<<=1)
		for (int i=0; i<(1<<n); i+=len)
			for (int j=0; j<p; j++) f[i|j|p]+=op*f[i|j];
}
void dfs(int x, int lst, vector<int>&now, int d) {
	if (!x) {
		id[now]=++m;
		for (int i=0; i<(1<<n); i++)
			if ((n-popcnt[i])&1) h[m]-=tmp[d][i];
			else h[m]+=tmp[d][i];
		return;
	}
	for (int i=min(x, lst); i; i--) {
		for (int j=0; j<(1<<n); j++) tmp[d+1][j]=tmp[d][j]*g[i][j];
		now.push_back(i), dfs(x-i, i, now, d+1), now.pop_back();
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read();
	for (int i=0; i<n; i++) scanf("%s", str[i]);
	for (int i=1; i<(1<<n); i++) popcnt[i]=popcnt[i>>1]+(i&1);
	for (int i=0; i<n; i++) f[i][1<<i]=1;
	for (int s=1; s<(1<<n); s++)
		for (int i=0; i<n; i++) {
			if (~s>>i&1) continue;
			for (int j=0; j<n; j++) {
				if ((s>>j&1) || str[i][j]==48) continue;
				f[j][s|1<<j]+=f[i][s];
			}
			g[popcnt[s]][s]+=f[i][s];
		}
	for (int i=1; i<=n; i++) FWT_or(g[i], 1);
	vector<int>now; fill(tmp[0], tmp[0]+(1<<n), 1), dfs(n, n, now, 0);
	for (int s=0; s<(1<<n-1); s++) {
		now.clear();
		for (int l=0, r=0; l<n; l=++r) {
			while (r+1<n && (s>>r)&1) r++;
			now.push_back(r-l+1);
		}
		sort (now.begin(), now.end(), greater<int>()), ans[s]=h[id[now]];
	}
	for (int i=0; i<n-1; i++)
		for (int s=0; s<(1<<n-1); s++)
			if (s>>i&1) ans[s^1<<i]-=ans[s];
	for (int s=0; s<(1<<n-1); s++) printf("%lld ", ans[s]);
	return 0;
}