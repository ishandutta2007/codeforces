#pragma GCC optimize(3)
#pragma GCC optimize(2)
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
int n, m, a[MAXN], lst[MAXN], tlst[MAXN];
vector < Pair > q[MAXN];
struct Segment_tree {
	static const int N = MAXN << 2;
	int mn[N];
	Segment_tree() {For(i, 0, N-10) mn[i] = INF;}
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void update(int k, int l, int r, int p, int v) {
		if(l == r) return mn[k] = v, void();
		p <= mid ? update(ls, l, mid, p, v) : update(rs, mid+1, r, p, v);
		mn[k] = min(mn[ls], mn[rs]);
	}
	int query(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return mn[k];
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return min(query(ls, l, mid, ql, mid), query(rs, mid+1, r, mid+1, qr));
	}
}tr;
int ans[MAXN], used[MAXN];
set < int > fir;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n);
    For(i, 1, n) FI(a[i]);
    FI(m);
    For(i, 1, m) {
    	int l, r; FI(l); FI(r);
    	q[r].pb(mkp(l, i));
	}
	For(i, 1, n) {
//		cerr << i << endl;
		
		if(!tlst[a[i]]) fir.insert(i);
		if(tlst[a[i]]) tr.update(1, 1, n, tlst[a[i]], INF), !used[i] ? fir.erase(tlst[a[i]]), used[i] = 1 : -1;
//		for(auto t : fir) {
//			cerr << t << ' ';
//		}
//		cerr << endl;
		tr.update(1, 1, n, i, tlst[a[i]]); tlst[a[i]] = i;
		for(auto t : q[i]) {
			int l = t.first, res = tr.query(1, 1, n, l, i);
//			cerr << t.second << ' ' << res << endl;
			if(res >= l) ans[t.second] = 0;
			else if(res == 0) {
				ans[t.second] = a[*--fir.end()];
			}
			else ans[t.second] = a[res];
		}
	}
	For(i, 1, m) {
		printf("%d\n", ans[i]);
	}
    return FastIO::Fflush(), 0;
}
/*
Think twice :
mod ?
INF ?
n = 1 ?
long long ?
Fastio::Fflush() ?

*/