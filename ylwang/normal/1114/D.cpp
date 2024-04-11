#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 5005
int a[MAXN], c[MAXN], dp[MAXN][MAXN], n = 0, m;
signed main()
{
    m = read();
    For(i, 1, m) c[i] = read();
    For(i, 1, m) if(c[i] != c[i-1]) a[++n] = c[i];
    memset(dp, 127/2, sizeof(dp));
    For(i, 1, n) dp[i][i] = 0;
    For(i, 1, n-1) dp[i][i+1] = (a[i] != a[i+1]);
    For(len, 3, n) {
    	For(i, 1, n) {
    		int j = i + len - 1; if(j > n) break;
    		if(a[i] == a[j]) dp[i][j] = dp[i+1][j-1] + 1;
    		else dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
		}
	}
	cout << dp[1][n] << endl;
    return 0;
}