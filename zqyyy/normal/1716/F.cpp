#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=2007, mod=998244353;
inline void inc(int &x, int y) {x+=y-mod, x+=x>>31&mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, a=(ll)a*a%mod)
		if (b&1) res=(ll)res*a%mod;
	return res;
}
int n, m, K, S[N][N];
inline void work() {
	n=read(), m=read(), K=read();
	int ans=0, inv=qpow(m, mod-2), a=(m+1)/2, res=qpow(m, n);
	for (int i=0, lim=min(n, K); i<=lim; i++)
		inc(ans, (ll)S[K][i]*res%mod), res=(ll)res*(n-i)%mod*inv%mod*a%mod;
	printf("%d\n", ans);
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	S[0][0]=1, n=2000;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=i; j++) S[i][j]=((ll)S[i-1][j]*j+S[i-1][j-1])%mod;
	int test=read();
	while (test--) work();
	return 0;
}