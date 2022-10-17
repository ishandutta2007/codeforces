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
#define int long long
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(ll &a, ll b) {a = min(a, b);}
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
const int MAXN = 2e6 + 5;
int n, k, fac[MAXN], invfac[MAXN];
void init(int n) {
	fac[0] = 1; For(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % P;
	invfac[n] = inv(fac[n]); foR(i, n - 1, 0) invfac[i] = 1ll * invfac[i + 1] * (i + 1) % P;
}
inline int C(int n, int m) {
	if(n < m || n < 0 || m < 0) return 0;
//	cerr << n << ' ' << fac[n] << ' ' << invfac[m] << endl;
	return 1ll * fac[n] * invfac[m] % P * invfac[n - m] % P;
}
map < Pair, int > mp;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); FI(k);
    init(MAXN - 5);
    For(i, 1, n) {
    	int l, r; FI(l), FI(r);
    	mp[mkp(l, 1)]++, mp[mkp(r + 1, -1)]++;
	}
	int x = 0, y = 0, res = 0;
	for(auto it : mp) {
		
		y = it.second; if(it.first.second == -1) x -= y;
		else {
//			cerr << x << ' ' << y << endl;
			res = (res + (C(x + y, k) - C(x, k) + P) % P) % P;
			x += y;
		}
	}
	cout << (res % P + P) % P << endl;
    return FastIO::Fflush(), 0;
}