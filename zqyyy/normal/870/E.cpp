// LUOGU_RID: 90807533
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use it in interactive problems!!!
	static char *p1, *p2, buf[1<<10];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<10, stdin), p1==p2?'\n':*p1++):*p1++; // '\n' for function isspace in function readstr 
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc(); (*s++)='\0';
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7, mod=1e9+7;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, tot, pa[N], sz[N], fl[N];
int find(int x) {return pa[x]^x?pa[x]=find(pa[x]):x;}
inline void unin(int x, int y) {
	x=find(x), y=find(y);
	if (x==y) {fl[x]=1; return;}
	pa[x]=y, sz[y]+=sz[x], fl[y]|=fl[x];
}
map<int, int>hx, hy;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read();
	for (int i=1; i<=n; i++) {
		int x=read(), y=read();
		int &u=hx[x]; if (!u) u=++tot, pa[u]=u, sz[u]=1;
		int &v=hy[y]; if (!v) v=++tot, pa[v]=v, sz[v]=1;
		unin(u, v);
	}
	int ans=1;
	for (int i=1; i<=tot; i++) if (find(i)==i) mul(ans, qpow(2, sz[i])-1+fl[i]);
	printf("%d\n", ans);
	return 0;
}