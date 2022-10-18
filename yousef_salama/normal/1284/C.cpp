#include <bits/stdc++.h>
using namespace std;

const int MAXN = 250005;

int n, m;
long long fact[MAXN];

int main(){	
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i <= n; i++){
		if(i == 0)fact[i] = 1;
		else fact[i] = i * fact[i - 1] % m;
	}
	
	long long res = 0;
	for(int len = 1; len <= n; len++){
		long long c = 1LL * (n - len + 1) * (n - len + 1) % m;
		long long d = fact[len] * fact[n - len] % m;
		
		res = (res + c * d) % m;
	}
	printf("%lld\n", res);
	
	return 0;
}