#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n, m, L, R;

long long modpow(long long a, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return a * modpow(a, p - 1) % MOD;
	
	long long r = modpow(a, p / 2);
	return r * r % MOD;
}

struct matrix{
	long long a[2][2];
	matrix(){
		a[0][0] = 1, a[0][1] = 0;
		a[1][0] = 0, a[1][1] = 1;
	}
};

matrix operator *(matrix a, matrix b){
	matrix c;
	for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++){
		c.a[i][j] = 0;
		for(int k = 0; k < 2; k++)
			c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
	}
	return c;
}
matrix modpow(matrix a, long long p){
	if(p == 0)return matrix();
	if(p % 2 == 1)return a * modpow(a, p - 1);
	
	matrix r = modpow(a, p / 2);
	return r * r;
}

int main(){
	scanf("%d %d %d %d", &n, &m, &L, &R);
	
	if(n % 2 == 1 && m % 2 == 1){
		printf("%lld\n", modpow(R - L + 1, 1LL * n * m));
	}else{
		long long e = (R - L + 1) / 2, o = (R - L + 1) / 2;
		if((R - L + 1) % 2 == 1){
			if(L % 2 == 0)e++;
			else o++;
		}
		
		matrix b;
		b.a[0][0] = e, b.a[0][1] = o;
		b.a[1][0] = o, b.a[1][1] = e;
		
		b = modpow(b, 1LL * n * m);
		
		printf("%lld\n", b.a[0][0]);
	}
	
	return 0;
}