//Solution by Tima
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    

const int N = 100, mod = int(1e9)  + 7; 

ll n, k, ans, pw[N], dp[N];
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
ll get(ll cnt, ll p){
	pw[0] = 1;
	for(int i = 1; i <= cnt; i++)
		pw[i] = pw[i - 1] * p % mod;
	
	for(int i = 0; i < cnt; i++)
		dp[i] = 0;
	dp[cnt] = 1;
	for(int i = 0; i < k; i++){
		ll cur = 0;
		for(int j = cnt; j >= 0; j--){
			cur = (cur + dp[j] * inv(j + 1)) % mod;
			dp[j] = cur;
		}
	}   	
	ll res = 0;
	for(int i = 0; i <= cnt; i++)
		res = (res + pw[i] * dp[i]) % mod;
	return res;
}
int main () {
	ans = 1;
	cin >> n >> k;
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0){
			ll p = i, cnt = 0;
			while(n % p == 0)
				n /= p, cnt++;
			ans = ans * get(cnt, p) % mod;
		}	
	if(n > 1)
		ans = ans * get(1, n) % mod;
	cout << ans;
}