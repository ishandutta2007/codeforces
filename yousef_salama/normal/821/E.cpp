#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int n, ci;
long long k, ai, bi;

struct matrix{
	long long C[20][20];
};
matrix operator*(matrix a, matrix b){
	matrix c;
	memset(c.C, 0, sizeof c.C);

	for(int i = 0; i < 20; i++)
	for(int j = 0; j < 20; j++)
	for(int k = 0; k < 20; k++)
		c.C[i][j] = (c.C[i][j] + a.C[i][k] * b.C[k][j]) % MOD;
	return c;
}
matrix mpow(matrix x, long long p){
	if(p == 0){
		matrix c;
		for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			c.C[i][j] = (i == j);
		return c;
	}else if(p % 2 == 1)return x * mpow(x, p - 1);
	else{
		matrix c = mpow(x, p / 2);
		return c * c;
	}
}
int main(){
	scanf("%d %I64d", &n, &k);

	vector <long long> v(20, 0);
	v[0] = 1;

	for(int i = 0; i < n; i++){
		scanf("%I64d %I64d %d", &ai, &bi, &ci);
		if(bi > k)bi = k;

		matrix T;
		memset(T.C, 0, sizeof T.C);

		for(int i = 0; i <= ci; i++)
		for(int j = -1; j <= 1; j++){
			int ni = i + j;
			if(ni >= 0 && ni <= ci)T.C[i][ni] = 1;
		}

		T = mpow(T, bi - ai);

		vector <long long> w(20, 0);
		for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			w[j] = (w[j] + v[i] * T.C[i][j]) % MOD;
		v = w;
	}

	printf("%I64d\n", v[0]);

	return 0;
}