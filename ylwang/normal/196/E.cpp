#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back // !
#define mkp make_pair
#define INF (1ll << 62)
#define rint register int
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
const int MAXN = 2e5 + 5;
int n, m, k, ik[MAXN];
struct Edge {
	int v, w, nxt;
}e[MAXN];
struct Tri {
	int u, v, w;
	bool operator < (const Tri &b) const {return w < b.w;}
}g[MAXN];
int lst[MAXN], tot = 0;
inline void addedge(int u, int v, int w) {
	e[++tot]  = (Edge) {v, w, lst[u]};
	lst[u] = tot;
}
struct Node {
	int x, y, z;
	bool operator < (const Node &b) const {return z > b.z;}
}; 
int d[MAXN], key[MAXN], p[MAXN], used[MAXN];
priority_queue < Node > q;
void Dij() {
	For(i, 0, n) d[i] = INF, used[i] = 0;
	For(i, 1, k) q.push((Node){key[i], p[key[i]] = key[i], d[key[i]] = 0});
	while(q.size()) {
		int u = q.top().x, p = q.top().y; q.pop();
//		cerr << u << ' ' << p << ' ' << endl;
		if(used[u]) continue; used[u] = 1;
		Foe(i, u) {
//			cerr << u << ' ' << v << ' ' << e[i].w << endl;
			if(d[v] > d[u] + e[i].w) {
				d[v] = d[u] + e[i].w, ::p[v] = p;
				q.push((Node) {v, p, d[v]});
			}
		}
	}
}
int f[MAXN];
inline int find(int x) {
	while(x != f[x]) x = f[x] = f[f[x]];
	return x;
}
signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
	#endif
	FI(n), FI(m); 
	For(i, 1, m) {
		int u, v, w; FI(u), FI(v), FI(w);
//		cerr << u << ' ' << v << ' ' << w << endl;
		addedge(u, v, w), addedge(v, u, w);
		g[i] = (Tri) {u, v, w};
	}
	FI(k);
	For(i, 1, k) FI(key[i]), ik[key[i]] = 1;
	Dij();
//	cerr << "?";
//	For(i, 1, n) cerr << d[i] << endl;
	For(i, 1, m) {
		g[i].w = d[g[i].u] + d[g[i].v] + g[i].w;
		g[i].u = p[g[i].u],  g[i].v = p[g[i].v];
//		cerr << g[i].u << ' ' << g[i].v << ' ' << g[i].w << endl;
	}
	For(i, 1, n) f[i] = i;
	int res = 0;
	sort(g + 1, g + 1 + m);
	For(i, 1, m) {
		int fu = find(g[i].u), fv = find(g[i].v);
		if(fu == fv) continue;
		f[fv] = fu, res += g[i].w;
	}
//	cerr << res << endl;
	printf("%lld\n", res + (!ik[1]) * d[1]);
    return FastIO::Fflush(), 0;
}