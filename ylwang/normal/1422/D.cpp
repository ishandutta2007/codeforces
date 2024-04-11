#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1ll << 62) - 1)
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
const int P = 998244353; //
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
inline int read() {int x; FI(x); return x;}
const int MAXN = 2e5 + 5;
int n, m, sx, sy, ex, ey;
struct Node {
	int x, y, id;
}a[MAXN];
bool cmp1(Node a, Node b) {return a.x < b.x;}
bool cmp2(Node a, Node b) {return a.y < b.y;}
bool cmp3(Node a, Node b) {return a.id < b.id;}
struct Edge {
	int v, w, nxt;
}e[MAXN << 2];
int lst[MAXN], tot = 0;
inline void addedge(int u, int v, int w) {
	e[++tot] = (Edge) {v, w, lst[u]};
	lst[u] = tot;
	e[++tot] = (Edge) {u, w, lst[v]};
	lst[v] = tot;
}
ll dis[MAXN]; int used[MAXN];
struct PQ {
	int x; ll y; PQ(int tx, ll ty) : x(tx), y(ty) {}
	bool operator < (const PQ &b) const {return y > b.y;}
};
priority_queue < PQ > q;
inline void Dij() {
	For(i, 0, m) dis[i] = INF; mst(used, 0);
	dis[0] = 0, q.push(PQ(0, 0));
	while(!q.empty()) {
		int u = q.top().x; q.pop();
		if(used[u]) continue; used[u] = 1;
		Foe(i, u) {
			if(dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				q.push(PQ(v, dis[v]));
			}
		}
	}
}

signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    n = read(), m = read(), sx = read(), sy = read(), ex = read(), ey = read();
    a[0].x = sx, a[0].y = sy, a[0].id = 0;
    For(i, 1, m) {
    	a[i].x = read(), a[i].y = read(), a[i].id = i;
	}
	sort(a, a + 1 + m, cmp1);
	For(i, 1, m)
		addedge(a[i-1].id, a[i].id, a[i].x - a[i-1].x);
	sort(a, a + 1 + m, cmp2);
	For(i, 1, m)
		addedge(a[i-1].id, a[i].id, a[i].y - a[i-1].y);
	Dij();
	sort(a, a + 1 + m, cmp3);
	ll ans = INF;
	For(i, 0, m) {
		ckmin(ans, (int)dis[i] + abs(a[i].x - ex) + abs(a[i].y - ey));
	}
	cout << ans << endl;
    return FastIO::Fflush(), 0;
}
/*

*/