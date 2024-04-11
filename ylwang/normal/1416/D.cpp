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
const int MAXN = 1e6 + 5;
int n, m, q, a[MAXN], o[MAXN], p[MAXN], u[MAXN], v[MAXN], used[MAXN];
vector < int > e[MAXN];

int f[MAXN], cnt = 0;
inline int find(int x) {
	while(x != f[x]) x = f[x] = f[f[x]];
	return x;
}
inline void merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	cnt++; e[cnt].pb(f[x]), e[cnt].pb(f[y]);
	f[x] = f[y] = cnt;
}

int dfn[MAXN], id[MAXN], siz[MAXN], ind;
inline void dfs(int u) {
	id[dfn[u] = ++ind] = u, siz[u] = 1;
	for(auto v : e[u]) {
		dfs(v), siz[u] += siz[v];
	}
}
struct Segment_tree {
	pair < int, int > mx[MAXN << 2];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	pair < int, int > merge(pair < int, int > a, pair < int, int > b) {
		if(a.first > b.first) return a;
		else return b;
	}
	void update(int k, int l, int r, int pos, int val) {
		if(l == r) return mx[k] = mkp(val, l), void();
		pos <= mid ? update(ls, l, mid, pos, val) : update(rs, mid+1, r, pos, val);
		mx[k] = merge(mx[ls], mx[rs]);
	}
	
	Pair query(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return mx[k];
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return merge(query(ls, l, mid, ql, mid), query(rs, mid+1, r, mid+1, qr));
	}
}tr;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    cin >> n >> m >> q;
    For(i, 1, n) FI(a[i]);
    For(i, 1, m) FI(u[i]), FI(v[i]);
    For(i, 1, q) {
    	FI(o[i]), FI(p[i]);
    	if(o[i] == 2) used[p[i]] = 1;
	}
	For(i, 1, 2 * n) f[i] = i; cnt = n;
	For(i, 1, m)
		if(!used[i]) merge(u[i], v[i]);
    foR(i, q, 1) {
    	if(o[i] == 1) p[i] = find(p[i]);
		else merge(u[p[i]], v[p[i]]);
	}
//	cerr << "?";
	cnt++;
	For(i, 1, cnt - 1)
		if(find(i) == i) e[cnt].pb(i);
	dfs(cnt);
//	For(i, 1, n) cerr << dfn[i] << endl;
	For(i, 1, n) tr.update(1, 1, cnt, dfn[i], a[i]);
	For(i, 1, q) {
		if(o[i] == 1) {
//			cerr << p[i] << endl;
//			cerr << dfn[p[i]] << ' ' << dfn[p[i]] + siz[p[i]] - 1 << endl;
			Pair res = tr.query(1, 1, cnt, dfn[p[i]], dfn[p[i]] + siz[p[i]] - 1);
			printf("%d\n", res.first); 
//			cerr << res.second << endl;
			tr.update(1, 1, cnt, res.second, 0);
		}
	}
    return 0;
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