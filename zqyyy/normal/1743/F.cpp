#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use in interactive problems!!!
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
struct Mat {
	int a[2][2];
	int* operator [](int i) {return a[i];}
	Mat() { a[0][0]=a[0][1]=a[1][0]=a[1][1]=0; }
	Mat operator *(Mat q) {
		Mat r;
		for (int i=0; i<2; i++)
			for (int k=0; k<2; k++)
				for (int j=0; j<2; j++)
					inc(r[i][j], (ll)a[i][k]*q[k][j]%mod);
		return r;
	}
};
inline Mat init(int v) {
	Mat r;
	if (v) r[1][1]=2, r[1][0]=1, r[0][1]=2, r[0][0]=1;
	else r[0][0]=3, r[1][0]=1, r[1][1]=2;
	return r;
}
struct Segment_Tree {
	Mat t[N<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void upd(int p) { t[p]=t[ls]*t[rs];}
	void build(int p, int l, int r) {
		if (l==r) {t[p]=init(0); return;}
		int mid=(l+r)>>1; build(ls, l, mid), build(rs, mid+1, r), upd(p);
	}
	void modify(int p, int l, int r, int x, int v) {
		if (l==r) {t[p]=init(v); return;} int mid=(l+r)>>1;
		x<=mid?modify(ls, l, mid, x, v):modify(rs, mid+1, r, x, v); upd(p);
	}
	#undef ls
	#undef rs
}T;
int n, m, L[N], R[N];
vector<int>Add[N], Del[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), m=3e5;
	for (int i=1; i<=n; i++) {
		L[i]=read(), R[i]=read();
		if (i>1) Add[L[i]].push_back(i), Del[R[i]+1].push_back(i);
	}
	T.build(1, 2, n); int ans=0;
	for (int i=0; i<=m; i++) {
		for (auto x:Add[i]) T.modify(1, 2, n, x, 1);
		for (auto x:Del[i]) T.modify(1, 2, n, x, 0);
		auto t=T.t[1]; inc(ans, t[L[1]<=i && i<=R[1]][1]);
	}
	printf("%d\n", ans);
	return 0;
}