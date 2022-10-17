#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
#define int long long
using namespace std;
inline int read()
{
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
int n;
#define MAXN 200005
int a[MAXN], b[MAXN];
int dp[MAXN][5];
int M(int a, int b, int c, int d) {
	return max(max(a, b), max(c, d));	
}
signed main()
{
	int n = read();
	For(i, 1, n)
		a[i] = read();
	For(i, 1, n) b[i] = read();
	memset(dp, 0, sizeof(dp));
	For(i, 1, n) {
		dp[i][0] = M(dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3]);
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + b[i];
//		dp[i][3] = 
	}
	cout << M(dp[n][0], dp[n][1], dp[n][2], dp[n][3]);
	return 0;
}