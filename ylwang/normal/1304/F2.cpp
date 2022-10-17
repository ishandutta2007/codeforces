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
const int MAXN = 65;
const int MAXM = 4e4 + 5;
int a[MAXN][MAXM], n, m, k, sum[MAXN][MAXM], f[MAXN][MAXM];
int calc(int i, int j, int l, int r) {int res = 0;For(t, i, j) res += sum[t][r] - sum[t][l-1];return res;}
struct Segment_tree {
	static const int N = MAXM << 2;
	int mx[N], tag[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	inline void build(int i, int k, int l, int r) {
		tag[k] = 0;
		if(l == r) return mx[k] = f[i-1][l], void();
		build(i, ls, l, mid), build(i, rs, mid+1, r);
		mx[k] = max(mx[ls], mx[rs]); 
	}
	void pushr(int k, int v) {mx[k] += v, tag[k] += v;}
	inline void update(int k, int l, int r, int ql, int qr, int v) {
//		cerr << k << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
		if(l == ql && r == qr) return pushr(k, v), void();
		if(tag[k]) pushr(ls, tag[k]), pushr(rs, tag[k]), tag[k] = 0;
		if(qr <= mid) update(ls, l, mid, ql, qr, v);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, v);
		else update(ls, l, mid, ql, mid, v), update(rs, mid+1, r, mid+1, qr, v);
		mx[k] = max(mx[ls], mx[rs]);
	}
}tr;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); FI(m); FI(k);
    For(i, 1, n) For(j, 1, m)
		FI(a[i][j]), sum[i][j] = sum[i][j-1] + a[i][j];
	
	mst(f, -127 / 2);
	For(i, 1, m - k + 1) f[1][i] = calc(1, 2, i, i+k-1);
	For(i, 2, n) {
		tr.build(i, 1, 1, m);
		For(j, 1, k)
			tr.update(1, 1, m, 1, j, -a[i][j]);
		
		For(j, 1, m - k + 1) {
			f[i][j] = tr.mx[1] + calc(i, i+1, j, j+k-1);
//			cerr << tr.mx[1] << ' ';
			tr.update(1, 1, m, max(1, j - k + 1), j, a[i][j]);
			if(j != m - k + 1) tr.update(1, 1, m, j + 1, j + k, -a[i][j + k]);
		}
	}
//	For(i, 1, n) {
//		For(j, 1, m) cerr << f[i][j] << ' ';
//		cerr << endl;
//	}
	int res = 0;
	For(i, 1, m) ckmax(res, f[n][i]);
	cout << res << endl;
    return FastIO::Fflush(), 0;
}
/*
Think twice!
*/