#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define int long long
#define MOD 1000000007
#define MAXN 500005
int a[MAXN], l, r, n;
int dp[MAXN][3];
int num[3];
signed main()
{
	n = read(), l = read(), r = read();
	num[0] = r / 3 - (l - 1) / 3;
    num[1] = (r + 2) / 3 - (l + 1) / 3;
    num[2] = (r + 1) / 3 - l / 3;
    dp[0][0] = 1;
    For(i, 1, n) {
    	dp[i][0] = (dp[i-1][0] * num[0] + dp[i-1][1] * num[2] + dp[i-1][2] * num[1]) % MOD;
    	dp[i][1] = (dp[i-1][0] * num[1] + dp[i-1][1] * num[0] + dp[i-1][2] * num[2]) % MOD;
    	dp[i][2] = (dp[i-1][0] * num[2] + dp[i-1][1] * num[1] + dp[i-1][2] * num[0]) % MOD;
	}
	cout << dp[n][0] << endl;
    return 0;
}