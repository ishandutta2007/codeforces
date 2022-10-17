#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


const int mod = 998244353;

int n, m, a[550];
ll dp[550][550];
bool was[550][550];
void solve(int l, int r){
	if(was[l][r])
		return;
	was[l][r] = 1;
	if(l >= r){
		dp[l][r] = 1;
		return;
	}
	int p = l;
	for(int i = l; i <= r; i++)
		if(a[i] < a[p])
			p = i;
	ll a = 0, b = 0;
	for(int i = l; i <= p; i++){                   
		solve(l, i - 1);
		solve(i, p - 1);
		a = (a + dp[l][i - 1] * dp[i][p - 1]) % mod;	
	}
    for(int i = p; i <= r; i++){
		solve(p + 1, i);
		solve(i + 1, r);
		b = (b + dp[p + 1][i] * dp[i + 1][r]) % mod;
	}
	dp[l][r] = a * b % mod;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	solve(1, n);
	cout << dp[1][n];
	return 0;
}