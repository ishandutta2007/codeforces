#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define int long long 
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 1005
int n, k;
string s;

int dp[MAXN][MAXN]; //  
int lst[MAXN], lstpos[MAXN];
signed main()
{
	cin >> n >> k;
	cin >> s; s = ' ' + s;
	memset(lst, -1, sizeof(lst));
	memset(lstpos, -1, sizeof(lstpos));
	for(int i = 1; i <= n; i++) {
		lst[i] = lstpos[s[i]-'a'+1];
		lstpos[s[i]-'a'+1] = i;
	}
	dp[0][0] = 1;
	For(i, 1, n) {
		For(j, 0, i) {
			if(j == 0) dp[i][j] = 1;
			else {
				if(lst[i] == -1) {
					dp[i][j] = dp[i-1][j] + max(dp[i-1][j-1], 1ll);
				} else {
					dp[i][j] = dp[i-1][j] + dp[i-1][j-1] - dp[lst[i]-1][j-1];
				}
			}
			
		}
	}
	int ans = 0;
	for(int i = n; i >= 0; i--) {
		if(k >= dp[n][i]) {
			ans += dp[n][i] * (n-i);
			k -= dp[n][i];
		} else {
			ans += k * (n-i);
			k = -1;
			break;
		}
	}
	if(k > 0) cout <<-1 << endl;
	else cout << ans << endl;
    return 0;
}