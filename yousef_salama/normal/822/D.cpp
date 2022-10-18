#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 5000005;

int t, l, r;
long long f[MAXN];

int main(){
	scanf("%d %d %d", &t, &l, &r);

	for(int i = 1; i <= r; i++){
		if(i == 1)f[i] = 0;
		else f[i] = 1LL * i * (i - 1) / 2;
	}
	for(int i = 1; i <= r; i++){
		for(int j = 2; j * i <= r; j++){
			f[j * i] = min(f[j * i], 1LL * i * j * (j - 1) / 2 + f[i]);
		}
	}

	long long res = 0, c = 1;
	for(int i = l; i <= r; i++){
		res = (res + c * (f[i] % MOD)) % MOD;
		c = (c * t) % MOD;
	}
	printf("%I64d\n", res);


	return 0;
}