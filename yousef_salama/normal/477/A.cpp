#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int a, b;
int main(){
	scanf("%d %d", &a, &b);

	int r = 0;
	for(long long m = 1; m < b; m++){
		long long c = (m * a) % MOD;

		long long d = (1LL * a * (a + 1) / 2) % MOD;
		d = (d * m) % MOD;
		d = (d * b) % MOD;

		r = (r + c + d) % MOD;
	}
	printf("%d\n", r);

	return 0;
}