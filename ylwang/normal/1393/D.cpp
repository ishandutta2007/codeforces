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
#define int long long
const int P = 998244353; //
using namespace std;
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
const int MAXN = 2e3 + 5;
char s[MAXN][MAXN]; int n, m;
int f[4][MAXN][MAXN], d[4][MAXN][MAXN];
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n); FI(m);
	For(i, 1, n) FI(s[i] + 1);
//	For(o, 0, 3) For(i, 1, n) For(j, 1, m) d[o][i][j] = f[o][i][j] = 1;
	
	For(i, 1, n) For(j, 1, m) d[0][i][j] = j > 1 ? d[0][i][j-1] + (s[i][j] == s[i][j-1]) : 1;
	For(i, 1, n) For(j, 1, m) d[1][i][j] = i > 1 ? d[1][i-1][j] + (s[i][j] == s[i-1][j]) : 1;
	foR(i, n, 1) foR(j, m, 1) d[2][i][j] = j < m ? d[2][i][j+1] + (s[i][j] == s[i][j+1]) : 1;
	foR(i, n, 1) foR(j, m, 1) d[3][i][j] = i < n ? d[3][i+1][j] + (s[i][j] == s[i+1][j]) : 1;
//	For(i, 1, n){
//		For(j, 1, m) cerr << d[1][i][j] << ' ';
//		cerr << endl;
//	}
	For(i, 1, n) For(j, 1, m) 
		f[0][i][j] = (s[i-1][j] == s[i][j] && s[i][j-1] == s[i][j]) ? min(min(f[0][i-1][j]+1, d[0][i][j]), min(f[0][i][j-1]+1, d[1][i][j])) : 1;
	For(i, 1, n) foR(j, m, 1)
		f[1][i][j] = (s[i-1][j] == s[i][j] && s[i][j+1] == s[i][j]) ? min(min(f[1][i-1][j]+1, d[2][i][j]), min(f[1][i][j+1]+1, d[1][i][j])) : 1;
	foR(i, n, 1) For(j, 1, m)
		f[2][i][j] = (s[i+1][j] == s[i][j] && s[i][j-1] == s[i][j]) ? min(min(f[2][i+1][j]+1, d[0][i][j]), min(f[2][i][j-1]+1, d[3][i][j])) : 1;
	foR(i, n, 1) foR(j, m, 1)
		f[3][i][j] = (s[i+1][j] == s[i][j] && s[i][j+1] == s[i][j]) ? min(min(f[3][i+1][j]+1, d[2][i][j]), min(f[3][i][j+1]+1, d[3][i][j])) : 1; 
	ll res = 0;
	For(i, 1, n) {
		For(j, 1, m) {
			int t = (1<<30); For(o, 0, 3) ckmin(t, f[o][i][j]);
//			cerr << t << endl;
			res += t;
		}
	}
	cout << res << endl;
    return FastIO::Fflush(), 0;
}
/*
  1
0   2
  3
  
0   1

2   3

4 4
bbcb
cbbb
ccbb
aabb

*/