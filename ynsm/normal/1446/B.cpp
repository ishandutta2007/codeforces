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
 
int n, m, dp[5050][5050], ans;
char s[N], t[N];
void f(int &a, int b){
	if(a < b)
		a = b;
}
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			f(dp[i][j], dp[i][j - 1] - 1);
			f(dp[i][j], dp[i - 1][j] - 1);
			f(dp[i][j], dp[i - 1][j - 1] + (s[i] == t[j]) * 4 - 2);
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans);
}