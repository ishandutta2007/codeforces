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
#define int long long
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
inline int read() {int x; FI(x); return x;}
const int MAXN = 5e5 + 5;
int a[MAXN], n;
struct SMT {
	static const int N = MAXN << 2;
	int sum[N], mx[N], t1[N], t2[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void pushr(int k, int l, int r, int v1, int v2) {
		if(v2) {
			sum[k] = v2 * (r - l + 1); mx[k] = t2[k] = v2;
			t1[k] = 0;
		}
		if(v1) {
			sum[k] += (r - l + 1) * v1; t1[k] += v1, mx[k] += v1;
		}
	}
	void pushdown(int k, int l, int r) {
		if(t1[k] || t2[k]) {
			pushr(ls, l, mid, t1[k], t2[k]);
			pushr(rs, mid+1, r, t1[k], t2[k]);
			t1[k] = t2[k] = 0;
		}
	}
	inline void cover(int k, int l, int r, int ql, int qr, int val) {
//		cerr << "?";
//		cerr << k << endl;
		if(l == ql && r == qr) return pushr(k, l, r, 0, val);
		pushdown(k, l, r);
		if(qr <= mid) cover(ls, l, mid, ql, qr, val);
		else if(mid < ql) cover(rs, mid+1, r, ql, qr, val);
		else cover(ls, l, mid, ql, mid, val), cover(rs, mid+1, r, mid+1, qr, val);
		mx[k] = max(mx[ls], mx[rs]); sum[k] = sum[ls] + sum[rs];
	}
	inline void add(int k, int l, int r, int ql, int qr, int val) {
//		cerr << "?";
		if(l == ql && r == qr) return pushr(k, l, r, val, 0);
		pushdown(k, l, r);
		if(qr <= mid) add(ls, l, mid, ql, qr, val);
		else if(mid < ql) add(rs, mid+1, r, ql, qr, val);
		else add(ls, l, mid, ql, mid, val), add(rs, mid+1, r, mid+1, qr, val);
		mx[k] = max(mx[ls], mx[rs]); sum[k] = sum[ls] + sum[rs];
	}
	int querypos(int k, int l, int r, int v) {
//		cerr << "?";
		if(l == r) return l;
		pushdown(k, l, r);
		if(mx[rs] >= v) return querypos(rs, mid+1, r, v);
		else return querypos(ls, l, mid, v);
	}
}tr;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
	cin >> n;
	For(i, 1, n) scanf("%1lld", &a[i]);
	int lst = 0, ans = 0;
	For(i, 1, n) {
		if(a[i] == 1) {
			if(!lst) lst = i;
//			cerr << lst << endl;
			int it = tr.querypos(1, 1, n, i - lst + 1);
			tr.add(1, 1, n, lst, i, 1);
//			cerr << lst << ' ' << it << endl;
			if(it < lst) tr.cover(1, 1, n, it, lst - 1, i - lst + 1);
		} else {
			lst = 0;
		}
//		cerr << tr.sum[1] << endl;
		ans += tr.sum[1];
	}
	cout << ans << endl;
    return FastIO::Fflush(), 0;
}
/*

*/