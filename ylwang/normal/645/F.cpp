#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back // !
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
const int MAXN = 1e5 + 5;
const int MAXA = 1e6 + 5;
int n, k, q, a[MAXN], prime[MAXA], tot = 0, mu[MAXA], vis[MAXA], fac[MAXA], invfac[MAXA], phi[MAXA];
vector < int > d[MAXA];
inline int C(int n, int m) {
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * fac[n] * invfac[n - m] % P * invfac[m] % P;
}
void init(int n) {
	fac[0] = invfac[0] = mu[1] = phi[1] = 1;
	For(i, 1, n) fac[i] = 1ll * fac[i-1] * i % P;
	For(i, 1, n) invfac[i] = inv(fac[i]);
	
	For(i, 2, n) {
//		cerr << "?";
		if(!vis[i]) prime[++tot] = i, mu[i] = -1, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * prime[j] <= n; j++) {
			int v = i * prime[j]; vis[v] = 1;
			if(i % prime[j]) {
				mu[v] = -mu[i], phi[v] = phi[i] * (prime[j] - 1);
			} else {
				mu[v] = 0, phi[v] = phi[i] * prime[j];
				break;
			}
		}
	}
//	cerr << "?";
	int cnt = 0;
	For(i, 2, n)
		for(rint j = 1; i * j <= n; j++) {
//			if(j % 1000 == 0) cerr << i << ' ' << j << endl;
//			cnt++;
			d[i * j].pb(i);
		}
//	cerr << cnt << endl;
}
int cnt[MAXA], ans = 0, F[MAXN];
void add(int x) {
	for(auto t : d[x]) {
		cnt[t]++;
		addmod(ans, (1ll * phi[t] * (C(cnt[t], k) - C(cnt[t] - 1, k)) % P + P) % P);
	}
	cnt[1]++;
	addmod(ans, (1ll * phi[1] * (C(cnt[1], k) - C(cnt[1] - 1, k)) % P + P) % P);
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	init(1000000);
	FI(n); FI(k); FI(q);
	For(i, 1, n) FI(a[i]), add(a[i]);
	For(i, 1, q) {
		int x; FI(x);
		add(x); FO(ans); FO('\n');
	}
    return FastIO::Fflush(), 0;
}
/*
1 1
36
2 1
*/