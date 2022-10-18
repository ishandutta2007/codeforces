#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXK = 5005;

long long modpow(long long a, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return a * modpow(a, p - 1) % MOD;
	
	long long r = modpow(a, p / 2);
	return r * r % MOD;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}

int n, m, k;

long long C[MAXK][MAXK], dp[MAXK];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 0; i <= k; i++)
	for(int j = 0; j <= k; j++){
		if(j == 0)C[i][j] = 1;
		else if(i == 0)C[i][j] = 0;
		else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
	
	for(int i = 1; i <= k; i++){
		dp[i] = modpow(i, k);
		for(int j = 1; j < i; j++)
			dp[i] = (dp[i] + (MOD - dp[j]) * C[i][j]) % MOD;
	}
	
	long long res = 0, c = 1;
	for(int i = 1; i <= min(n, k); i++){
		c = c * (n - i + 1) % MOD;
		c = c * modinv(i) % MOD;
		
		long long cnt = c * dp[i] % MOD;
		res = (res + cnt * modpow(m, 1LL * (MOD - 2) * i % (MOD - 1))) % MOD;
	}
	
	printf("%lld\n", res);
	
	return 0;
}