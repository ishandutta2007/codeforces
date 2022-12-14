#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int fac[400010], ifac[400010];

int C(int n, int k){
	return 1LL * fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for(int i=2;i<=400000;i++)
		fac[i] = 1LL * fac[i-1] * i % mod,
		ifac[i] = mod - 1LL * mod / i * ifac[mod % i] % mod;
	for(int i=2;i<=400000;i++)
		ifac[i] = 1LL * ifac[i-1] * ifac[i] % mod;
	int n;
	cin >> n;
	int res = 0;
	for(int i=1;i<=n;i++)
		if((n - i) % 2 == 0){
			int k = (n - i) / 2;
			res = (res + C(i + k - 1, k)) % mod;
		}
	for(int i=1;i<=n;i++)
		res = 1LL * res * ((mod + 1) / 2) % mod;
	cout << res << endl;
}