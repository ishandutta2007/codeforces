#pragma GCC optimize(3)
#pragma GCC optimize(2)
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
const int P = 1000000007; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(double &a, double b) {a = min(a, b);}
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
const int MAXN = 3e5 + 5;
int a[MAXN], n, L, v1[MAXN], v2[MAXN];
double t1[MAXN], t2[MAXN];
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    int T; cin >> T;
    while(T--) {
    	FI(n); FI(L);
    	For(i, 1, n) FI(a[i]); a[0] = 0, a[n + 1] = L;
    	t1[0] = 0, v1[0] = 1;
    	For(i, 1, n + 1) {
    		t1[i] = t1[i - 1] + 1.0 * (a[i] - a[i - 1]) / v1[i - 1]; v1[i] = v1[i - 1] + 1;
//    		cerr << t1[i] << ' ';
		}
//		cerr << endl;
		t2[n + 1] = 0, v2[n + 1] = 1;
		foR(i, n, 0) {
			t2[i] = t2[i + 1] + 1.0 * (a[i + 1] - a[i]) / v2[i + 1]; v2[i] = v2[i + 1] + 1;
//			cerr << t2[i] << ' ';
		}
//		cerr << endl;
		double res = 1e12;
		For(i, 1, n + 1) {
			if(t1[i] >= t2[i] && t1[i - 1] <= t2[i - 1]) {
				if(t2[i] < t1[i - 1]) {
					res = t1[i - 1] + 1.0 * (a[i] - a[i - 1] + (t2[i] - t1[i - 1]) * v2[i]) / (v2[i] + v1[i - 1]);
				} else {
					res = t2[i] + 1.0 * (a[i] - a[i - 1] + (t1[i - 1] - t2[i]) * v1[i - 1]) / (v2[i] + v1[i - 1]);
				}
//				cerr << v2[i] << ' ' << v1[i - 1] << ' ' << t2[i] << ' ' << t1[i - 1] << ' '  << a[i] << ' ' << a[i - 1] << endl;
				break;
			}
		}
		printf("%.10lf\n", res);
	}
    return FastIO::Fflush(), 0;
}
/*
Think twice :
mod ?
INF ?
n = 1 ?
long long ?
Fastio::Fflush() ?

*/