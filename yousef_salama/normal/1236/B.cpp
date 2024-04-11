#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long modpow(long long a, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return a * modpow(a, p - 1) % MOD;
	
	long long r = modpow(a, p / 2);
	return r * r % MOD;
}

int n, m;
int main(){
	scanf("%d %d", &n, &m);
	printf("%lld\n", modpow(modpow(2, m) - 1 + MOD, n));
	
	return 0;
}