#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

struct matrix{
	int A[2][2];
};

matrix operator *(matrix a, matrix b){
	matrix c;
	memset(c.A, 0, sizeof c.A);

	for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	for(int k = 0; k < 2; k++)
		c.A[i][j] = (c.A[i][j] + 1LL * a.A[i][k] * b.A[k][j]) % MOD;
	return c;
}

int npow(int x, long long p){
	if(p == 0)return 1;
	else if(p % 2 == 1)return (1LL * x * npow(x, p - 1)) % MOD;
	else{
		int r = npow(x, p / 2);
		return (1LL * r * r) % MOD;
	}
}
matrix mpow(matrix a, long long p){
	if(p == 0){
		matrix r;
		for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			r.A[i][j] = (i == j);
		return r;
	}else if(p % 2 == 1)return a * mpow(a, p - 1);
	else{
		matrix r = mpow(a, p / 2);
		return r * r;
	}
}

int k;
long long a[MAXN];

int main(){
	scanf("%d", &k);

	matrix T;
	T.A[0][0] = 0; T.A[0][1] = 2;
	T.A[1][0] = 1; T.A[1][1] = 1;

	int t = 1;
	for(int i = 0; i < k; i++){
		scanf("%I64d", &a[i]);
		t = (1LL * t * (a[i] % (MOD - 1))) % (MOD - 1);
	}

	int q = (1LL * npow(2, t) * (MOD + 1) / 2) % MOD;

	matrix C = mpow(T, t);
	int p = (1LL * C.A[0][0] * (MOD + 1) / 2) % MOD;

	printf("%d/%d\n", p, q);

	return 0;
}