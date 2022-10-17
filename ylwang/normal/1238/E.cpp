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
//#define int long long
const int P = 1000000007; //
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
const int MAXN = 2e5 + 5;
int n, m, cnt[21][21]; char s[MAXN];
int f[1 << 20];
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); FI(m); FI(s + 1);
    For(i, 2, n) cnt[s[i-1]-'a'][s[i]-'a']++, cnt[s[i]-'a'][s[i-1]-'a']++;
    For(i, 0, m) cnt[i][i] = 0;
//    For(i, 0, m - 1) {
//    	For(j, 0, m - 1) cerr << cnt[i][j] << ' ';
//    	cerr << endl;
//	}
	mst(f, 127 / 2); f[0] = 0;
	For(i, 0, (1 << m) - 1) {
		int t = __builtin_popcount(i);
		For(j, 0, m - 1) {
			if(!((i >> j) & 1)) {
				int sum = 0;
				For(k, 0, m - 1) {
					if((i >> k) & 1) sum += cnt[j][k];
					else sum -= cnt[k][j];
				}
				ckmin(f[i | (1 << j)], f[i] + sum * t);
			}
		}
	}
	cout << f[(1 << m) - 1] << endl;
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