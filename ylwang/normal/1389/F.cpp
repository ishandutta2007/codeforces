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
const int P = 998244353; //
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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 4e5 + 5;
struct Line {
	int l, r, op;
}a[MAXN]; int n;
int disc[MAXN], t = 0, dp[MAXN][3];
vector < int > e[MAXN];
struct Segment_tree {
	vector < int > mx, tag;
	void init(int tn) {
		mx.resize(tn<<2); tag.resize(tn<<2);
	}
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void pushdown(int k) {
		if(tag[k]) {
			mx[ls] += tag[k], tag[ls] += tag[k];
			mx[rs] += tag[k], tag[rs] += tag[k];
			tag[k] = 0;
		}
	}
	void update(int k, int l, int r, int ql, int qr, int val)  {
//		cerr << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
		if(l == ql && r == qr) {
			return mx[k] += val, tag[k] += val, void();
		}
		pushdown(k);
		if(qr <= mid) update(ls, l, mid, ql, qr, val);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, val);
		else update(ls, l, mid, ql, mid, val), update(rs, mid+1, r, mid+1, qr, val);
		mx[k] = max(mx[ls], mx[rs]);
	}
	int query() {
		return mx[1];
	}
}tr1, tr2;
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n);
	For(i, 1, n) {
		FI(a[i].l); FI(a[i].r); FI(a[i].op);
		disc[++t] = a[i].l, disc[++t] = a[i].r;
	}
	sort(disc + 1, disc + 1 + t);
	t = unique(disc + 1, disc + 1 + t) - disc - 1;
	For(i, 1, n) {
		a[i].l = lower_bound(disc+1, disc+1+t, a[i].l) - disc;
		a[i].r = lower_bound(disc+1, disc+1+t, a[i].r) - disc;
		e[a[i].r].pb(i);
	}
	tr1.init(t+1), tr2.init(t+1);
	For(i, 1, t) {
		for(auto it : e[i]) {
			if(a[it].op == 1) tr1.update(1, 1, t, 1, a[it].l, 1);
			if(a[it].op == 2) tr2.update(1, 1, t, 1, a[it].l, 1);
		}
		dp[i][2] = tr1.query(), dp[i][1] = tr2.query();
		if(i != t) tr1.update(1, 1, t, i+1, i+1, dp[i][1]);
		if(i != t) tr2.update(1, 1, t, i+1, i+1, dp[i][2]);
	}
	cout << max(dp[t][1], dp[t][2]) << endl;
    return FastIO::Fflush(), 0;
}
/*

*/