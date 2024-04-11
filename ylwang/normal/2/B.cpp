#pragma GCC optimize("Ofast")
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
}
const int MAXN = 1005;
int n, a[MAXN][MAXN], b[MAXN][MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN], l[2][MAXN][MAXN];
void print(int o, int x, int y) {
//	cerr << x << ' ' << y << endl; 
	if(x == 1 && y == 1) return;
	if(l[o][x][y] == 0) {
		print(o, x-1, y);  printf("D");
	} else {
		print(o, x, y-1); printf("R");
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n);
	int tx = 0, ty = 0;
	For(i, 1, n) {
		For(j, 1, n) {
			int x; FI(x);
			if(x == 0) {
				tx = i, ty = j; continue;
			}
			while(x % 2 == 0) x /= 2, a[i][j]++;
			while(x % 5 == 0) x /= 5, b[i][j]++;
		}
	}
	For(i, 0, n) For(j, 0, n) f[i][j] = INF; f[1][1] = a[1][1];
	For(i, 1, n) For(j, 1, n) {
		if(i != 1 && f[i-1][j] + a[i][j] < f[i][j])
			f[i][j] = f[i-1][j] + a[i][j], l[0][i][j] = 0;
		if(j != 1 && f[i][j-1] + a[i][j] < f[i][j]) 
			f[i][j] = f[i][j-1] + a[i][j], l[0][i][j] = 1;
	}
	
	For(i, 0, n) For(j, 0, n) g[i][j] = INF; g[1][1] = b[1][1];
	For(i, 1, n) For(j, 1, n) {
		if(i != 1 && g[i-1][j] + b[i][j] < g[i][j])
			g[i][j] = g[i-1][j] + b[i][j], l[1][i][j] = 0;
		if(j != 1 && g[i][j-1] + b[i][j] < g[i][j]) 
			g[i][j] = g[i][j-1] + b[i][j], l[1][i][j] = 1;
	}
	if(min(f[n][n], g[n][n]) > 0 && tx && ty) {
		printf("1\n");
		For(i, 1, tx - 1) printf("D");
		For(i, 1, ty - 1) printf("R");
		For(i, 1, n - tx) printf("D");
		For(i, 1, n - ty) printf("R");
		
		return 0;
	}
	printf("%d\n", min(f[n][n], g[n][n]));
	if(f[n][n] < g[n][n]) {
		print(0, n, n);
	} else {
		print(1, n, n);
	}
	printf("\n");
    return FastIO::Fflush(), 0;
}
/*

*/