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
 
int n, ans, dp[N];
char s[N];
void g(){
	s[n] = s[0];
	for(int i = 0; i < n; i++)
		s[i] = s[i + 1];
}
int h(int l, int r, string t){
	int res = 0;
	for(int i = l; i < r; i++)
		res += (s[i] != t[i - l]);
	return res;
}
void f(){
	for(int i = 0; i <= n; i++)
		dp[i] = inf;
	dp[0] = 0;
	for(int i = 0; i < n; i++){                               
		if(i + 2 <= n)
			dp[i + 2] = min(dp[i + 2], dp[i] + h(i, i + 2, "RL"));
		if(i + 3 <= n)
			dp[i + 3] = min(dp[i + 3], dp[i] + h(i, i + 3, "RRL"));
		if(i + 3 <= n)
			dp[i + 3] = min(dp[i + 3], dp[i] + h(i, i + 3, "RLL"));
		if(i + 4 <= n)
			dp[i + 4] = min(dp[i + 4], dp[i] + h(i, i + 4, "RRLL")); 
	}
	ans = min(ans, dp[n]);
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%s", s);
		ans = inf;
		for(int i = 0; i < 10; i++){
			f();
			g();
		}
		printf("%d\n", ans);
	}
}