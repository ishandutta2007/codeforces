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
const int MAXN = 2005;
int n, m;
int dp[MAXN][4][MAXN]; // dp[i][j][k][w] : i, stage:j, k components

signed main()
{
	cin >> n >> m;
	dp[1][0][1] = 1, dp[1][1][2] = 1;
	dp[1][2][2] = 1, dp[1][3][1] = 1;
	For(i, 2, n) {
		For(j, 0, 3) {
			For(k, 1, 2*i) {
				if(j == 0 || j == 3) {
					addmod(dp[i][j][k], dp[i-1][0][k-(j==3)]);
					addmod(dp[i][j][k], dp[i-1][1][k]);
					addmod(dp[i][j][k], dp[i-1][2][k]);
					addmod(dp[i][j][k], dp[i-1][3][k-(j==0)]);
				}
				if(j == 1) {
					addmod(dp[i][j][k], dp[i-1][0][k-1]);
					addmod(dp[i][j][k], dp[i-1][1][k]);
					if(k>=2) addmod(dp[i][j][k], dp[i-1][2][k-2]);
					addmod(dp[i][j][k], dp[i-1][3][k-1]);
				}
				if(j == 2) {
					addmod(dp[i][j][k], dp[i-1][0][k-1]);
					if(k>=2) addmod(dp[i][j][k], dp[i-1][1][k-2]);
					addmod(dp[i][j][k], dp[i-1][2][k]);
					addmod(dp[i][j][k], dp[i-1][3][k-1]);
				}
			}
		}
	}
//	For(i, 1, n) {
//		For(j, 0, 3) {
//			For(k, 1, 2*i) {
//				fprintf(stderr, "dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
//			}
//		}
//	}
	int ans = 0;
	For(i, 0, 3) addmod(ans, dp[n][i][m]);
	cout << ans % MOD << endl;
    return 0;
}