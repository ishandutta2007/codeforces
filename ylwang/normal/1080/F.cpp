#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back // !
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
const int MAXN = 3e5 + 5;
int n, Qnum, m, b[MAXN];
struct Node {
	int l, r, p;
	bool operator < (const Node &b) const {return l < b.l;}
}a[MAXN];
int rt[MAXN], tot = 0, mn[MAXN];
struct CM_tree { //  
	static const int N = MAXN * 22;
	int mx[N], c[N][2];
	#define ls (c[p][0])
	#define rs (c[p][1])
	#define mid ((l + r) >> 1)
	void build(int &p, int l, int r) {
		p = ++tot; mx[p] = -1; if(l == r) return;
		build(ls, l, mid); build(rs, mid+1, r);
	}
	void insert(int &p, int q, int l, int r, int pos, int v) {
		p = ++tot; mx[p] = -1;
		if(l == r) return mx[p] = v, void();
		if(pos <= mid) insert(ls, c[q][0], l, mid, pos, v), rs = c[q][1];
		else insert(rs, c[q][1], mid+1, r, pos, v), ls = c[q][0];
		mx[p] = max(mx[ls], mx[rs]);
		if(mx[ls] == -1 || mx[rs] == -1) mx[p] = -1;
	}
	int query(int p, int l, int r, int ql, int qr) {
		if(!p) return 0;
		if(l == ql && r == qr) return mx[p] == -1 ? INF : mx[p];
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return max(query(ls, l, mid, ql, mid), query(rs, mid+1, r, mid+1, qr));
	}
}tr;
int sum[MAXN];
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	scanf("%d %d %d", &n, &Qnum, &m);
	For(i, 1, m) scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].p);
	sort(a + 1, a + 1 + m);
//	For(i, 1, m) {
//		fprintf(stderr, "%d %d %d\n", a[i].l, a[i].r, a[i].p);
//	}
	tr.build(rt[m + 1], 1, n);
	
	mst(mn, 127);
	foR(i, m, 1) {
		ckmin(mn[a[i].p], a[i].r);
//		cerr << a[i].p << ' ' << a[i].r << ' ' << mn[a[i].p] << endl;
		tr.insert(rt[i], rt[i+1], 1, n, a[i].p, mn[a[i].p]), b[i] = a[i].l;
	}
	
//	cerr << tot << endl;
	while(Qnum--) {
		int A, B, x, y; scanf("%d %d %d %d", &A, &B, &x, &y);
		x = lower_bound(b + 1, b + 1 + m, x) - b;
//		cerr << x << endl;
		printf(tr.query(rt[x], 1, n, A, B) <= y ? "yes\n" : "no\n");
		fflush(stdout); 
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