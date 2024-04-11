#include <bits/stdc++.h>
#define N 2048808
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

int n, k;
ll pw[N], ans[N], output = 0;
int pn, mu[N], p[170734];

inline void add(ll &a, const ll b) {(a += b) >= mod ? a -= mod : 0;}
ll PowerMod(ll a, int n, ll c = 1) {for(; n; n >>= 1, (a *= a) %= mod) if(n & 1) (c *= a) %= mod; return c;}

void sieve(int n){
	int i, j, v; pn = 0;
	memset(mu, 1, sizeof mu); mu[1] = 1;
	for(i = 2; i <= n; ++i){
		if(mu[i] > 1) {p[pn++] = i; mu[i] = -1;}
		for(j = 0; j < pn; ++j){
			if((v = i * p[j]) > n) break;
			if(!(i % p[j])) {mu[v] = 0; break;}
			else mu[v] = -mu[i];
		}
	}
}

int main(){
	int i, j;
	scanf("%d%d", &n, &k);
	for(i = 0; i <= k; ++i) pw[i] = PowerMod(i, n);
	sieve(k);
	for(i = 1; i <= k; ++i)
		if(mu[i])
			for(j = 1; i * j <= k; ++j){
				add(ans[i * j], (pw[j] - pw[j - 1]) * mu[i]);
				ans[i * j] < 0 ? ans[i * j] += mod : 0;
			}
	for(i = 1; i <= k; ++i){
		add(ans[i], ans[i - 1]);
		add(output, ans[i] ^ i);
	}
	printf("%d\n", (int)output);
	return 0;
}