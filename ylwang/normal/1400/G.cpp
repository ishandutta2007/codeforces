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
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mul(int &a, int b) {a = 1ll * a * b % P;}
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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 3e5 + 5;
const int MAXM = 25;
int n, m, l[MAXN], r[MAXN], u[MAXM], v[MAXM], s[MAXN];
int fac[MAXN], ifac[MAXN], sum[MAXN][55];

bool used[MAXN];
inline int C(int n, int m) {
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;
}

signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
	#endif
	FI(n), FI(m);
	fac[0] = ifac[0] = 1;
	For(i, 1, n) fac[i] = 1ll * fac[i-1] * i % P;
	For(i, 1, n) ifac[i] = inv(fac[i]);
	For(i, 1, n) FI(l[i]), FI(r[i]), s[l[i]]++, s[r[i] + 1]--;
	For(i, 1, n) s[i] += s[i-1];
	For(i, 0, m - 1) FI(u[i]), FI(v[i]);
	int res = 0;
	
	For(i, 1, n) addmod(res, C(s[i], i));
	For(i, 1, n) For(j, 1, m * 2)
		addmod(sum[i][j], sum[i-1][j] + C(s[i] - j, i - j));
//	cerr << "?";
	For(st, 1, (1 << m) - 1) {
//		cerr << st << endl;
		int L = -1, R = INF, o = (__builtin_popcount(st) & 1) ? -1 : 1, cnt = 0;
		For(i, 0, m - 1) {
			if((st >> i) & 1) {
				ckmax(L, l[u[i]]), ckmin(R, r[u[i]]), cnt += (!used[u[i]]), used[u[i]] = 1;
				ckmax(L, l[v[i]]), ckmin(R, r[v[i]]), cnt += (!used[v[i]]), used[v[i]] = 1;
			}
		}
		if(L <= R) addmod(res, (o * (sum[R][cnt] - sum[L - 1][cnt]) % P + P) % P);
		For(i, 0, m - 1) used[u[i]] = used[v[i]] = 0;
	}
	cout << res << endl;
    return FastIO::Fflush(), 0;
} 
/*
tot - illegal

*/