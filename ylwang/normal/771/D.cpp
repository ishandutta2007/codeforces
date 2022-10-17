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
const int MAXN = 85;
int n, c1, c2, c3, p1[MAXN], p2[MAXN], p3[MAXN];
char s[MAXN];
int f[MAXN][MAXN][MAXN][2];
int calc1(int x, int to, int y, int z) {
	int fr = p1[x];
	For(i, 1, y) fr += p2[i] > p1[x];
	For(i, 1, z) fr += p3[i] > p1[x];
//	cerr << x << ' ' << y << ' ' << z << ' ' << to << ' ' << fr << endl;
	return fr - to;
}
int calc2(int y, int to, int x, int z) {
	int fr = p2[y];
	For(i, 1, x) fr += p1[i] > p2[y];
	For(i, 1, z) fr += p3[i] > p2[y];
	return fr - to;
}
int calc3(int z, int to, int x, int y) {
	int fr = p3[z];
	For(i, 1, x) fr += p1[i] > p3[z];
	For(i, 1, y) fr += p2[i] > p3[z];
//	cerr << z << ' ' << x << ' ' << y << ' ' << to << ' ' << fr << endl;
	return fr - to;
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); FI(s + 1); mst(f, 127 / 2);
    For(i, 1, n) {
    	if(s[i] == 'V') p1[++c1] = i;
    	else if(s[i] == 'K') p2[++c2] = i;
    	else p3[++c3] = i;
	}
    f[0][0][0][0] = 0;
	For(i, 0, c1) {
		For(j, 0, c2) {
			For(k, 0, c3) {
				if(i ^ c1) ckmin(f[i+1][j][k][1], min(f[i][j][k][0], f[i][j][k][1]) + calc1(i+1, i+j+k+1, j, k));
				if(j ^ c2) ckmin(f[i][j+1][k][0], f[i][j][k][0] + calc2(j+1, i+j+k+1, i, k));
				if(k ^ c3) ckmin(f[i][j][k+1][0], min(f[i][j][k][0], f[i][j][k][1]) + calc3(k+1, i+j+k+1, i, j));
			}
		}
	}
//	For(i, 0, c1) {
//		For(j, 0, c2) {
//			For(k, 0, c3) {
//				cerr << i << ' ' << j << ' ' << k << ' ' << f[i][j][k][0] << ' ' << f[i][j][k][1] << endl;
//			}
//		}
//	}
	cout << min(f[c1][c2][c3][0], f[c1][c2][c3][1]) << endl;
    return FastIO::Fflush(), 0;
}
/*

*/