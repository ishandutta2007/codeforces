#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
const int N=2e5+7, mod=998244353;
inline void inc(int &x, int y) {x+=y-mod, x+=x>>31&mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, a=(ll)a*a%mod)
		if (b&1) res=(ll)res*a%mod;
	return res;	
}
int n, dp[N][2][2][2][2][2][2];
char str[N];
int dfs(int n, bool f1, bool f2, bool f3, bool lima, bool limb, bool limc) {
	if (n==::n+1) return f1 && f2 && f3;
	int &res=dp[n][f1][f2][f3][lima][limb][limc];
	if (~res) return res; res=0;
	int a=lima?str[n]-'0':1, b=limb?str[n]-'0':1, c=limc?str[n]-'0':1;
	for (int i=0; i<=a; i++)
		for (int j=0; j<=b; j++)
			for (int k=0; k<=c; k++)
				inc(res, dfs(n+1, f1 || (i==j && i!=k), f2 || (i==k && i!=j), f3 || (j==k && k!=i), lima && i==a, limb && j==b, limc && k==c));
	return res;
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	scanf("%s", str+1), n=strlen(str+1);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(1, 0, 0, 0, 1, 1, 1));
	return 0;
}