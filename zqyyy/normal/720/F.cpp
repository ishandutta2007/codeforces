#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e5+7;
const ll INF=0x3f3f3f3f3f3f3f3fll;
struct node {
	ll v, c;
	node(ll _v=0, ll _c=0) :v(_v), c(_c){}
	node& operator +=(node a) {v+=a.v, c+=a.c; return *this;}
	node operator +(node a) {node tmp=*this; tmp+=a; return tmp;}
	bool operator <(const node &q) const {return v^q.v?v<q.v:c<q.c;}
};
int n, a[N], id[N];
ll m, s[N];
struct b1t {
	node c[N];
	inline void init() {for (int i=1; i<=n+1; i++) c[i]={0, 0};}
	inline void add(int p, node x) {for(p++; p<=n+1; p+=p&-p) c[p]+=x;}
	inline node ask(int p) {node res; for (p++; p; p^=p&-p) res+=c[p]; return res;}
}t1;
struct b2t {
	int c[N];
	inline void init() {for (int i=1; i<=n+1; i++) c[i]=n+2;}
	inline void add(int p, int x) {for (p++; p<=n+1; p+=p&-p) ckmin(c[p], x);}
	inline int ask(int p) {int res=n+2; for (p++; p; p^=p&-p) ckmin(res, c[p]); return res;}
}t2;
struct b3t {
	node c[N];
	inline void init() {for (int i=1; i<=n+1; i++) c[i]={-INF, 0};}
	inline void add(int p, node x) {for (p++; p<=n+1; p+=p&-p) ckmax(c[p], x);}
	inline node ask(int p) {node res={-INF, 0}; for (p++; p; p^=p&-p) ckmax(res, c[p]); return res;}
}t3, t4;
node f[N];
int L[N];
inline node check(ll mid) {
	node sum; t1.init(), t2.init();
	//cout<<"check "<<mid<<endl;
	for (int i=0, j=0; i<=n; i++) {
		int x=id[i];
		while (j<=n && s[x]-s[id[j]]-mid>=0) {
			int y=id[j++];
			t1.add(y, node(-s[y]-mid, 1)), t2.add(y, y);
		}
		node tmp=t1.ask(x-1);
		sum+=tmp+node(tmp.c*s[x], 0), L[x]=min(x, t2.ask(x-1))+1;
	}
	//cout<<sum.v<<" "<<sum.c<<endl;
	//for (int i=1; i<=n; i++) cout<<L[i]<<" \n"[i==n];
	t3.init(), t4.init(), t3.add(n, node()), t4.add(0, node()); node Max;
	for (int i=1; i<=n; i++) {
		if (!L[i]) f[i]=t3.ask(n);
		else  {
			node v1=t3.ask(n-L[i]+1), v2=t4.ask(L[i]-2);
			f[i]=max(v1, v2+node(s[i]-mid, 1));
		}
		ckmax(Max, node(-s[i], 0)), t3.add(n-i, f[i]), t4.add(i, f[i]+Max);
		//if (mid==-3) cout<<f[i].v<<" "<<f[i].c<<" "<<Max.v<<" "<<Max.c<<endl;
	}
	//cout<<f[n].v<<" "<<f[n].c<<endl;
	return sum+f[n];
}
int main(){
	n=read(), m=read();
	for (int i=1; i<=n; i++) a[i]=read(), s[i]=s[i-1]+a[i];
	iota(id, id+n+1, 0), sort(id, id+n+1, [&](int x, int y) {return s[x]^s[y]?s[x]<s[y]:x<y;});
	ll l=-5e9, r=5e9;
	while (l<=r) {
		ll mid=(l+r)>>1;
		if (check(mid).c>=m) l=mid+1;
		else r=mid-1;
	}
	printf ("%lld\n", check(r).v+m*r);
	return 0;
}