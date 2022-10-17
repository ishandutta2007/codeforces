#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

int n, q, a[N];
ll ans, pre[N], prod[N];
set< int > st;
ll binpow(ll x, ll p){
	ll res = 1;
	while(p){
		if(p & 1)
			res = res * x % mod;
		p >>= 1;
		x = x * x % mod;	
	}
	return res;
}
ll inv(ll x){
	return binpow(x, mod - 2);
}
void add(int x, int k){
	int y = *st.upper_bound(x) - 1;
	ll res = 0;
	if(x == 1)
		res = pre[y - 1];
	else
		res = (pre[y - 1] - pre[x - 2] + mod) % mod;
	res = res * inv(prod[y]); 
	if(k == 1)
		ans = (ans + res) % mod;
	else
		ans = (ans + mod - res) % mod;
}
int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	pre[0] = 1;
	prod[0] = 1;
	for(int i = 1; i <= n; i++){
		a[i] = a[i] * inv(100) % mod;
		pre[i] = (pre[i - 1] + prod[i - 1] * a[i]) % mod;
		prod[i] = prod[i - 1] * a[i] % mod;
	}
	st.insert(1);
	st.insert(n + 1);
	add(1, 1);
	while(q--){
		int x;
		scanf("%d", &x);
		if(st.find(x) == st.end()){
			auto it = st.lower_bound(x);
			it--;
			add(*it, -1);
			st.insert(x);
			add(x, 1);
			add(*it, 1);
		}else{
			auto it = st.lower_bound(x);
			it--;
			add(*it, -1);
			add(x, -1);
			st.erase(x);
			add(*it, 1);
		}
		printf("%lld\n", ans);
	}	                   
	return 0;
}