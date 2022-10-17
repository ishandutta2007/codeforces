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
 
int n, p, k, x, y, dp[N];
char s[N];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &p, &k);
		scanf("%s", &s);
		scanf("%d%d", &x, &y);
		for(int i = n - 1; i >= 0; i--){
			if(i + k < n)
				dp[i] = dp[i + k];
			else
				dp[i] = 0;
			if(s[i] == '0')
				dp[i]++;
		}
		int ans = inf;
		p--;
		for(int i = 0; i < n; i++)
			if(i + p < n)
            	ans = min(ans, dp[i + p] * x + i * y);
		printf("%d\n", ans);			
	}
}