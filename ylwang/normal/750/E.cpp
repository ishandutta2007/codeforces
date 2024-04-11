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
const int MOD = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= MOD ? t - MOD : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}return ans;}
inline int inv(int a) {return ksm(a, MOD-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 200005;
struct Matrix {
	int num[5][5], n;
	Matrix (int op = 0) {
		n = 5;
		memset(num, 0x3f, sizeof(num));
		if(op == 1) For(i, 0, n-1) num[i][i] = 0; 
	}
	
	Matrix operator * (const Matrix b) {
		Matrix ans;
		For(i, 0, n-1) For(j, 0, n-1) For(k, 0, n-1)
			ckmin(ans[i][j], num[i][k] + b.num[k][j]);
		return ans;
	}
	int *operator [] (int n) {return num[n];}
};
Matrix get(int x) {
	Matrix t(1);
	if(x == 2) t[0][0] = 1,t[1][0] = 0;
	if(x == 0) t[1][1] = 1,t[2][1] = 0;
	if(x == 1) t[2][2] = 1,t[3][2] = 0;
	if(x == 7) t[3][3] = 1,t[4][3] = 0;
	if(x == 6) t[4][4] = 1,t[3][3] = 1;
	return t;
}
int a[MAXN], n;
struct Segment_tree {
	Matrix sum[MAXN<<2];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void pushup(int k) {
		sum[k] = sum[rs] * sum[ls];
	}
	void build(int k, int l, int r) {
		if(l == r)  sum[k] = get(a[l]);
		else {
			build(ls, l, mid); build(rs, mid+1, r);
			pushup(k); 
		}
	}
	Matrix query(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return sum[k];;
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(mid < ql) return query(rs, mid+1, r, ql, qr);
		else return query(rs, mid+1, r, mid+1, qr) * query(ls, l, mid, ql, mid);
	}
}tr;
signed main()
{
	int Qnum;
	n = read(), Qnum = read();
	For(i, 1, n) scanf("%1d", &a[i]);
	tr.build(1, 1, n);
	while(Qnum--) {
		int l = read(), r = read();
		Matrix ans = tr.query(1, 1, n, l, r);
		printf("%d\n", ans[4][0] > (r - l + 1) ? -1 : ans[4][0]);
	}
	
    return 0;
}