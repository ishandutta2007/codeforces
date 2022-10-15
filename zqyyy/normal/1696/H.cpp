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
const int N=607, mod=1e9+7, inf=0x3f3f3f3f;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, m, ans, a[N];
inline void solve1() { // get the maximum m absolute value(s)
	static int f[N]; f[0]=1;
	for (int i=1; i<=n; i++) {
		inc(f[m], f[m]); int v=(a[i]+mod)%mod;
		for (int j=m; j; j--) inc(f[j], (ll)f[j-1]*v%mod);
	}
	inc(ans, f[m]);
}
inline void solve2() { // when m is odd and all value in the subset is negative, get the minimum m absolute value(s)
	if (m%2==0) return;
	static int cnt, b[N], f[N];
	for (int i=1; i<=n; i++) if (a[i]<0) b[++cnt]=a[i];
	if (cnt<m) return;
	f[0]=1;
	for (int i=1; i<=cnt; i++) {
		inc(f[m], f[m]); int v=b[i]+mod;
		for (int j=m; j; j--) inc(f[j], (ll)f[j-1]*v%mod);
	}
	dec(ans, f[m]), memset(f, 0, sizeof f), f[0]=1;
	for (int i=cnt; i; i--) {
		inc(f[m], f[m]); int v=b[i]+mod;
		for (int j=m; j; j--) inc(f[j], (ll)f[j-1]*v%mod);
	}
	inc(ans, f[m]);
}
inline void solve3() { // when in the maximum m absolute value(s) has odd negative value, adjust it.
	static int s_p, s_n, pos[N], neg[N], z, pw[N]={1}, f[N][N], g[N][N];
	for (int i=1; i<=n; i++) pw[i]=(pw[i-1]<<1)%mod;
	for (int i=1; i<=n; i++) {
		int x=a[i];
		if (x>0) pos[++s_p]=x;
		else if (x<0) neg[++s_n]=x;
		else z++;
	}
	f[0][0]=1;
	for (int i=1; i<=s_p; i++) {
		for (int j=0; j<=m-2; j++) f[i][j]=f[i-1][j];
		for (int j=m-2; j>0; j--) inc(f[i][j], (ll)f[i-1][j-1]*pos[i]%mod);
	}
	g[0][0]=1;
	for (int i=1; i<=s_n; i++) {
		for (int j=0; j<=m-1; j++) g[i][j]=g[i-1][j];
		for (int j=m-1; j; j--) inc(g[i][j], (ll)g[i-1][j-1]*(neg[i]+mod)%mod);
	}
	// m is odd
	if (m%2==1) {
		for (int j=m, k=1; j<=s_n; j++) {
			int val=g[j-1][m-1]; while (k<=s_p && pos[k]>=-neg[j]) k++;
			dec(ans, (ll)val*(neg[j]+mod)%mod*(pw[n-j-k+1]+mod-pw[s_n-j])%mod);
			for (int i=k; i<=s_p; i++)
				inc(ans, (ll)val*pos[i]%mod*pw[n-j-i]%mod);
		}
	}
	for (int i=1; i<=s_p; i++) //pos1
		for (int j=1; j<=s_n; j++) { //neg1
			int val=0;
			for (int k=0; k<=m-2; k+=2) inc(val, (ll)f[i-1][m-2-k]*g[j-1][k]%mod);
			if (!val) continue;
			int pp=i+1; while (pp<=s_p && pos[pp]>=-neg[j]) pp++;
			int pn=j+1; while (pn<=s_n && -neg[pn]>pos[i]) pn++;
			dec(ans, (ll)val*pos[i]%mod*(neg[j]+mod)%mod*(pw[n-pp+1-pn+1]-1)%mod);
			for (int k=pn, l=pp; k<=s_n; k++) { //neg choose neg and neg1
				while (l<=s_p && (ll)neg[j]*neg[k]<=(ll)pos[i]*pos[l]) l++;
				inc(ans, (ll)neg[j]*neg[k]%mod*val%mod*pw[n-l+1-k]%mod);
			}
			for (int k=pp, l=pn; k<=s_p; k++) { //choose pos and pos1
				while (l<=s_n && (ll)pos[i]*pos[k]<(ll)neg[j]*neg[l]) l++;
				inc(ans, (ll)pos[i]*pos[k]%mod*val%mod*pw[n-l+1-k]%mod);
			}
		}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), m=read();
	for (int i=1; i<=n; i++) a[i]=read();
	sort(a+1, a+n+1, [](const int &x, const int &y) {return abs(x)^abs(y)?abs(x)>abs(y):x>y;});
	solve1(), solve2(), solve3(), printf("%d\n", ans);
	return 0;
}