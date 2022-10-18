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
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector <int> d(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	sort(d.begin(), d.end());
	
	vector <long long> sum(n + 1, 0);
	for(int i = 1; i <= n; i++)
		sum[i] = (sum[i - 1] + d[i - 1]) % MOD;
	
	while(m--){
		int a, b;
		scanf("%d %d", &a, &b);
		
		int x = lower_bound(d.begin(), d.end(), b) - d.begin();
		
		if(n - x < a){
			printf("0\n");
			continue;
		}
		
		long long p = 1LL * (n - x - a) * modinv(n - x) % MOD;
		long long q = 1LL * (n - x + 1 - a) * modinv(n - x + 1) % MOD;
		
		long long total = (p * (sum[n] - sum[x] + MOD) + q * sum[x]) % MOD;
		printf("%lld\n", total);
	}
	
	return 0;
}