#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar());
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
inline void print(ll x) {
	if(x > 9) print(x/10);
	putchar(x%10+'0');
}
#define MAXN 1000005
int n, m;
ll sum[MAXN<<2];
int maxi[MAXN<<2];
#define ls (k<<1)
#define rs (k<<1|1)
#define mid ((l+r)>>1)
inline void update1(int k, int l, int r, int pos, int val) {
	if(l == r) {sum[k] = maxi[k] = val; return;}
	pos <= mid ? update1(ls, l, mid, pos, val) : update1(rs, mid+1, r, pos, val);
	sum[k] = sum[ls] + sum[rs];
	maxi[k] = max(maxi[ls], maxi[rs]);
}
inline ll query(int k, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) {return sum[k];}
	if(mid >= qr) return query(ls, l, mid, ql, qr);
	else if(mid < ql) return query(rs, mid+1, r, ql, qr);
	else return query(ls, l, mid, ql, mid) + query(rs, mid+1, r, mid+1, qr);
}
inline void update2(int k, int l, int r, int ql, int qr, int val) {
	if(maxi[k] < val) return;
	if(l == r && ql == qr) {sum[k] %= val; maxi[k] %= val;return;}
	if(mid >= qr) update2(ls, l, mid, ql, qr, val);
	else if(mid < ql) update2(rs, mid+1, r, ql, qr, val);
	else {
		update2(ls, l, mid, ql, mid, val); 
		update2(rs, mid+1, r, mid+1, qr, val);
	}
	sum[k] = sum[ls] + sum[rs];
	maxi[k] = max(maxi[ls], maxi[rs]);
}
signed main()
{
    n = read(), m = read();
    For(i, 1, n) update1(1, 1, n, i, read());
    register int l, r, mod;
    while(m--) {
    	register int opt = read();
    	if(opt == 1) {
    		l = read(), r = read();
    		print(query(1, 1, n, l, r));
    		printf("\n");
		} else if(opt == 2) {
			l = read(), r = read(), mod = read();
			update2(1, 1, n, l, r, mod);
		} else {
			l = read(), r = read();
			update1(1, 1, n, l, r);
		}
	}
    return 0;
}