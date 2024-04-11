#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=50, M=1<<23|7, mod=998244853;
inline void inc(int &x, int y) {x+=y-mod, x+=x>>31&mod;}
inline void dec(int &x, int y) {x-=y, x+=x>>31&mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
int n, pa[N], sz[N], f[M], g[M], id[N], popcnt[M];
int find(int x) {return x^pa[x]?pa[x]=find(pa[x]):x;}
inline void unin(int x, int y) {x=find(x), y=find(y); if (x^y) pa[y]=x, sz[x]+=sz[y];}
bool flg[N][N];
char str[N][N];
inline void FWT(int n, int *f) {
	for (int len=2, p=1; len<=n; p=len, len<<=1)
		for (int i=0; i<n; i+=len)
			for (int j=0; j<p; j++) inc(f[i|j|p], f[i|j]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for (int i=1; i<=n; i++) pa[i]=i, sz[i]=1;
	for (int i=1; i<=n; i++) {
		scanf("%s", str[i]+1);
		for (int j=1; j<i; j++)
			if (str[i][j]=='A') unin(i, j);
	}
	int m=0;
	for (int i=1; i<=n; i++)
		if (find(i)==i) id[i]=sz[i]>1?m++:-1;
		else id[i]=id[find(i)];
	if (!m) printf("%d\n", n-1), exit(0);
	for (int i=1; i<=n; i++)
		for (int j=1; j<i; j++) {
			if (str[i][j]!='X') continue;
			int p=id[find(i)], q=id[find(j)];
			if (!~p || !~q) continue;
			if (p==q) puts("-1"), exit(0);
			flg[p][q]=flg[q][p]=true;
		}
	g[0]=1;
	for (int i=1; i<(1<<m); i++) {
		popcnt[i]=popcnt[i>>1]+(i&1);
		int lb=__builtin_ctz(i&-i); g[i]=g[i^(i&-i)];
		for (int j=0; j<m; j++)
			if (i>>j&1) g[i]&=!flg[j][lb];
	}
	FWT(1<<m, g); int ans=n-1;
	for (int i=0; i<(1<<m); i++) f[i]=1;
	while (++ans) {
		for (int i=0; i<(1<<m); i++) mul(f[i], g[i]);
		int res=0;
		for (int i=0; i<(1<<m); i++) (m-popcnt[i])&1?dec(res, f[i]):inc(res, f[i]);
		if (res) printf("%d\n", ans), exit(0);
	}
	return 0;
}