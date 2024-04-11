#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use it in interactive problems!!!
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc();
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
const int N=3e5+7, mod=998244353;
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
struct Query {int opt, x, y, z;} q[N];
int n, m, Q, a[N], b[N], lsh[N<<1], ans[N];
ll v[N<<1];
mt19937 RAND(random_device{}());
struct b1t {
	ll c[N];
	inline void init() {fill(c+1, c+n+1, 0);}
	inline void add(int p, ll x) {for (; p<=n; p+=p&-p) c[p]+=x;}
	inline ll ask(int p) {ll res=0; for (; p; p&=p-1) res+=c[p]; return res;}
	inline ll query(int l, int r) {return ask(r)-ask(l-1);}
}T;
inline void work() {
	for (int i=1; i<=m; i++) v[i]=RAND();
	T.init(); for (int i=1; i<=n; i++) T.add(i, v[b[i]=a[i]]);
	for (int i=1, j; i<=Q; i++)
		if (q[i].opt==1) j=q[i].x, T.add(j, v[q[i].y]-v[b[j]]), b[j]=q[i].y;
		else ans[i]&=T.query(q[i].x, q[i].y)%q[i].z==0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<=n; i++) a[i]=lsh[++m]=read();
	for (int i=1; i<=Q; i++) {
		q[i].opt=read(), q[i].x=read(), q[i].y=read();
		if (q[i].opt==1) lsh[++m]=q[i].y;
		else q[i].z=read(), ans[i]=1;
	}
	sort(lsh+1, lsh+m+1), m=unique(lsh+1, lsh+m+1)-lsh-1;
	auto find=[&](int x) {return lower_bound(lsh+1, lsh+m+1, x)-lsh;};
	for (int i=1; i<=n; i++) a[i]=find(a[i]);
	for (int i=1; i<=Q; i++) if (q[i].opt==1) q[i].y=find(q[i].y);
	for (int i=1; i<=40; i++) work();
	for (int i=1; i<=Q; i++) if (q[i].opt==2) puts(ans[i]?"YES":"NO");
	return 0;
}