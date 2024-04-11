#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

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
	int n;
	scanf("%d", &n);
	
	vector <int> a(2 * n);
	for(int i = 0; i < 2 * n; i++)scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	
	long long sum = 0;
	for(int i = 0; i < n; i++)sum = (sum - a[i] + MOD) % MOD;
	for(int i = n; i < 2 * n; i++)sum = (sum + a[i]) % MOD;
	
	long long p = 1;
	for(int i = 0; i < n; i++)p = p * (2 * n - i) % MOD;
	
	long long b = 1;
	for(int i = 0; i < n; i++)b = b * (i + 1) % MOD;
	
	printf("%lld\n", p * modinv(b) % MOD * sum % MOD);
	
	
	return 0;
}