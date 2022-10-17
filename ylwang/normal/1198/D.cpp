#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
} 
#define MAXN 55 //
int n, a[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];
int sum[MAXN][MAXN];
inline bool notept(int x, int y, int r, int c) {
	return sum[r][c]- sum[r][y-1] - sum[x-1][c] + sum[x-1][y-1];
}
signed main()
{
	n = reaD();
	memset(dp, 127, sizeof(dp)); 
	For(i, 1, n) {
		string s; cin >> s;
		For(j, 1, n)
			a[i][j] = (s[j-1] == '#'), dp[i][j][i][j] = a[i][j];
	}
	For(i, 1, n)
		For(j, 1, n)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
	For(l1, 1, n) {
		For(l2, 1, n) {
			For(x, 1, n-l1+1) {
				For(y, 1 ,n-l2+1) {
					int r = x + l1 - 1, c = y + l2 - 1;
					if(notept(x, y, r, c)) {
						dp[x][y][r][c] = max(l1, l2);
						For(i, x, r-1) dp[x][y][r][c] = min(dp[x][y][i][c] + dp[i+1][y][r][c], dp[x][y][r][c]);
						For(i, y, c-1) dp[x][y][r][c] = min(dp[x][y][r][i] + dp[x][i+1][r][c], dp[x][y][r][c]);
					} else dp[x][y][r][c] = 0;
				}
			}
		}
	}
	cout << dp[1][1][n][n] << endl;
    return 0;
}