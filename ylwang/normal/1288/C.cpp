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
const int MOD = 1000000007; //
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
const int MAXN = 1005, MAXM = 15;
int n, m, dp[MAXN][MAXM][MAXN];
signed main()
{
	cin >> n >> m;
	// a_1 <= b_1, a_i >= a[i+1], b_i <= b[i+1]
	For(i, 1, n) {
		dp[i][1][i] = 1;
		For(j, 1, m) {
			if(j != 1) 
				For(k, i, n)
					dp[i][j][k] = dp[i][j-1][k];
			For(k, i, n)
				addmod(dp[i][j][k], dp[i][j][k-1]);
		}
	}
	long long ans = 0;
	For(i, 1, n) {
		For(j, i, n) {
			ll v1 = dp[n-i+1][m][n], v2 = dp[j][m][n]; 
			ans = (ans + 1ll * v1 * v2) % MOD;
		}
	}
	cout << ans << endl;
    return 0;
}