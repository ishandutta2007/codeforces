#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
//#define int long long
const int P = 998244353; //
using namespace std;
#define int long long
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}

namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 205;
int R, G, B;
int r[MAXN], g[MAXN], b[MAXN];
int dp[MAXN][MAXN][MAXN];
signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
	#endif
	cin >> R >> G >> B;
	For(i, 1, R) cin >> r[i];
	For(i, 1, G) cin >> g[i];
	For(i, 1, B) cin >> b[i];
	sort(r + 1, r + 1 + R, greater<int>());
	sort(g + 1, g + 1 + G, greater<int>());
	sort(b + 1, b + 1 + B, greater<int>());
	int res = 0;
	For(i, 0, R) For(j, 0, G) For(k, 0, B) {
		if(i != R && j != G) ckmax(dp[i+1][j+1][k], dp[i][j][k] + r[i+1] * g[j+1]);
		if(i != R && k != B) ckmax(dp[i+1][j][k+1], dp[i][j][k] + r[i+1] * b[k+1]);
		if(j != G && k != B) ckmax(dp[i][j+1][k+1], dp[i][j][k] + g[j+1] * b[k+1]);
	}
	For(i, 0, R) For(j, 0, G) For(k, 0, B) {
		ckmax(res, dp[i][j][k]);
//		cerr << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
	}
	cout << res << endl;
    return FastIO::Fflush(), 0;
}