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
int n, m, h, a[MAXN], b[MAXN];
struct Segment_tree {
	static const int N = MAXN << 2;
	int mn[N], tag[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void build(int k, int l, int r) {
		if(l == r) return mn[k] = -l, tag[k] = 0, void();
		build(ls, l, mid), build(rs, mid+1, r);
		mn[k] = min(mn[ls], mn[rs]);
	}
	inline void pushr(int k, int v) {
		mn[k] += v, tag[k] += v;
	}
	void update(int k, int l, int r, int ql, int qr, int v) {
//		cerr << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
		if(l == ql && r == qr) return pushr(k, v), void();
		if(tag[k]) pushr(ls, tag[k]), pushr(rs, tag[k]), tag[k] = 0;
		if(qr <= mid) update(ls, l, mid, ql, qr, v);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, v);
		else update(ls, l, mid, ql, mid, v), update(rs, mid+1, r, mid+1, qr, v);
		mn[k] = min(mn[ls], mn[rs]);
	}
}tr;
void modify(int x, int v) {
	int p = lower_bound(b + 1, b + 1 + m, x) - b;
	if(p <= m) tr.update(1, 1, m, p, m, v);
}
signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
	#endif
	FI(n); FI(m); FI(h);
	For(i, 1, m) FI(b[i]);
	sort(b + 1, b + 1 + m);
	tr.build(1, 1, m);
	For(i, 1, n) FI(a[i]), a[i] = h - a[i];
	For(i, 1, m) modify(a[i], 1);
	int ans = (tr.mn[1] >= 0);
	For(i, 2, n - m + 1) {
		modify(a[i - 1], -1), modify(a[i + m - 1], 1);
		ans += (tr.mn[1] >= 0);
	}	
	cout << ans << endl;
    return FastIO::Fflush(), 0;
}