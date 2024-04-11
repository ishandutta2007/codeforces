#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
#define int long long
const int P = 1000000009; //
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
inline int read() {rint x; FI(x); return x;}
const int MAXN = 3e5 + 5;
#define vi vector < int > 
vi a, st; int n, m, val[MAXN];
int mu[MAXN], prime[MAXN], tot, vis[MAXN];
void init(int n = MAXN - 5) {
	mu[1] = 1;
	For(i, 2, n) {
		if(!vis[i]) prime[++tot] = i, mu[i] = -1;
		for(int j = 1; j <= tot && i * prime[j] <= n; j++) {
			int to = i * prime[j]; vis[to] = 1;
			if(i % prime[j] == 0) {
				mu[to] = 0; break;
			} else mu[to] = -mu[i];
		}
	}
//	cerr << "?";
}
vi operator * (const vi &a, const vi &b) {
	vi ans(m + 5);
	For(i, 1, m) {
		int t1 = 0, t2 = 0;
		for(int j = 1; i * j <= m; j++)
			t1 += a[i * j], t2 += b[i * j];
		ans[i] = t1 * t2;
	}
	For(i, 1, m)
		for(int j = 2; i * j <= m; j++)
			ans[i] += ans[i * j] * mu[j];
	return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
	n = read(); 
	For(i, 1, n)
		val[i] = read(), ckmax(m, val[i]);
	init(); st.resize(m + 5); 
	For(i, 1, n) st[val[i]] = 1;
	if(st[1]) return printf("1\n"), 0;
	a = st;
	For(i, 1, 6) {
		a = a * st;
		if(a[1]) return printf("%lld\n", i + 1), 0;
	}
	printf("-1\n");
    return FastIO::Fflush(), 0;
}
/*

*/