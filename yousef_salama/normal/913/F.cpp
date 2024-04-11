#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
const int MOD = 998244353;

long long modpow(long long a, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return a * modpow(a, p - 1) % MOD;
	
	long long r = modpow(a, p / 2);
	return r * r % MOD;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}

int n, a, b;
long long p[MAXN][MAXN], sp[MAXN], dp[MAXN], dp2[MAXN];

int main(){
	scanf("%d %d %d", &n, &a, &b);
	long long prob = a * modinv(b) % MOD;
	
	for(int i = 0; i <= n; i++)
	for(int j = 0; j <= n; j++){
		if(j == 0){
			p[i][j] = 1;
		}else if(j > i){
			p[i][j] = 0;
		}else{
			p[i][j] = (p[i - 1][j - 1] * modpow(prob, i - j) + p[i - 1][j] * modpow(MOD + 1 - prob, j)) % MOD;
		}
	}
	
	for(int i = 0; i <= n; i++){
		if(i <= 1)sp[i] = 1;
		else{
			sp[i] = 0;
			for(int j = 1; j < i; j++){
				sp[i] = (sp[i] + p[i][j] * sp[j]) % MOD;
			}
			sp[i] = (MOD + 1 - sp[i]) % MOD;
		}
	}
	
	for(int i = 0; i <= n; i++){
		if(i <= 1){
			dp[i] = 0;
			dp2[i] = 0;
		}else{
			dp[i] = i * (i - 1) / 2;
			dp2[i] = 0;
			
			for(int j = 1; j < i; j++){
				dp[i] = (dp[i] + p[i][j] * sp[j] % MOD * (dp[j] + dp2[i - j])) % MOD;
				dp2[i] = (dp2[i] + p[i][j] * sp[j] % MOD * (dp[j] + dp2[i - j])) % MOD;
			}
			
			dp[i] = dp[i] * modinv(MOD + 1 - sp[i]) % MOD;
			dp2[i] = (dp2[i] + sp[i] * dp[i]) % MOD;
		}
	}
	
	printf("%lld\n", dp[n]);
	
	return 0;
}