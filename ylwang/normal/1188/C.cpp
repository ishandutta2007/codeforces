#pragma GCC optimize(3)
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
#define MOD 998244353
#define MAXN 1005
int n, k, a[MAXN];
int dp[MAXN][MAXN];
int sum[MAXN][MAXN]; //dp
inline int solve(int v) {
    dp[0][0] = 1, sum[0][0] = 1;
    int pos = 0;
    for(int i = 1; i <= n; i++) {
        while(a[i] - a[pos] >= v) pos++;
        for(int j = 0; j <= k; j++) {
//			for(int r = 0; r < i; r++) {
                if(j)  dp[i][j] = sum[pos-1][j-1];
                sum[i][j] = (sum[i-1][j] + dp[i][j]) % MOD;
//			}
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = (ans + dp[i][k]) % MOD;
    return ans;
}
signed main()
{
    n = read(), k = read();
    for(int i = 1; i <= n; i++)
    	a[i] = read();
    a[0] = -1000000000ll;
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for(int x = 1; x * (k - 1) <= a[n]; x++)
        ans = (ans + solve(x)) % MOD;
    cout << ans << endl;
    return 0;
}