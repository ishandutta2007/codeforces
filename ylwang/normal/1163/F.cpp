#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define rint register int
#define INF ((1ll << 60) - 1)
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
const int MAXN = 4e5 + 5;
struct Edge {
	int v, w, nxt;
}e[MAXN << 1];
int lst[MAXN], tot = 1, n, m, u[MAXN], v[MAXN], w[MAXN];
inline void addedge(int u, int v, int w) {
	e[++tot] = (Edge) {v, w, lst[u]};
	lst[u] = tot;
}
int dis[2][MAXN], used[MAXN];
struct Node {
	int u, y; 
	bool operator < (const Node &b) const {return y > b.y;}
};
priority_queue < Node > q;
void Dij(int s, int o) {
	For(i, 1, n) dis[o][i] = INF; mst(used, 0);
	q.push((Node) {s, dis[o][s] = 0});
	while(!q.empty()) {
		int u = q.top().u; q.pop();
		if(used[u]) continue; used[u] = 1;
		Foe(i, u) {
			if(dis[o][v] > dis[o][u] + e[i].w)
				dis[o][v] = dis[o][u] + e[i].w, q.push((Node) {v, dis[o][v]});
		} 
	}
}
int id[MAXN], dfn[MAXN], cnt, flag = 0, vis[MAXN]; // id :  dfn :  
void dfs(int u, int fa, int fr) {
	vis[u] = 1;
	if(flag) return; dfn[u] = ++cnt, id[cnt] = u; used[fr >> 1] = cnt - 1;
	if(u == n) return flag = 1, void();
	Foe(i, u) {
		if(v == fa || dis[0][v] != dis[0][u] + e[i].w || vis[v]) continue;
		dfs(v, u, i);
	}
	if(flag) return;
	dfn[u] = 0; used[fr >> 1] = 0, cnt--;
}
int L[MAXN], R[MAXN];

int ccnt[MAXN];
void dfs1(int now, int u, int fr) {
	L[u] = now; ccnt[u]++; assert(ccnt[u] <= 1);
	Foe(i, u) {
		if(v == fr || dis[0][v] != dis[0][u] + e[i].w || L[v] || dfn[v]) continue;
		dfs1(now, v, u);
	}
}
void dfs2(int now, int u, int fr) {
	R[u] = now;
	Foe(i, u) {
		if(v == fr || dis[1][v] != dis[1][u] + e[i].w || R[v] || dfn[v]) continue;
		dfs2(now, v, u);
	}
}
int ans[MAXN];
struct Segment_tree {
	static const int N = MAXN << 2;
	int tag[N];
	Segment_tree() {For(i, 1, N - 5) tag[i] = INF;}
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void update(int k, int l, int r, int ql, int qr, int v) {
		if(l == ql && r == qr) return ckmin(tag[k], v);
		if(qr <= mid) update(ls, l, mid, ql, qr, v);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, v);
		else update(ls, l, mid, ql, mid, v), update(rs, mid+1, r, mid+1, qr, v);
	}
	void dfs(int k, int l, int r, int now) {
//		cerr << k << ' ' << l << ' ' << r << ' ' << tag[k] << endl;
		ckmin(now, tag[k]); if(l == r) return ans[l] = now, void();
		dfs(ls, l, mid, now), dfs(rs, mid+1, r, now);
	}
}tr;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); FI(m); int Q; FI(Q);
//    cerr << n << ' ' << m << ' ' << Q << endl;
    For(i, 1, m) {
    	FI(u[i]), FI(v[i]), FI(w[i]);
    	addedge(u[i], v[i], w[i]); addedge(v[i], u[i], w[i]);
	}
	Dij(1, 0); Dij(n, 1);
	mst(used, 0);
	dfs(1, 0, 0);
	foR(i, cnt, 1) dfs1(i, id[i], 0);
	For(i, 1, cnt) dfs2(i, id[i], 0);
//	For(i, 1, cnt) cerr << i << ' ' << id[i] << endl;
//	For(i, 1, n) cerr << ' ' << L[i] << ' ' << R[i] << endl;
//	For(i, 1, m) cerr << used[i] << endl;
	For(u, 1, n) Foe(i, u) if(!used[i >> 1] && L[u] < R[v]) {

//		cerr << u << ' ' << v << ' ' << dis[0][u] << ' ' << dis[1][v] << ' ' << e[i].w << endl;
		tr.update(1, 1, cnt - 1, L[u], R[v] - 1, dis[0][u] + e[i].w + dis[1][v]);
	}
	tr.dfs(1, 1, cnt - 1, INF);
//	For(i, 1, cnt - 1) cerr << ans[i] << endl;
	while(Q--) {
//		cerr << "?";
		int t, x; FI(t); FI(x);
		if(!used[t] && x > w[t]) {
			printf("%lld\n", dis[0][n]);
//			if(n == 69 && m == 68 && u[1] == 1) printf("!\n");
		}
		else if(!used[t] && x <= w[t]) {
			printf("%lld\n", min(dis[0][n], min(dis[0][u[t]] + x + dis[1][v[t]], dis[0][v[t]] + x + dis[1][u[t]])));
		}
		else if(used[t] && x <= w[t] ) {
			printf("%lld\n", dis[0][n] + x - w[t]);
		}
		else {
			assert(used[t] && x > w[t]);
			printf("%lld\n", min(dis[0][n] + x - w[t], ans[used[t]]));
//			cerr << t << ' ' << ans[used[t]] << endl;
		}
	}
    return FastIO::Fflush(), 0;
}
/*

4 7 1
2 1 8
2 4 2
4 3 2
3 2 8
2 3 5
4 3 1
2 4 5
2 9
*/