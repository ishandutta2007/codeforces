#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define ull unsigned ll
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); --i)
#define For(i, k, j) for(rint i = (k); i <= (j); ++i)
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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 1e6 + 5;
const int MAXA = 1e7 + 5;
const int MAXP = 7e5 + 5;
int n, m, t, a[MAXN], ans[MAXN], mul[MAXN], ivm[MAXN];
vector < Pair > q[MAXN];

vector < int > d[MAXA];
int prime[MAXP], vp[MAXP], ivp[MAXP], cnt = 0, exi[MAXA], vis[MAXA], lst[MAXP];
inline void init() {
	For(i, 2, t) {
		if(!vis[i]) prime[++cnt] = i, vp[cnt] = 1ll * (prime[cnt] - 1) * inv(prime[cnt]) % P, ivp[cnt] = inv(vp[cnt]);
		for(int j = 1; i * prime[j] <= t && j <= cnt; j++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}	
	}
	For(i, 1, cnt) for(rint j = 1; j * prime[i] <= t; j++)
		if(exi[j * prime[i]]) d[j * prime[i]].pb(i);
}
struct BIT {
	int c[MAXN];
	void init() {For(i, 1, n) c[i] = 1;}
	inline void update(int x, int v) {for(; x <= n; x += (x & -x)) c[x] = 1ll * c[x] * v % P;}
	inline int query(int x) {
		int res = 1; for(; x; x -= (x & -x)) res = 1ll * res * c[x] % P;
		return res;
	}
	inline int getmul(int l, int r) {
		return 1ll * query(r) * inv(query(l - 1)) % P;
	}
}bit;
signed main()
{
//	file("szh");
	FI(n); 
	For(i, 1, n) FI(a[i]), ckmax(t, a[i]), exi[a[i]] = 1;
	FI(m);
	mul[0] = ivm[0] = 1; For(i, 1, n) mul[i] = 1ll * mul[i-1] * a[i] % P, ivm[i] = inv(mul[i]);
	init(); bit.init();
	For(i, 1, m) {
		int l, r; FI(l), FI(r); if(l > r) swap(l, r);
		q[r].pb(mkp(l, i));
	}
	For(i, 1, n) {
		for(auto p : d[a[i]]) {
			if(lst[p]) bit.update(lst[p], ivp[p]);
			bit.update(i, vp[p]); lst[p] = i;
		}
		for(auto t : q[i])
			ans[t.second] = 1ll * mul[i] * ivm[t.first - 1] % P * bit.getmul(t.first, i) % P;
		
	}
	For(i, 1, m)
		FO(ans[i]), FO('\n');
	
    return FastIO::Fflush(), 0;
}
/*

*/