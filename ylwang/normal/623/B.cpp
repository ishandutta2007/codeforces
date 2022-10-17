#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define ull unsigned ll
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); --i)
#define For(i, k, j) for(rint i = (k); i <= (j); ++i)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
//#define int long long
const int P = 1000000007; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(ll &a, ll b) {a = min(a, b);}
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
const int MAXN = 1e6 + 5;
int n, A, B, a[MAXN];
vector < int > Div;
map < int, int > vis;
void calc_div(int x) {
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			if(!vis[i]) Div.pb(i);
			while(x % i == 0) x /= i;
		}
	}
	if(x != 1 && !vis[x]) Div.pb(x);
}
ll dp[MAXN][3];
ll solve(int d) {
//	cerr << d << endl;
	For(i, 1, n) dp[i][0] = dp[i][1] = dp[i][2] = (1ll << 62);
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	For(i, 1, n) {
		if(a[i] % d == 0) {
			ckmin(dp[i][0], dp[i-1][0]);
			ckmin(dp[i][1], min(dp[i-1][0], dp[i-1][1]) + A);
			ckmin(dp[i][2], min(dp[i-1][1], dp[i-1][2]));
		} else if((a[i] + 1) % d == 0 || (a[i] - 1) % d == 0) {
			ckmin(dp[i][0], dp[i-1][0] + B);
			ckmin(dp[i][1], min(dp[i-1][0], dp[i-1][1]) + A);
			ckmin(dp[i][2], min(dp[i-1][1], dp[i-1][2]) + B);
		} else {
			ckmin(dp[i][1], min(dp[i-1][0], dp[i-1][1]) + A);
		}
	}
	return min(min(dp[n][0], dp[n][1]), dp[n][2]);	
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	cin >> n >> A >> B;
	For(i, 1, n) FI(a[i]);
	calc_div(a[1]); calc_div(a[1] - 1); calc_div(a[1] + 1); 
	calc_div(a[n]); calc_div(a[n] - 1); calc_div(a[n] + 1); 
	sort(Div.begin(), Div.end());
	ll ans = (1ll << 62);
	for(auto d : Div)
		ckmin(ans, solve(d));
	cout << ans << endl;
    return FastIO::Fflush(), 0;
}
/*

*/