#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+c-48, c=getchar();
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
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, Q;
double x, y;
struct mat {
	double a[3][3];
	double* operator [](int i) {return a[i];}
	mat(int v=0) {
		memset(a, 0xc0, sizeof a); if (!v) return;
		a[0][0]=a[0][1]=a[0][2]=0, a[1][0]=a[1][1]=v/(x+y), a[2][0]=v/x;
	}
	mat operator *(mat q) {
		mat r;
		for (int i=0; i<3; i++)
			for (int k=0; k<3; k++)
				for (int j=0; j<3; j++)
					ckmax(r[i][j], a[i][k]+q[k][j]);
		return r;
	}
};
namespace sgt {
	mat t[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p) {t[p]=t[ls]*t[rs];}
	void build(int p, int l, int r) {
		if (l==r) {t[p]=mat(read()); return;} int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r), upd(p);
	}
	void modify(int p, int l, int r, int x, int v) {
		if (l==r) {t[p]=mat(v); return;} int mid=(l+r)>>1;
		x<=mid?modify(ls, l, mid, x, v):modify(rs, mid+1, r, x, v); upd(p);
	}
	mat query(int p, int l, int r, int x, int y) {
		if (x<=l && r<=y) return t[p]; int mid=(l+r)>>1; if (y<=mid) return query(ls, l, mid, x, y);
		if (x>mid) return query(rs, mid+1, r, x, y); return query(ls, l, mid, x, y)*query(rs, mid+1, r, x, y);
	}
#undef ls
#undef rs
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read(), x=read(), y=read();
	if (x<y) swap(x, y);
	sgt::build(1, 1, n);
	while (Q--) {
		int opt=read(), x=read(), y=read();
		if (opt==1) sgt::modify(1, 1, n, x, y);
		else {
			mat tmp=sgt::query(1, 1, n, x, y);
			double ans=-1e18;
			for (int i=0; i<3; i++)
				for (int j=0; j<3; j++) ckmax(ans, tmp[i][j]);
			printf("%.12lf\n", ans);
		}
	}
	return 0;
}