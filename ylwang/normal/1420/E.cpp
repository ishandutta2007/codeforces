#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define rint register int
#define INF ((1ll << 50) - 1)
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
int n, o[MAXN], a[MAXN], m, f[MAXN][MAXN][MAXN*MAXN/2], res[MAXN];
inline int C2(int x) {
	if(x < 2) return 0;
	return x * (x - 1) / 2;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n);
    For(i, 1, n) {
    	FI(o[i]); if(o[i]) a[++m] = i;
	}
	int t = C2(n - m); a[++m] = n + 1;
	mst(f, 127 / 2); f[0][0][0] = 0; 
	For(i, 1, m) {
		For(j, i, n + 1) {
			For(k, 0, n * (n - 1) / 2) {
				if(k < abs(a[i] - j)) continue;
				For(lst, 0, j - 1) {
					ckmin(f[i][j][k], f[i-1][lst][k - abs(a[i] - j)] + C2(j - lst - 1));
				}
			}
		}
	}
//	For(i, 1, m + 1) {
//		For(j, 1, n + 1) {
//			For(k, 0, n * (n - 1) / 2) cerr << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << endl;
//		}
//	}
	res[0] = -(1 << 30);
	For(k, 0, n * (n - 1) / 2) {
		if(k) res[k] = res[k - 1];
		ckmax(res[k], t - f[m][n + 1][k]);
		cout << res[k] << ' ';
	}
	cout << endl;
    
    return FastIO::Fflush(), 0;
}