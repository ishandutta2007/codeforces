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
 
int n, a[N], dp[N];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n + n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i <= n; i++)
		dp[i] = 0;
	dp[0] = 1;
	int k = n + n;
	while(k){
		int p = 0;
		for(int i = 0; i < k; i++)
			if(a[i] > a[p])
				p = i;
		for(int i = n; i >= 0; i--)
			dp[i + k - p] |= dp[i];
		k = p;
	}
	if(dp[n])       
		puts("YES");
	else
		puts("NO");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}