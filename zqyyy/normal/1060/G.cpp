#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
struct Query {
	int x, id, bel; ll k;
} q[N];
int n, Q, a[N];
ll ans[N];
struct b1t {
	int c[N];
	inline void init() { for (int i=1; i<=n; i++) c[i]=i&-i;}
	inline void add(int p,int x) {for (; p<=n; p+=p&-p) c[p]+=x;}
	inline int ask(int p) {int res=0; for (; p; p^=p&-p) res+=c[p]; return res;}
	inline int query(int k) {
		static int lg=__lg(n); int p=0, sum=0;
		for (int i=lg; ~i; i--)
			if (p+(1<<i)<=n && sum+c[p|1<<i]<k) sum+=c[p|=1<<i];
		return p+1;
	}
}T;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1; i<=Q; i++) {
		q[i].x=read(), q[i].k=read(), q[i].id=i;
		if (q[i].x<a[1]) ans[i]=q[i].x;
	}
	sort(q+1, q+Q+1, [&](auto x, auto y) {return x.x>y.x;}), T.init(); ll pos=1e15, cnt=0;
	for (int i=n, j=1; i; i--) {
		while (j<=Q && q[j].x>=a[i]) {
			ll p=(pos-q[j].x+i-1)/i;
			pos-=p*i, cnt+=p, q[j].bel=T.query(q[j].x-pos+1), q[j].k=cnt-q[j].k, j++;
		}
		ll p=(pos-a[i]+i-1)/i; pos-=p*i, cnt+=p, T.add(T.query(a[i]-pos+1), -1);
	}
	sort(q+1, q+Q+1, [&](auto x, auto y) {return x.k<y.k;}), T.init(), pos=1e15, cnt=0;
	for (int i=n, j=1; i; i--) {
		ll p=(pos-a[i]+i-1)/i;
		while (j<=Q && q[j].k-cnt<=p) {
			if (q[j].x>=a[1]) ans[q[j].id]=pos-(q[j].k-cnt)*i+T.ask(q[j].bel-1);
			j++;
		}
		pos-=p*i, cnt+=p, T.add(T.query(a[i]-pos+1), -1);
	}
	for (int i=1; i<=Q; i++) printf("%lld\n", ans[i]);
	return 0;
}