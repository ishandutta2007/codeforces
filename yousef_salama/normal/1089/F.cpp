#include <bits/stdc++.h>
using namespace std;

long long modpow(long long x, long long p, long long mod){
	if(p == 0)return 1;
	if(p % 2 == 1)return x * modpow(x, p - 1, mod) % mod;

	long long r = modpow(x, p / 2, mod);
	return r * r % mod;
}
int phi(int x){
	int ret = x;
	for(int d = 2; d * d <= x; d++)if(x % d == 0){
		ret -= ret / d;
		while(x % d == 0)x /= d;
	}
	if(x > 1){
		ret -= ret / x;
	}
	return ret;
}
long long modinv(long long x, long long mod){
	return modpow(x, phi(mod) - 1, mod);
}

int main(){
	int n;
	scanf("%d", &n);
	
	int p = -1, q = -1;
	for(int d = 2; d * d <= n; d++)if(n % d == 0){
		p = d;
		while((n / p) % d == 0)p *= d;
		
		if(p == n){
			p = -1;
			q = -1;
		}else{
			q = n / p;
		}
	
		break;
	}
	
	if(p == -1){
		printf("NO\n");
		return 0;
	}
	
	
	long long a = modinv(p, q) * (q - 1) % q;
	long long b = modinv(q, p) * (p - 1) % p;
	
	printf("YES\n");
	printf("2\n");
	printf("%lld %d\n", a, n / p);
	printf("%lld %d\n", b, n / q);
	
	return 0;
}