# include <bits/stdc++.h>
using namespace std;
const int MN = 2e6 + 44, M = 1e9 + 7;
long long fac[MN], fin[MN];
long long bin(int a, int b) {
	return fac[a] * fin[b] % M * fin[a - b] % M;
}
long long pow(long long b, int e) {
	if (e == 0)
		return 1;
	else if (e % 2)
		return pow(b, e - 1) * b % M;
	else
		return pow(b * b % M, e / 2);
}
int main() {
	fac[0] = 1;
	for (int i = 0; i < MN - 1; ++i)
		fac[i + 1] = fac[i] * (i + 1) % M;
	fin[MN - 1] = pow(fac[MN - 1], M - 2);
	for (int i = MN - 2; i >= 0; --i)
		fin[i] = fin[i + 1] * (i + 1) % M;
	for (int i = 0; i < 10; ++i) {
		cerr << i << '.' << fac[i] << ' ' << fin[i] << endl;
	}
	int n;
	scanf("%d", &n);
	long long res = 0;
	for (int i = 0; i <= n; ++i) {
		res += bin(n + i + 1, n);
	}
	res %= M;
	printf("%lld\n", res);
}