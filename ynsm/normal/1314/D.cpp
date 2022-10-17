#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, k, a[80][80], dp[80][20], par[80], ans = inf;
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	int m = 40000;
	while(m--){
		for(int i = 0; i < n; i++)
			par[i] = rand() & 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j <= k; j++)
				dp[i][j] = inf;
		dp[0][0] = 0;
		for(int j = 0; j < k; j++)
			for(int i = 0; i < n; i++)
				for(int q = 0; q < n; q++)
					if(par[i] != par[q])
						dp[q][j + 1] = min(dp[q][j + 1], dp[i][j] + a[i][q]);
	    ans = min(ans, dp[0][k]);
	}
	printf("%d", ans);
}