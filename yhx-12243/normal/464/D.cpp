#include <bits/stdc++.h>
#define N 1034
using namespace std;

int n, k, i, j;
double A, B, C;
double f[2][N];

int main(){
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; ++i)
		for(j = 1; j < N; ++j){
			A = f[i & 1 ^ 1][j] * (double)(k * (j + 1) - 1);
			B = f[i & 1 ^ 1][j + 1];
			C = (double)(j * (j + 3) >> 1); // 1 + 2 + ... + j + j
			f[i & 1][j] = (A + B + C) / (double)(k * (j + 1));
		}
	printf("%.15lg\n", f[n & 1][1] * k);
	return 0;
}