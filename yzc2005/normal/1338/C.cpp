#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, cnt;
ll n, po[100], sum[100];
const int a[] = {1, 0, 2, 3};

inline ll getans1(ll n) {
	for(int k = 0; ; ++k) {
		if(n <= po[k]) return po[k] | (n - 1);
		n -= po[k];
	}	
}

inline ll getans2(ll n) {
	if(n == 1) return 2;
	ll ans = a[(n - 1) % 4];
	for(int k = 2; ; ++k) {
		if(n <= sum[k - 1]) return ans += 2 * po[k - 1];
		ans += a[(ll)ceil((n - sum[k - 1]) * 1.0 / po[k - 1]) % 4] * po[k - 1];
	} 
	return ans;
}

int main() {
	po[0] = sum[0] = 1; for(int i = 1; i <= 30; ++i) po[i] = po[i - 1] * 4, sum[i] = sum[i - 1] + po[i];
	for(scanf("%d", &t); t; --t) {
		scanf("%lld", &n);
		if(n % 3 == 1) printf("%lld\n", getans1(n / 3 + 1));
		else if(n % 3 == 2) printf("%lld\n", getans2(n / 3 + 1));
		else printf("%lld\n", getans1(n / 3) ^ getans2(n / 3));
	}
	return 0;
}