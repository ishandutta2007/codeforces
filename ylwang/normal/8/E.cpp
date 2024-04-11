#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::readd(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
#define int long long
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
    for(;isdigit(c);num=num*10+c-48,c=getchar());
    return num*flag;
}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int readd(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool readd(int& x) {if(x)x=0;int bf=0,n=readd(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
int n, k, a[55], dp[55][2][2];
int dfs(int x, int lim1, int lim2) {
	if(x > n - x + 1) return 1;
	if(dp[x][lim1][lim2] >= 0) return dp[x][lim1][lim2];
	int ans = 0;
	For(i, 0, 1) {
		For(j, 0, 1) {
			if(a[x] == (i ^ 1) || a[n-x+1] == (j ^ 1) || (x == n - x + 1 && i != j) || (lim1 && i == 1 && j == 1) || (lim2 && i == 1 && j == 0) )continue;
//			cerr << "?" << endl;
			ans += dfs(x + 1, lim1 && i != j, lim2 && i == j);
		}
	}
	return dp[x][lim1][lim2] = ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n); FI(k);
	mst(a, -127); mst(dp, -1); a[1] = 0;
//	cerr << dfs(1, 1, 1) << endl;
	k++;
	if(dfs(1, 1, 1) < k) {
		printf("-1\n");
		return 0;
	}
	For(i, 2, n) {
		mst(dp, -1);
		a[i] = 0; int t = dfs(1, 1, 1);
		if(t < k)
			a[i] = 1, k -= t;
	}
	
	For(i, 1, n)
		printf("%lld", a[i]);
    return 0;
}