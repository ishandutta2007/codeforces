
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define si set < int >
#define vi vector < int >
#define pii pair < int, int >
#define mii map < int, int >
#define p_q priority_queue
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(int i = (k); i >= (j); i--)
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define Foe(i, u) for(int i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
//#define int long long
const int P = 1000000007; //
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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
#define eps (1e-6)
inline int read() {int x; FI(x); return x;}
const int MAXN = 5e5 + 5;
int n, m, a[MAXN], b[MAXN], p[MAXN];
struct Segment_tree {
	static const int N = MAXN << 2;
	int a[N], tag[N];
	Segment_tree() {mst(tag, -1);}
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	int merge(int x, int y) {return max(x, y);}
	inline void pushr(int k, int l, int r, int val) {a[k] = val, tag[k] = val;}
	inline void pushdown(int k, int l, int r) {
		if(tag[k] != -1) pushr(ls, l, mid, tag[k]), pushr(rs, mid+1, r, tag[k]), tag[k] = -1;
	}
	void update(int k, int l, int r, int ql, int qr, int val) {
		if(l == ql && r == qr) return pushr(k, l, r, val);
		pushdown(k, l, r);
		if(qr <= mid) update(ls, l, mid, ql, qr, val);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, val);
		else update(ls, l, mid, ql, mid, val), update(rs, mid+1, r, mid+1, qr, val);
		a[k] = merge(a[ls], a[rs]);
	}
	int query(int k, int l, int r, int ql, int qr) {
//		cerr << k << ' ' << l << ' ' <<  r << ' ' << ql << ' ' << qr << endl;
		if(l == ql && r == qr) return a[k];
		pushdown(k, l, r);
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return merge(query(ls, l, mid, ql, mid), query(rs, mid+1, r, mid+1, qr));
	}
	#undef mid
}tr;
int disc[MAXN], t;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    n = read(), m = read();
    For(i, 1, n) disc[i] = a[i] = read() - i; sort(disc + 1, disc + 1 + n);
	For(i, 1, m) b[p[i] = read()] = 1;
	For(i, 2, m) if(a[p[i]] < a[p[i-1]]) {
    	printf("-1\n"); return 0;
	}
	For(i, 1, n) a[i] = lower_bound(disc + 1, disc + 1 + n, a[i]) - disc;
//	For(i, 1, n) cerr << a[i] << endl;
	
    
//	if(n == 20) return 0;
	p[0] = 0, p[m + 1] = n + 1; a[0] = 0; a[n + 1] = INF; int ans = 0;
	For(i, 1, m + 1) {
		tr.update(1, 1, n, 1, n, 0); int now = 0;
		For(j, p[i - 1] + 1, p[i] - 1) {
//			cerr << j << endl;
			if(a[p[i - 1]] <= a[j] && a[j] <= a[p[i]]) { int t;
				ckmax(now, t = (tr.query(1, 1, n, 1, a[j]) + 1));
				tr.update(1, 1, n, a[j], a[j], t);
			}
		}
		ans += now;
	}
	cout << n - ans - m << endl;
    return FastIO::Fflush(), 0;
}
/*
 
*/