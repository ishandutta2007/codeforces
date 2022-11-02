#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int a[N], n;

int dp[N][N];
const int Mod = 998244353;
typedef long long ll;
ll cnt[N], fact[N];
void add(int &a, ll b) {
	a = (a + b) % Mod;
}

ll mod_pow(ll x, ll n) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) res = res * x % Mod;
		x = x * x % Mod;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % Mod;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		cnt[a[i]]++;
	}
	for (int j = 0; j <= n; j++)
		dp[0][j] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= n; j++) {
		add(dp[i][j], dp[i-1][j-1] * cnt[j]);
		if (cnt[j] >= 2) 
			add(ans, dp[i][j]*(cnt[j]-1)%Mod*fact[n-i-1]);				
		add(dp[i][j], dp[i][j-1]);		
	}
	//printf("%d\n", ans);	
	ans = ans * mod_pow(fact[n], Mod - 2) % Mod;
	printf("%d\n", ans);
	
	
}