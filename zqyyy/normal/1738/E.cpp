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
const int N=2e5+7, mod=998244353, inf=0x3f3f3f3f;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, fac[N], ifac[N];
inline int C(int n, int m) {
	if (n<m || m<0) return 0;
	return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
ll a[N], pre[N], suf[N];
inline void clear() {}
inline void work() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	int ans=1;
	/*
	for (int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
	suf[n+1]=0; for (int i=n; i; i--) suf[i]=suf[i+1]+a[i];
	for (int l1=1, r1=0, r2=n, l2=n+1; l1<r2;) {
		while (r1<n && pre[r1+1]==pre[l1]) r1++;
		while (l2>1 && suf[l2-1]==suf[r2]) l2--;
		if (pre[l1]<suf[r2]) l1=r1+1;
		else if (pre[l1]>suf[r2]) r2=l2-1;
		else {
			if (l2<r1) {mul(ans, qpow(2, r1-l1+(l1!=1 || r1!=n))); break;}
			int L=r1-l1+1, R=r2-l2+1, tmp=0;
			for (int i=0; i<=min(L, R); i++) inc(tmp, (ll)C(L, i)*C(R, i)%mod);
			mul(ans, tmp), l1=r1+1, r2=l2-1;
		}
	}*/
	ll sl=a[1], sr=a[n];
	for (int l1=1, r1=1, r2=n, l2=n; l1<r2;) {
		while (r1<n && !a[r1+1]) r1++;
		while (l2>1 && !a[l2-1]) l2--;
		if (sl<sr) sl+=a[l1=++r1];
		else if (sl>sr) sr+=a[r2=--l2];
		else {
			if (l2<=r1) {mul(ans, qpow(2, r1-l1+(l1!=1 || r1!=n))); break;}
			int L=r1-l1+1, R=r2-l2+1, tmp=0;
			for (int i=0; i<=min(L, R); i++) inc(tmp, (ll)C(L, i)*C(R, i)%mod);
			mul(ans, tmp), sl+=a[l1=++r1], sr+=a[r2=--l2];
		}
	}
	printf("%d\n", ans);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=2e5, fac[0]=1;
	for (int i=1; i<=n; i++) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n], mod-2);
	for (int i=n; i; i--) ifac[i-1]=(ll)ifac[i]*i%mod;
	int test=read();
	while (test--) work(), clear();
	return 0;
}