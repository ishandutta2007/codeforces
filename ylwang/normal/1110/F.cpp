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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 5e5 + 5;
int n, m, dis[MAXN], dep[MAXN], L[MAXN], R[MAXN], cnt = 0, id[MAXN], ind = 0, pos[MAXN];
vector < Pair > e[MAXN];

struct Segment_tree {
	static const int N = MAXN << 2;
	int mn[N], tag[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void build(int k, int l, int r) {
		if(l == r) return mn[k] = dis[id[l]], void();
		build(ls, l, mid); build(rs, mid+1, r);
		mn[k] = min(mn[ls], mn[rs]);
	}
	inline void pushr(int k, int v) {
		mn[k] += v, tag[k] += v;
	}
	void update(int k, int l, int r, int ql, int qr, int val) {
		if(l == ql && r == qr) return pushr(k, val);
		if(tag[k]) pushr(ls, tag[k]), pushr(rs, tag[k]), tag[k] = 0;
		if(qr <= mid) update(ls, l, mid, ql, qr, val);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, val);
		else update(ls, l, mid, ql, mid, val), update(rs, mid+1, r, mid+1, qr, val);
		mn[k] = min(mn[ls], mn[rs]);
	}
	int query(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return mn[k];
		if(tag[k]) pushr(ls, tag[k]), pushr(rs, tag[k]), tag[k] = 0;
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return min(query(ls, l, mid, ql, mid), query(rs, mid+1, r, mid+1, qr));
	}
}tr;
void dfs1(int u, int fa) {
	dep[u] = dep[fa] + 1, L[u] = INF, R[u] = -1; ind++;
	for(auto t : e[u]) {
		int v = t.first, w = t.second;
		dis[v] = dis[u] + w; dfs1(v, u);
		ckmin(L[u], L[v]); ckmax(R[u], R[v]);
	}
	if(L[u] == INF)
		L[u] = R[u] = ++cnt, id[cnt] = u, pos[cnt] = ind;
};
struct Query {
	int id, l, r;
};
vector < Query > q[MAXN]; int ans[MAXN], tot = 0;
void dfs2(int u, int fa) {
	for(auto t : q[u])
		ans[t.id] = tot + tr.query(1, 1, cnt, t.l, t.r);
	for(auto t : e[u]) {
		int v = t.first, w = t.second;
		tr.update(1, 1, cnt, L[v], R[v], -2 * w); tot += w;
		dfs2(v, u);
		tr.update(1, 1, cnt, L[v], R[v], 2 * w); tot -= w;
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n); FI(m);
	For(i, 2, n) {
		int f, w; FI(f); FI(w);
		e[f].pb(mkp(i, w));
	}
	dfs1(1, 0);
	tr.build(1, 1, cnt);
	For(i, 1, m) {
		int u, l, r; FI(u), FI(l), FI(r);
		l = lower_bound(pos + 1, pos + 1 + cnt, l) - pos, r = upper_bound(pos + 1, pos + 1 + cnt, r) - pos - 1;
		q[u].pb((Query) {i, l, r});
	}
	dfs2(1, 0);
	For(i, 1, m)
		FO(ans[i]), FO('\n');
	
    return FastIO::Fflush(), 0;
}
/*

*/