#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define reaD() read()
using namespace std;
#define int long long //
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 1000005 //
 
int n, a[MAXN], maxi[MAXN << 2], lzy[MAXN << 2];
#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
inline void pushdown(int k) {
	maxi[ls] = max(maxi[ls], lzy[k]);
	maxi[rs] = max(maxi[rs], lzy[k]);
	lzy[ls] = max(lzy[ls], lzy[k]);
	lzy[rs] = max(lzy[rs], lzy[k]);
	lzy[k] = 0;
} 
inline void update(int k, int l, int r, int pos, int val) {
	if(l == pos && l == r) {maxi[k] = val; return;}
	pushdown(k);
	if(pos <= mid) update(ls, l, mid, pos, val);
	else update(rs, mid+1, r, pos, val);
	maxi[k] = max(maxi[ls], maxi[rs]);
}
inline void print(int k, int l, int r) {
	if(l == r) {printf("%d ", maxi[k]);return;}
	pushdown(k);
	print(ls, l, mid);
	print(rs, mid+1, r);
}
signed main() 
{
	
	n = read();
	For(i, 1, n) {
		a[i] = read();
		update(1, 1, n, i, a[i]);
	}
	int Qnum = reaD();
	while(Qnum--) {
		int opt = read();
		if(opt == 1) {
			int p = read(), x = read();
			update(1, 1, n, p, x);
		} else {
			int x = read();
			maxi[1] = max(maxi[1], x);
			lzy[1] = max(lzy[1], x);
		}
	} 
	print(1, 1, n);
    return 0;
}