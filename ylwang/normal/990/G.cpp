//#pragma GCC optimize(2)
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
inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
const int MAXN = 2e5 + 5;
int a[MAXN], n, prime[20005], cnt = 0, mu[MAXN], vis[MAXN];
//vector < int > d[MAXN];
void init(int n) {
	mu[1] = 1;
	For(i, 2, n) {
		if(!vis[i]) prime[++cnt] = i, mu[i] = -1;
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				mu[i * prime[j]] = 0; break;
			} else mu[i * prime[j]] = -mu[i];
		}
	}
//	For(i, 1, n)
//		for(rint j = 1; j * i <= n; j++)
//			d[i * j].pb(i);
}
int u[MAXN], v[MAXN];
vector < int > e[MAXN];
int f[MAXN], siz[MAXN];
inline int find(int x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}

ll tans[MAXN], ans[MAXN];
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	init(200000);
	FI(n);
	For(i, 1, n) FI(a[i]), ans[a[i]]++;
	For(i, 1, n - 1) {
		FI(u[i]), FI(v[i]);
		int d = gcd(a[u[i]], a[v[i]]);
//		for(auto t : ::d[d]) {
//			cerr << d << ' ' << t << endl;
//			e[t].pb(mkp(u, v));
//		}
		for(int j = 1; j * j <= d; j++) {
			if(d % j == 0) {
				e[j].pb(i);
				if(j * j != d) e[d / j].pb(i);
			}
		}
	}
	For(i, 0, n) f[i] = i, siz[i] = 1;
	foR(i, 200000, 1) {
//		For(i, 1, n) assert(f[i] == i && siz[i] == 1);
		for(auto t : e[i]) {
			int u = ::u[t], v = ::v[t], fu = find(u), fv = find(v);
			f[fv] = fu, tans[i] += 1ll * siz[fu] * siz[fv], siz[fu] += siz[fv];
		}
		for(auto t : e[i]) {
			int u = ::u[t], v = ::v[t];
			f[u] = u, f[v] = v; siz[u] = siz[v] = 1;
		}
	}
//	For(i, 1, n) cerr << mu[i] << endl;
	For(i, 1, 200000)
		for(int j = 1; j * i <= 200000; j++)
			ans[i] += tans[i * j] * mu[j];
	For(i, 1, 200000) {
		if(ans[i]) {
			printf("%d %lld\n", i, ans[i]);
		}
	}
    return FastIO::Fflush(), 0;
}