#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MOD = 1000000007;

int N;
long long a[MAXN], b[MAXN], fact[MAXN], invfact[MAXN];
long long modpower(long long x, int p){
	if(p == 0)return 1;
	else if(p % 2 == 1)return (x * modpower(x, p - 1)) % MOD;
	else{
		long long r = modpower(x, p / 2);
		return (r * r) % MOD;
	}
}
long long C(int x, int y){
	long long r = 1;
	r = (r * fact[x]) % MOD;
	r = (r * invfact[y]) % MOD;
	r = (r * invfact[x - y]) % MOD;
	return r;
}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%I64d", &a[i]);

	for(int i = 0; i <= N; i++){
		if(i == 0)fact[i] = 1;
		else fact[i] = (i * fact[i - 1]) % MOD;
	}
	for(int i = 0; i <= N; i++)
		invfact[i] = modpower(fact[i], MOD - 2);

	int k = 1;
	while((N > 1) && (N % 4 != 1)){
		for(int i = 0; i < N - 1; i++){
			b[i] = (a[i] + k * a[i + 1] + MOD) % MOD;
			k *= -1;
		}
		for(int i = 0; i < N; i++)
			a[i] = b[i];
		N--;
	}


	long long r = 0;
	for(int i = 0; i < N; i += 2)
		r = (r + a[i] * C(N / 4 * 2, i / 2)) % MOD;
	printf("%I64d\n", r);

	return 0;
}