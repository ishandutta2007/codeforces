#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long modpow(long long x, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;
	
	long long r = modpow(x, p / 2);
	return r * r % MOD;
}
long long modinv(long long x){
	return modpow(x, MOD - 2);
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	vector <long long> fact(n + 1), invfact(n + 1);
	
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
		fact[i] = i * fact[i - 1] % MOD;
	
	invfact[n] = modinv(fact[n]);
	for(int i = n - 1; i >= 0; i--)
		invfact[i] = invfact[i + 1] * (i + 1) % MOD;
		
	auto C = [&](int i, int j) -> long long{
				if(j > i)return 0;
				return (fact[i] * invfact[j] % MOD * invfact[i - j] % MOD);
			};
		
	vector < pair <int, int> > evs;
	for(int i = 0; i < n; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		
		evs.push_back({l, 1});
		evs.push_back({r + 1, -1});
	}
	sort(evs.begin(), evs.end());
	
	long long res = 0;
	int c = 0;
	
	for(int i = 0; i < (int)evs.size(); ){
		int j = i, d = 0;
		while(j < (int)evs.size() && evs[j].first == evs[i].first){
			c += evs[j].second;
			if(evs[j].second == 1)d++;
			j++;
		}
		
		res = (res + C(c, k) - C(c - d, k) + MOD) % MOD;
		
		i = j;
	}
	printf("%lld\n", res);
	
	return 0;
}