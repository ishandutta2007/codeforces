#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
const int base=19260817, mod=1e9+9;
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, a=(ll)a*a%mod)
		if (b&1) res=(ll)res*a%mod;
	return res;
}
const int ib=qpow(base, mod-2);
int n, K, Q, a[N], pw[N], ipw[N];
struct Node {
	int v, len;
	Node(int _v=0, int _len=0) :v(_v), len(_len){}
	Node& operator +=(const Node &q) {v=(v+(ll)q.v*pw[len])%mod, len+=q.len; return *this;}
	Node operator +(const Node &q) const {Node tmp=*this; tmp+=q; return tmp;}
	Node& operator -=(const Node &q) {v=(v+mod-q.v)*(ll)ipw[q.len]%mod, len-=q.len; return *this;}
	Node operator -(const Node &q) const {Node tmp=*this; tmp-=q; return tmp;}
	bool operator ==(const Node &q) const {return v==q.v && len==q.len;}
	bool operator !=(const Node &q) const {return !(*this==q);}
};
struct node {
	Node hl, hr;
	bool fl;
	node() {fl=true, hl=hr=Node();}
};
struct Segment_Tree {
	#define ls (p<<1)
	#define rs (p<<1|1)
	node t[N<<2];
	Node queryl(int p, int len) {
		if (!len) return Node();
		if (len==t[p].hl.len) return t[p].hl;
		if (len<=t[ls].hl.len) return queryl(ls, len);
		return t[ls].hl+(queryl(rs, len-t[ls].hl.len+t[ls].hr.len)-t[ls].hr);
	}
	Node queryr(int p, int len) {
		if (!len) return Node();
		if (len==t[p].hr.len) return t[p].hr;
		if (len<=t[rs].hr.len) return queryr(rs, len);
		return t[rs].hr+(queryr(ls, len-t[rs].hr.len+t[rs].hl.len)-t[rs].hl);
	}
	inline void upd(int p) {
		if (!t[ls].fl || !t[rs].fl) {t[p].fl=false; return;}
		t[p].fl=true;
		if (t[ls].hr.len<t[rs].hl.len) {
			Node tmp=queryl(rs, t[ls].hr.len);
			if (tmp==t[ls].hr) t[p].hr=t[rs].hr, t[p].hl=t[ls].hl+(t[rs].hl-tmp);
			else t[p].fl=false;
		} else {
			Node tmp=queryr(ls, t[rs].hl.len);
			if (tmp==t[rs].hl) t[p].hl=t[ls].hl, t[p].hr=t[rs].hr+(t[ls].hr-tmp);
			else t[p].fl=false;
		}
	}
	void build(int p, int l, int r) {
		if (l==r) {
			t[p]=node();
			if (a[l]<0) t[p].hl=Node(-a[l], 1);
			else t[p].hr=Node(a[l], 1);
			return;
		}
		int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r), upd(p);
	}
	void modify(int p, int l, int r, int x, int v) {
		if (l==r) {
			t[p]=node();
			if (v<0) t[p].hl=Node(-v, 1);
			else t[p].hr=Node(v, 1);
			return;
		}
		int mid=(l+r)>>1;
		x<=mid?modify(ls, l, mid, x, v):modify(rs, mid+1, r, x, v);
		upd(p);
	}
	int tp, stk[44];
	Node lst[44];
	void Get(int p, int l, int r, int x, int y) {
		if (x<=l && r<=y) {stk[++tp]=p; return;}
		int mid=(l+r)>>1;
		if (x<=mid) Get(ls, l, mid, x, y);
		if (y>mid) Get(rs, mid+1, r, x, y);
	}
	Node qr(int i, int len) {
		if (!i || !len) return Node();
		if (len==lst[i].len) return lst[i];
		int p=stk[i];
		if (len<=t[p].hr.len) return queryr(p, len);
		return t[p].hr+(qr(i-1, len-t[p].hr.len+t[p].hl.len)-t[p].hl);
	}
	inline bool query(int l, int r) {
		tp=0, Get(1, 1, n, l, r);
		for (int i=1; i<=tp; i++) {
			int p=stk[i];
			if (!t[p].fl) return false;
			if (lst[i-1].len<t[p].hl.len) return false;
			if (qr(i-1, t[p].hl.len)!=t[p].hl) return false;
			lst[i]=t[p].hr+(lst[i-1]-t[p].hl);
		}
		return !lst[tp].len;
	}
	#undef ls
	#undef rs
}T;
int main() {
	n=read(), K=read();
	for (int i=1; i<=n; i++) a[i]=read();
	pw[0]=1; for (int i=1; i<=n; i++) pw[i]=(ll)pw[i-1]*base%mod;
	ipw[0]=1; for (int i=1; i<=n; i++) ipw[i]=(ll)ipw[i-1]*ib%mod;
	T.build(1, 1, n), Q=read();
	while (Q--) {
		int opt=read(), x=read(), y=read();
		if (opt==1) T.modify(1, 1, n, x, y);
		else puts(T.query(x, y)?"Yes":"No");
	}
	return 0;
}