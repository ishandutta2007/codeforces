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
const int P = 998244853; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
 
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
const int MAXN = 2e5 + 5;
struct Edge {
	int v, w, nxt;	
}e[MAXN]; 
int lst[MAXN], tot = 0, n, m, siz[MAXN], s[MAXN];
inline void addedge(int u, int v, int w) {
	e[++tot] = (Edge) {v, w, lst[u]};
	lst[u] = tot;
};
void dfs1(int u, int fa) {
	Foe(i, u) {
		if(v == fa) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if(siz[v]) s[u] += s[v] + 2 * e[i].w;
	}
}
bool cmp(Pair a, Pair b) {
	return 1.0 * a.first / a.second > 1.0 * b.first / b.second;
}
int cnt = 0;
Pair a[MAXN];
double f[MAXN];
void dfs2(int u, int fa) {
	Foe(i, u) {
		if(v == fa) continue;
		dfs2(v, u); f[u] += (f[v] + e[i].w) * siz[v];
	}
	cnt = 0;
	Foe(i, u) {
		if(v == fa) continue;
		a[++cnt] = mkp(siz[v], s[v] + 2 * e[i].w);
	}
	sort(a + 1, a + 1 + cnt, cmp);
	double sum = 0;
	For(i, 1, cnt) {
		f[u] += a[i].first * sum;
		sum += a[i].second;
	}
	f[u] /= siz[u];
} 
signed main()
{
	FI(n); 
//	FI(m);
//	For(i, 1, m) {
//		int x; FI(x);
//		o[x] = siz[x] = 1;
//	}
	For(i, 2, n) siz[i] =1 ;
	For(i, 1, n-1) {
		int u, v, w; FI(u); FI(v); FI(w);
		addedge(u, v, w); addedge(v, u, w);
	}
	dfs1(1, 0);
//	For(i, 1, n) {
//		cerr << siz[i] << ' ' << s[i] << endl;
//	} 
	dfs2(1, 0);
//	For(i, 1, n) {
//		cerr << f[i] << ' ' << s[i] << endl;
//	}
	printf("%.8lf\n", f[1]);
    return FastIO::Fflush(), 0;
} 
/*
4 3
2 3 4
1 3 2
4 2 1
3 2 3

*/