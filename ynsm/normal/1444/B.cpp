#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)3e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
 
int n, a[N];
ll ans, cnt;
ll bp(ll x, ll p){
	ll res = 1;
	while(p){
		if(p & 1)
			res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}
ll inv(ll x){
	return bp(x, mod - 2);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n + n; i++)
		scanf("%d", &a[i]);	
	sort(a, a + n + n);
	for(int i = 0; i < n; i++)
		ans += a[i + n] - a[i];
	ans %= mod;
	ll C = 1;
	cnt = 1;
	for(int i = 1; i <= n; i++){
		C = C * (n - i + 1) % mod * inv(i) % mod;
		cnt = (cnt + C * C) % mod;	
	}
	ans = ans * cnt % mod;
	printf("%lld", ans);
}