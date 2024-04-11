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
#define FOr(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin);freopen(s".out", "w", stdout)
#define INF ((1 << 30) - 1)
#define dprintf(x) fprintf(stderr, "%d ", x)
#define dprintfln(x) fprintf(stderr, "%d\n", x)
#define dln fprintf(stderr, "\n")
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
const int MAXN = 5e5 + 5;
int n, m, q;
//int Hash(int x, int y) {
//	x = (x + 1) / 2, y = (y + 1) / 2;
//	return m * (x - 1) + y;
//}
//Pair Anti_hash(int k) {
//	int x = k / m + 1, y = k % m;
//	return mkp(x, y);
//}
//struct Query {
//	int x, y, id;
//}q1[MAXN], q2[MAXN];
//int n1, n2, ans[MAXN];
//int res[MAXN];
struct Segment_tree {
	int a[MAXN<<2], mx[MAXN<<2];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void pushdown(int k) {
		if(mx[k]) {
			ckmax(a[ls], mx[k]); ckmax(a[rs], mx[k]);
			ckmax(mx[ls], mx[k]); ckmax(mx[rs], mx[k]);
		}
		mx[k] = 0;
	}
	void update(int k, int l, int r, int ql, int qr, int v) {
		if(l == ql && r == qr) return ckmax(a[k], v), ckmax(mx[k], v);
		pushdown(k);
		if(qr <= mid) update(ls, l, mid, ql, qr, v);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, v);
		else {
			update(ls, l, mid, ql, mid, v); update(rs, mid+1, r, mid+1, qr, v);
		}
		a[k] = max(a[ls], a[rs]);
	}
	int query(int k, int l, int r, int pos) {
		if(l == r) return a[k]; pushdown(k); 
		return pos <= mid ? query(ls, l, mid, pos) : query(rs, mid+1, r, pos);
	}
}tr[2]; 
signed main()
{
	cin >> n >> m >> q;
	int res = 1;
	For(i, 1, q) {
		int x = read(), y = read(), st = 0;
		if(x % 2 != 0) st = 1; 
		x = (x + 1) / 2, y = (y + 1) / 2;
		if(st == 0) {
//			cout << "0*" << x << ' ' << y << endl;
//			cout << endl << tr[1].query(1, 1, n, x) << endl;
			if(m - tr[1].query(1, 1, n, x) + 1 <= y) res = 0;
			tr[0].update(1, 1, n, 1, x, y);
		} else {
//			cout << "1*" << x << ' ' << y << endl;
			if(tr[0].query(1, 1, n, x) >= y) res = 0;
			tr[1].update(1, 1, n, x, n, m - y + 1);
			 
		}
//		s = Hash(x, y);
//		int t = Hash(x + 1, y);
		
		printf(res == 1 ? "YES\n" : "NO\n");
	}
    return 0;
}
/*
5 5 5
7 5
2 10
8 6
2 10
9 7

*/