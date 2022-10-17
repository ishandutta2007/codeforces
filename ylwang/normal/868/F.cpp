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
#define int long long
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
const int MAXN = 1e5 + 5;
const int MAXK = 25;
int f[MAXK][MAXN], n, k, a[MAXN]; 
int l = 1, r = 0, nowans, cur, cnt[MAXN];
void del(int x) {
	cnt[x]--, nowans -= cnt[x];	
}
void add(int x) {
	nowans += cnt[x], cnt[x]++;
}
int get(int ql, int qr) {
	while(r > qr) del(a[r--]);
	while(l > ql) add(a[--l]);
	while(r < qr) add(a[++r]);
	while(l < ql) del(a[l++]);
	return nowans;
}
void calc(int l, int r, int L, int R) {
	if(l > r) return;
	int p = 0, mid = (l + r) >> 1;
	for(int i = L; i <= min(R, mid - 1); i++) {
		int t = get(i+1, mid);
		if(f[cur-1][i] + t < f[cur][mid]) {
			f[cur][mid] = f[cur-1][i] + t, p = i;
		}
	} 
	calc(l, mid-1, L, p);
	calc(mid+1, r, p, R);
}
signed main()
{
	n = read(), k = read();
	mst(f, 127 / 2);
	For(i, 1, n)
		a[i] = read(), f[1][i] = get(1, i);
	For(i, 2, k) {
		cur = i;
		calc(1, n, 0, n-1);
	}
	cout << f[k][n] << endl;
    return 0;
}
/*

*/