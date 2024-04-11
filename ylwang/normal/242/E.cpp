#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MOD = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= MOD ? t - MOD : t); }
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 100005, MAXW = 25;
int n, v[MAXW][MAXN];
struct Segment_tree {
	int n, val[MAXN << 2], tag[MAXN << 2];
	void Clear() {mst(val, 0); mst(tag, 0); n = 0;}
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void Build(int num, int k, int l, int r) {
		if(l == r) {val[k] = v[num][l], tag[k] = 0; return;}
		Build(num, ls, l, mid); Build(num, rs, mid+1, r);
		val[k] = val[ls] + val[rs];
	}
	void pushdown(int k, int l, int r) {
		if(tag[k]) {
			tag[k] = 0, tag[ls] ^= 1, tag[rs] ^= 1;
			val[ls] = (mid-l+1) - val[ls];
			val[rs] = (r - mid) - val[rs];
//			assert(val[ls] >= 0); assert(val[rs] >= 0);
		}
	} 
	int query(int k, int l, int r, int ql, int qr) {
//		cout << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
		if(l == ql && r == qr) return val[k];
		pushdown(k, l, r); assert(l <= r);
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(mid < ql) return query(rs, mid+1, r, ql, qr);
		else return query(ls, l, mid, ql, mid) + query(rs, mid+1, r, mid+1, qr);
	}
	int Query(int l, int r) {return query(1, 1, n, l, r);}
	void rev(int k, int l, int r, int rl, int rr) {
		if(l == rl && r == rr) {
			tag[k] ^= 1; val[k] = (r - l + 1) - val[k];
			return;
		}
		pushdown(k, l, r);
		if(rr <= mid) rev(ls, l, mid, rl, rr);
		else if(mid < rl) rev(rs, mid+1, r, rl, rr);
		else {rev(ls, l, mid, rl, mid); rev(rs, mid+1, r, mid+1, rr);}
		val[k] = val[ls] + val[rs];
	}
	void Reverse(int l, int r) {rev(1, 1, n, l, r);}
}tr[MAXW];
signed main()
{
	cin >> n;
	For(i, 1, n) {
		int x = read();
		for(int j = 0; (1 << j) <= x; j++)
			v[j][i] = (x >> j) & 1;
	}
	For(i, 0, 20) {
		tr[i].Clear(); tr[i].n = n; 
		tr[i].Build(i, 1, 1, n);
	}
	int Qnum = read();
	while(Qnum--) {
		int op = read(), l = read(), r = read();
		if(op == 1) {
			int ans = 0;
			For(i, 0, 20)
				ans += tr[i].Query(l, r) * (1ll << i);
			printf("%lld\n", ans);
		} else {
			int x = read();
			For(i, 0, 20)
				if((x >> i) & 1)
					tr[i].Reverse(l, r);
		}
	}
    return 0;
}