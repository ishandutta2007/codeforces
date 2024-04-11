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
 
int n, m, dp[N], mx[N], ans, t[N], a[N], b[N];
int main(){
	scanf("%d%d", &n, &m);
	int cur = 0;
	
	t[0] = 0;
	a[0] = 1;
	b[0] = 1;
	dp[0] = 0;

	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &t[i], &a[i], &b[i]);
		
		
		if(i - 1111 > 0)
			dp[i] = mx[i - 1111] + 1;
		else
			dp[i] = -inf;
					
		for(int q = max(0, i - 1111); q < i; q++)
			if(abs(a[i] - a[q]) + abs(b[i] - b[q]) <= t[i] - t[q])
				dp[i] = max(dp[i], dp[q] + 1);		
	
		ans = max(ans, dp[i]);
		mx[i] = max(dp[i], mx[i - 1]);
	}
	printf("%d", ans);
}