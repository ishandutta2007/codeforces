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
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}return ans;}
inline int inv(int a) {return ksm(a, MOD-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = (1 << 20) | 1;
inline void FWT(int *a, int n, int op) {
	for(int k = 1; k < n; k <<= 1)
		for(int i = 0; i < n; i += (k<<1))
			for(int j = 0; j < k; j++) {
				a[i+j] += a[i+j+k], a[i+j+k] = a[i+j] - a[i+j+k] - a[i+j+k];
				a[i+j] /= op, a[i+j+k] /= op;
			}
}
int n, m, a[MAXN], b[MAXN], mp[21][MAXN];
signed main()
{
	IOS;
	cin >> n >> m;
	For(i, 1, n) {
		string s; cin >> s;
		For(j, 1, m)
			mp[i][j] = (s[j-1] == '1');
	} 
	For(i, 1, m) {
		int st = 0;
		For(j, 1, n)
			st = (st << 1) | mp[j][i];
		a[st]++;
	}
	For(st, 0, (1<<n)-1) {
		b[st] = min(1ll*__builtin_popcount(st), n-__builtin_popcount(st));
	}
	FWT(a, (1<<n), 1); FWT(b, (1<<n), 1);
	For(i, 0, (1<<n)-1) a[i] *= b[i];
	FWT(a, (1<<n), 2);
	int ans = n * m;
	For(i, 0, (1<<n)-1) {
		ckmin(ans, a[i]);
	}
	cout << ans <<endl;
    return 0;
}