#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define Pair pair < int, int >
#define mkp make_pair
#define rint register int
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define Foe(i, u) for(register int i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin);freopen(s".out", "w", stdout)
#define INF ((1 << 30) - 1)
#define dprintf(x) fprintf(stderr, "%d ", x)
#define dprintfln(x) fprintf(stderr, "%d\n", x)
#define dln fprintf(stderr, "\n")
#define ull unsigned long long
//#define int long long
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
    for(;isdigit(c);num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 1e5 + 5;
int n, m, dep[MAXN], res[MAXN]; vector < int > e[MAXN];
vector < Pair > Tk[MAXN], q[MAXN]; int S[MAXN], tot = 0;
void dfs1(int u) {
	S[++tot] = u;
//	cout << u << ' ' << dep[u] << endl;
	for(auto t : Tk[u]) {
		if(tot > t.first + 1)
			q[S[tot-t.first]].pb(t);
	}
	for(auto v : e[u]) {
		dep[v] = dep[u] + 1; dfs1(v); 
	}
	tot--;
} 
struct Segment_tree {
	int ls[MAXN*25], rs[MAXN*25], val[MAXN*25], rt[MAXN], tot = 0;
	Segment_tree() {tot = 0;}
	#define mid ((l + r) >> 1)
	void update(int &k, int l, int r, int pos) {
		if(!k) k = ++tot;
		if(l == r) return val[k]++, void();
		if(pos <= mid) update(ls[k], l, mid, pos);
		else update(rs[k], mid+1, r, pos);
		val[k] = val[ls[k]] + val[rs[k]];
	}
	int query(int k, int l, int r, int pos) {
		if(l == r) return val[k];
		return pos <= mid ? query(ls[k], l, mid, pos) : query(rs[k], mid+1, r, pos);
	}
	void merge(int &p, int q, int l, int r) {
		if(!q) return; if(!p) return p = q, void();
		if(l == r) return val[p] += val[q], void();
		merge(ls[p], ls[q], l, mid); merge(rs[p], rs[q], mid+1, r);
		val[p] = val[ls[p]] + val[rs[p]];
	}
}tr;
void dfs2(int u) {
	tr.update(tr.rt[u], 1, n, dep[u]);
	for(auto v : e[u]) {
		dfs2(v);
		tr.merge(tr.rt[u], tr.rt[v], 1, n);
	}
//	cout << u << endl;
	for(auto t : q[u]) {
//		cout << t.first << ' ' << t.second << endl;
		res[t.second] = tr.query(tr.rt[u], 1, n, dep[u] + t.first);
	}
}
signed main()
{
	cin >> n;
	For(i, 1, n)
		e[read()].pb(i);
	cin >> m;
	For(i, 1, m) {
		int x = read(), k = read();
		Tk[x].pb(mkp(k, i));
	}
	dfs1(0);
//	For(i, 1, n) {
//		cout << i << endl;
//		for(auto t : q[i]) {
//			cout << t.first  << ' ' << t.second << endl;
//		}
//	}
//	cout<< endl;
//	mst(res, 0);
	dfs2(0);
	For(i, 1, m) {
		printf("%d ", max(res[i] - 1, 0));
	}
    return 0;
}