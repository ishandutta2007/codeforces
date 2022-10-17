#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
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
const int P = 1000000007;
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int ksm(int a, int b, int P) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}

inline void printarray(int *a, int n) {For(i, 1, n) fprintf(stderr, "%d ", a[i]); fprintf(stderr, "\n");}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 105;
int c1[MAXN], c2[MAXN], a[MAXN], n, f[MAXN][MAXN][4][4]; // f[i][j][x][y] : i ... j  x y 

signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); For(i, 1, n) FI(c1[i]), FI(a[i]), FI(c2[i]), c1[i]--, c2[i]--;
    mst(f, -127 / 2);
    For(i, 1, n)
    	f[i][i][c1[i]][c2[i]] = f[i][i][c2[i]][c1[i]] = a[i];
    
    For(l, 2, n) {
    	For(i, 1, n - l + 1) {
    		int j = i + l - 1;
//    		cerr << i << ' ' << j << endl;
    		For(x, 0, 3) For(y, 0, 3) {
	    		For(k, i, j-1) { // merge (i...k, k+1...j);
	    			ckmax(f[i][j][x][y], max(f[i][k][x][y], f[k+1][j][x][y]));
	    			For(p, 0, 3) {
	    				ckmax(f[i][j][x][y], f[i][k][x][p] + f[k+1][j][p][y]);
	    				ckmax(f[i][j][x][y], f[i][k][p][x] + f[k+1][j][y][p]);
					}
				}
			}
		}
	}
//	For(i, 1, n) For(j, i, n) For(x, 0, 3) For(y, 0, 3) {
//		cerr << i << ' ' << j << ' ' << x << ' ' << y << ' ' << f[i][j][x][y] << endl;
//	}
	int res = 0;
	For(x, 0, 3) For(y, 0, 3) ckmax(res, f[1][n][x][y]);
	cout << res << endl;
    return FastIO::Fflush(), 0;
}
/*

*/