#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=122;
ll f[N][N];
inline void work() {
	ll t=read(), x=read(), y=read(); t-=x+y;
	if (t<0) {puts("NO"); return;}
	for (int i=0; i<=120; i++)
		for (int j=0; j<=120; j++) f[i][j]=0;
	f[0][0]=t;
	for (int i=0; i<120; i++)
		for (int j=0; j<120; j++) f[i+1][j]+=f[i][j]/2, f[i][j+1]+=(f[i][j]+1)/2;
	int u=0, v=0;
	while (u<=x && v<=y) {
		if (u==x && v==y) {puts("YES"); return;}
		f[u][v]&1?u++:v++;
	}
	puts("NO");
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	for (int T=read(); T; T--) work();
	return 0;
}