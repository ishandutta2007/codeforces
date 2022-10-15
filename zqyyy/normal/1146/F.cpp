#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7, mod=998244353;
inline void inc(int &x, int y) {x+=y-mod, x+=x>>31&mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, a=(ll)a*a%mod)
		if (b&1) res=(ll)res*a%mod;
	return res;
}
int n, f[N][3];
vector<int>G[N];
void dfs(int x) {
	if (G[x].empty()) {f[x][2]=1; return;}
	f[x][0]=1;
	for (int y:G[x]) {
		dfs(y); int a=(f[y][1]+f[y][2])%mod, b=(f[y][0]+f[y][2])%mod;
		f[x][2]=((ll)(f[x][2]+f[x][1])*a+(ll)f[x][2]*b)%mod;
		f[x][1]=((ll)f[x][0]*a+(ll)f[x][1]*b)%mod, f[x][0]=(ll)f[x][0]*b%mod;
	}
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	n=read();
	for (int i=2; i<=n; i++) G[read()].push_back(i);
	dfs(1), printf("%d\n", (f[1][0]+f[1][2])%mod);
	return 0;
}