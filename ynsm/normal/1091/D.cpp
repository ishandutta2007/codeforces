#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
int n;
ll f[N], rf[N], ans;
ll binpow(ll x, ll p){
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
	return binpow(x, mod - 2);
}
ll C(int k, int n){
	return f[n] * rf[k] % mod * rf[n - k] % mod;
}
int main(){  
	f[0] = 1;
	for(int i = 1; i < N; i++)
		f[i] = f[i - 1] * i % mod;
	rf[N - 1] = inv(f[N - 1]);
	for(int i = N - 2; i >= 0; i--)
		rf[i] = rf[i + 1] * (i + 1) % mod;
	cin >> n;
	ans = 1;
	for(int k = 0; k < n; k++){
		ll cur = C(k, n) * f[k] % mod * (f[n - k] - 1 + mod) % mod;
		ans = (ans + cur) % mod;
	}
	cout << ans;
	return 0;
}