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
//#define int long long
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
inline int read() {rint x; FI(x); return x;}
const int MAXN = 6e5 + 5; 
struct Segment_tree {
	static const int N = MAXN << 2;
	int a[N], tag[N];
	Segment_tree() {}
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	inline int merge(int x, int y) {return min(x, y);}
	inline void pushr(int k, int val) {a[k] += val, tag[k] += val;}
	inline void pushdown(int k) {if(tag[k]) pushr(ls, tag[k]), pushr(rs, tag[k]), tag[k] = 0;}
	void update(int k, int l, int r, int ql, int qr, int val) {
		if(ql > qr) return;
		if(l == ql && r == qr) return pushr(k, val); pushdown(k);
		if(qr <= mid) update(ls, l, mid, ql, qr, val);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, val);
		else update(ls, l, mid, ql, mid, val), update(rs, mid+1, r, mid+1, qr, val);
		a[k] = merge(a[ls], a[rs]);
	}
	int query(int k, int l, int r, int pos) {
		if(l == r) return a[k] == 0; pushdown(k);
		return pos <= mid ? query(ls, l, mid, pos) : query(rs, mid+1, r, pos);
	}
	int find(int k, int l, int r) {
		if(l == r) return l; pushdown(k);
		return a[ls] == 0 ? find(ls, l, mid) : find(rs, mid+1, r);
	}
	#undef mid
}tr;
int n, a[MAXN], s[MAXN], top, tp[MAXN], id[MAXN], cnt, L[MAXN], R[MAXN], M[MAXN]; // 1 : 0 :  
stack < int > s1, s2;
namespace XHTree {
	vector < int > e[MAXN]; int rt;
	ll dfs(int u = rt) {
//		cerr << u << endl;
		if(!e[u].size()) return 1; ll tmp = e[u].size();
		ll res = tp[u] ? tmp * (tmp - 1) / 2 : 1;
		for(auto v : e[u]) res += dfs(v);
		return res;
	}
};
inline void add(int u, int v) {
	XHTree::e[u].pb(v);
//	cerr << "add " << u << ' ' << v << endl;
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    n = read();
    For(i, 1, n) {int x = read(), y = read(); a[x] = y;}
    s1.push(0), s2.push(0);
    For(i, 1, n) {
//    	fprintf(stderr, "point %d\n", i);
    	while(s1.size() > 1 && a[i] > a[s1.top()]) {
    		int now = s1.top(); s1.pop();
    		tr.update(1, 1, n, s1.top() + 1, now, a[i] - a[now]);
		}
		while(s2.size() > 1 && a[i] < a[s2.top()]) {
			int now = s2.top(); s2.pop();
			tr.update(1, 1, n, s2.top() + 1, now, a[now] - a[i]);
		}
    	tr.update(1, 1, n, 1, i - 1, -1); s1.push(i), s2.push(i);
    	int pos = tr.find(1, 1, n);
    	id[i] = ++cnt; int cur = cnt; L[cur] = R[cur] = i;
//    	cerr << pos << endl;
//    	For(i, 1, n) cerr << tr.query(1, 1, n, i, i) << endl;
    	while(top && L[s[top]] >= pos) {
    		int p = s[top]; 
//			cerr << p << '?' << L[p] << ' ' << R[p] << endl;
    		if(tp[p] && tr.query(1, 1, n, M[p])) {
    			add(p, cur); R[p] = i; cur = s[top--];
			} else if(tr.query(1, 1, n, L[p])) {
//				cerr << "?";
				tp[++cnt] = 1, L[cnt] = L[p], R[cnt] = i, M[cnt] = L[cur];
				add(cnt, s[top--]); add(cnt, cur); cur = cnt;
			} else {
				add(++cnt, cur);
				do {
					add(cnt, s[top--]);
				} while(top && !tr.query(1, 1, n, L[s[top]]));
				L[cnt] = L[s[top]], R[cnt] = i; add(cnt, s[top--]);
				cur = cnt;
			}
		}
		s[++top] = cur;
	}
	XHTree::rt = s[1];
	cout << XHTree::dfs() << endl;
    return FastIO::Fflush(), 0;
}
/*

*/