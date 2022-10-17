#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 500005
#define MOD 1000000007
int n, a[MAXN], k;
int dp[MAXN][5];
signed main()
{
	srand(time(0));
	n = read(), k = read();
	int ans = 0;
	For(i, 1, n) a[i] = read();
	For(i, 1, n) {//
		dp[i][0] = max(dp[i-1][0] + a[i], 0ll) ;
		dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + a[i] * k;
		dp[i][2] = max(dp[i-1][2], dp[i-1][1]) + a[i];
		ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
	}
	cout << ans << endl;
    return 0;
}
/*

*/