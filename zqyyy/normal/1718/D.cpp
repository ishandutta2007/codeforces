#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=3e5+7, inf=1e6+1;
int n, m, Q, tp, ls[N], rs[N], stk[N], p[N], a[N], c[N];
struct seg {int l, r;} b[N];
int f[N];
void dfs(int x, int lim) {
	f[x]=0;
	if (a[x]) ckmin(lim, a[x]), f[x]=a[x];
	if (ls[x]) dfs(ls[x], lim), ckmax(f[x], f[ls[x]]);
	if (rs[x]) dfs(rs[x], lim), ckmax(f[x], f[rs[x]]);
	if (!a[x]) b[++m]={f[x], lim};
}
#define GG {while (Q--) read(), puts("NO"); return;}
inline void work() {
	n=read(), Q=read();
	for (int i=1; i<=n; i++) p[i]=read();
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1; i<=n; i++) ls[i]=rs[i]=0;
	tp=0;
	for (int i=1; i<=n; i++) {
		while (tp && p[stk[tp]]<p[i]) ls[i]=stk[tp--];
		if (tp) rs[stk[tp]]=i; stk[++tp]=i;
	}
	m=0, dfs(stk[1], inf);
	for (int i=1; i<m; i++) c[i]=read();
	for (int i=1; i<=n; i++)
		if (a[i] && a[i]<f[i]) GG;
	set<int>s; int low=-1, high=-1;
	for (int i=1; i<m; i++) s.insert(c[i]);
	sort (b+1, b+m+1, [](auto x, auto y) {return x.r^y.r?x.r<y.r:x.l>y.l;});
	for (int i=1; i<=m; i++){
		auto it=s.lower_bound(b[i].l);
		if (it==s.end() || *it>b[i].r) {
			if (~high) GG;
			high=b[i].r;
		} else s.erase(it);
	}
	for (int i=1; i<m; i++) s.insert(c[i]);
	sort (b+1, b+m+1, [](auto x, auto y) {return x.l^y.l?x.l>y.l:x.r<y.r;});
	for (int i=1; i<=m; i++) {
		auto it=s.upper_bound(b[i].r);
		if (it==s.begin() || *(--it)<b[i].l) {
			if (~low) GG;
			low=b[i].l;
		} else s.erase(it);
	}
	while (Q--) {
		int x=read();
		puts(low<=x && x<=high?"YES":"NO");
	}
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int test=read();
	while (test--) work();
	return 0;
}