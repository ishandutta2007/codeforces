#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define int long long
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
#define MOD 1000000007
int n, m; 
int dp[MAXN][4];
signed main()
{
	cin >> n >> m;
	if(n > m) swap(n, m);
	dp[1][0] = dp[1][1] = 1; 
	For(i, 2, m) {
		dp[i][0] = (dp[i-1][1] + dp[i-1][3]) % MOD;
		dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
		dp[i][2] = dp[i-1][0] % MOD;
		dp[i][3] = dp[i-1][1] % MOD;
	} 
	int ans = 0;
	For(i, 0, 3) {
		ans = (ans + dp[m][i]) % MOD;
		ans = (ans + dp[n][i]) % MOD;
	}
	cout << ((ans-2)+MOD)%MOD << endl;
    return 0;
}