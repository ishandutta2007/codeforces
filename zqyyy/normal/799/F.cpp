// LUOGU_RID: 90821929
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
typedef uint64_t ull;
mt19937 RAND(random_device{}());
ull rnd(ull l, ull r) {return uniform_int_distribution<ull>(l, r)(RAND);}
int n, m, pa[N];
int find(int x) {return x^pa[x]?pa[x]=find(pa[x]):x;}
ull a[N];
map<ull, vector<int> >mp;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), m=read(), iota(pa+1, pa+m+2, 1);
	for (int i=1; i<=n; i++) {
		int l=read(), r=read(); ull val=rnd(1, -1);
		a[l+1]^=val, a[r+1]^=val;
		for (int j=find(l); j<=r; j=pa[j]=find(j+1));
	}
	for (int i=1; i<=m; i++) a[i]^=a[i-1];
	for (int i=1; i<=m; i++) a[i]^=a[i-1], mp[a[i]].push_back(i);
	ll ans=0;
	for (auto &[x, vec]:mp) {
		int sz=vec.size(); ans+=sz*(sz+1ll)/2;
		for (int i=0; i<sz; i++) ans+=(ll)vec[i]*(i-(sz-1-i));
	}
	for (int l=1, r; l<=m; l=r+1) {
		l=r=find(l); if (l>m) break;
		while (r<m && find(r+1)==r+1) r++;
		ans-=(r-l+1)*(r-l+2ll)/2;
		for (int i=l; i<=r; i++) ans-=(ll)i*(i-l-(r-i));
	}
	printf("%lld\n", ans);
	return 0;
}