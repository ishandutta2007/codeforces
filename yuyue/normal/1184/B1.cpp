#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
		#define eprintf(...) fprintf(stderr, _VA_ARGS_)
#else
		#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , int> pli;
typedef pair<ll , ll> pll;
typedef long double ld;
typedef vector< int > vi;
typedef unsigned long long ull;
#define mp make_pair
#define fi first
#define se second
const int MAXP = 1e7 + 10;
const int N = 1e5 + 10;

int n , m , rt , sz;
int a[N] , d[N] , g[N] , lc[MAXP] , rc[MAXP];
ll sum[MAXP];

template <typename T> inline void chkmax(T &x,T y) { x = max(x,y); }
template <typename T> inline void chkmin(T &x,T y) { x = min(x,y); }
template <typename T> inline void read(T &x) {
    T f = 1; x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}
inline void upd(int now) { sum[now] = sum[lc[now]] + sum[rc[now]]; }
inline void modify(int &now , int l , int r , int x , int val) {
		if (!now) now = ++sz;
		if (l == r) {
				sum[now] += (ll)val; 
				return;
		}
		int mid = (l + r) >> 1;
		if (mid >= x) modify(lc[now] , l , mid , x , val);
		else modify(rc[now] , mid + 1 , r , x , val);
		upd(now);
}
inline ll query(int now , int l , int r , int ql , int qr) {
		if (!now) return 0;
		if (l == ql && r == qr)
				return sum[now];
		int mid = (l + r) >> 1;
		if (mid >= qr) return query(lc[now] , l , mid , ql , qr);
		else if (mid + 1 <= ql) return query(rc[now] , mid + 1 , r , ql , qr);
		else return query(lc[now] , l , mid , ql , mid) + query(rc[now] , mid + 1 , r , mid + 1 , qr);
}

int main() {
		
		read(n); read(m);
		for (int i = 1; i <= n; ++i) read(a[i]);
		for (int i = 1; i <= m; ++i) {
				read(d[i]); read(g[i]);
				modify(rt , 1 , (int)1e9 , d[i] , g[i]);
		}
		for (int i = 1; i <= n; ++i) {
				if (i ^ n) printf("%I64d " , query(rt , 1 , (int)1e9 , 1 , a[i]));
				else printf("%I64d\n" , query(rt , 1 , (int)1e9 , 1 , a[i]));		
		}
		
		return 0;
	
}