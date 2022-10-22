//wdnmd
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
inline char getc() { //Don't to use it in interactive problems!!!
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?'\n':*p1++):*p1++;
}
inline void read(char *s) { // readstr
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
const int N=2e5+7, mod=1e9+7;
const ll INF=1.1e18;
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
mt19937 RAND(random_device{}());
inline int rnd(int l, int r) {return uniform_int_distribution<int>(l, r)(RAND);}
struct Treap {
	int tot, ls[N], rs[N], sz[N], val[N], t[N];
	inline void upd(int p) {
		t[p]=t[ls[p]]+t[rs[p]]+val[p], sz[p]=sz[ls[p]]+sz[rs[p]]+1;
	}
	inline int newnode(int x) {
		int p=++tot; sz[p]=1, val[p]=t[p]=x, ls[p]=rs[p]=0;
		return p;
	}
	void split(int p, int k, int &x, int &y) {
		if (!p) {x=y=0; return;}
		if (k<=sz[ls[p]]) y=p, split(ls[p], k, x, ls[y]);
		else x=p, split(rs[p], k-sz[ls[p]]-1, rs[x], y);
		upd(p);
	}
	int merge(int x, int y) {
		if (!x || !y) return x|y;
		if (rnd(1, sz[x]+sz[y])<=sz[x]) return rs[x]=merge(rs[x], y), upd(x), x;
		else return ls[y]=merge(x, ls[y]), upd(y), y;
	}
	inline int merge(forward_list<int>li) {int p=0; for (auto x:li) p=merge(p, x); return p;}
	int query(int p, int k) {
		if (!p) return 0;
		if (k<=sz[ls[p]]) return query(ls[p], k);
		return query(rs[p], k-sz[ls[p]]-1)+t[ls[p]]+val[p];
	}
	int find(int p, int k) {
		if (!p) return 0;
		if (k<t[ls[p]]+sz[ls[p]]) return find(ls[p], k);
		return sz[ls[p]]+1+find(rs[p], k-(t[ls[p]]+sz[ls[p]]+val[p]+1));
	}
	void debug(int p) {
		if (!p) return;
		debug(ls[p]), cout<<val[p]<<" ", debug(rs[p]);
	}
} T;
struct Query {
	int k, m, id;
	bool operator <(const Query &q) const {return k<q.k;}
} q[N];
int n, d, Q, st, rt, s_a, s_b, a[N], b[N], tmp[N];
ll s, ans[N];
char str[N];
inline void debug(int rt) {T.debug(rt), cout<<endl;}
inline int calc(int c, int k, ll mid) {
	int p=upper_bound(b+1, b+s_b+1, mid)-b-1; mid-=p;
	if (mid<s) return p;
	if (c<s_a && mid>=a[c+1]) return p+upper_bound(a+c+1, a+s_a+1, mid)-a-1;
	mid-=s; ll num=mid/(d+c-1), P=mid%(d+c-1); int pos=T.find(rt, P);
	//if (c==3 && mid<=20) cout<<p<<" "<<num<<" "<<P<<" "<<pos<<endl;
	return p+max(0ll, min(c, num*c+pos-(k-st)));
	/*
	if (c<s_a && mid>=a[c+1]) return p+upper_bound(a+c+1, a+s_a+1, mid)-a-1;
	int num=k/c; //number of turn.
	if (mid<s+(ll)num*(c-1+d)) return p;
	mid-=s+(ll)num*(c-1+d);
	int tmp=T.query(rt, k%c); if (tmp>mid) return p;
	//if (mid+p+s+(ll)num*(c-1+d)<=20) cout<<mid+p+s+(ll)num*(c-1+d)<<" "<<k<<" "<<mid<<" "<<tmp<<endl;
	//if (c==4) cout<<mid-tmp<<" "<<T.find(rt, mid-tmp)<<" "<<mid+p+s+(ll)num*(c-1+d)<<endl;
	return p+min(c, max(0ll, min(c-1, T.find(rt, mid))+1-k%c+(mid>=c-1+d?T.find(rt, mid-(c-1+d))+1:0)));
	*/
}
inline ll Calc(int c, int i) {
	ll l=1, r=INF;
	while (l<=r) {
		ll mid=(l+r)>>1;
		if (calc(c, q[i].k, mid)>=q[i].m) r=mid-1;
		else l=mid+1;
	}
	//if (c==3)
	//	for (int j=1; j<=20; j++) cout<<"! "<<calc(c, q[i].k, j)<<endl;
	//debug(rt);
	return l;
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), d=read(), Q=read();
	for (int i=1; i<=n; i++) tmp[i]=read();
	read(str+1);
	for (int i=1; i<=n; i++)
		if (str[i]=='1') a[++s_a]=tmp[i]-s_b;
		else b[++s_b]=tmp[i];
	for (int i=1; i<=Q; i++) q[i].k=read(), q[i].m=read(), q[i].id=i;
	sort(q+1, q+Q+1), s=a[1], rt=T.newnode(d-1);
	int j=1;
	//	for (int i=1; i<=s_a; i++) cout<<a[i]<<" \n"[i==s_a];
	for (int i=2; i<=s_a; i++) {
		//cout<<i<<" "<<s+T.query(rt, i-2)+i-1<<endl;
		int num=(a[i]-s-1)/(d+i-2), p=(a[i]-s-1)%(d+i-2), pos=T.find(rt, p);
		while (j<=Q && q[j].k<=st+(num-1)*(i-1)+pos) ans[q[j].id]=Calc(i-1, j), j++;
		int a, b, c, v=p-(pos-1)-T.query(rt, pos-1), tmp=T.query(rt, pos);
		T.split(rt, pos-1, a, b), T.split(b, 1, b, c);
		rt=T.merge({c, a, T.newnode(v), T.newnode(T.val[b]-v)});
		st+=(num-1)*(i-1)+pos, s+=(num-1)*(d+i-2)+pos+tmp;
		//debug(rt);
		//cout<<num<<" "<<(num-1)*(d+i-2)+pos+tmp<<endl;
		/*
		cout<<i<<endl;
		if (a[i]<=s+T.query(rt, i-2)+i-1) {
			int p=a[i]-s-1, pos=T.find(rt, p)+1, a, b, c; //giao!
			p-=T.query(rt, pos-1)+(pos-1);
			T.split(rt, pos-1, a, b), T.split(b, 1, b, c);
			rt=T.merge({a, T.newnode(p), T.newnode(T.val[b]-p), c});
			//debug(rt), cout<<pos<<" "<<s<<" "<<st<<" "<<p<<endl;
			continue;
		}
		int num=(a[i]-s-1)/(i-2+d), p=(a[i]-s-1)%(i-2+d), pos=T.find(rt, p)+1;
		bool fl=p==T.query(rt, pos-1)+pos-1;
		//cout<<fl<<" "<<p+1<<" "<<T.query(rt, pos)<<endl;
		//if (!p) num--, p=i-2+d;
		while (j<=Q && q[j].k<st+num*(i-1)+pos-fl) ans[q[j].id]=Calc(i-1, j), j++;
		int a, b, c, y=T.query(rt, pos)+pos-1-p, tmp=T.query(rt, pos-1);
		T.split(rt, pos-1, a, b), T.split(b, 1, b, c);
		//cout<<fl<<" "<<T.query(rt, pos-1)+pos-1<<endl;
		if (!fl) rt=T.merge({c, a, T.newnode(y), T.newnode(T.val[b]-y)});
		else if (!p) rt=T.merge({T.newnode(0), b, c});
		else rt=T.merge({b, c, T.newnode(0), a}); //T.merge({});
		st+=num*(i-1)+pos-fl, s+=num*(i-2+d)+p+pos-fl;
		debug(rt); cout<<num<<" "<<st<<" "<<s<<" "<<pos<<" "<<y<<" "<<p<<endl;
		*/
		//cout<<j<<endl;
	}
	//cout<<st<<" "<<s<<" "<<s_a<<" "<<s_b<<endl;
	while (j<=Q) ans[q[j].id]=Calc(s_a, j), j++;
	for (int i=1; i<=Q; i++) printf("%lld\n", ans[i]);
	return 0;
}