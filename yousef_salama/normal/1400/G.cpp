#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int MAXM = 25;
const int MOD = 998244353;

int n, m, l[MAXN], r[MAXN], a[MAXN], b[MAXN];

long long modpow(long long x, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;
	
	long long r = modpow(x, p / 2);
	return r * r % MOD;
}
long long modinv(long long x){
	return modpow(x, MOD - 2);
}

long long fact[MAXN], invfact[MAXN];
long long C(int n, int r){
	if(r > n || r < 0)return 0;
	return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int c[MAXN];
long long pref[2 * MAXM][MAXN];
bool vis[MAXN];

int main(){
	scanf("%d %d", &n, &m);
	
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
		fact[i] = i * fact[i - 1] % MOD;
	
	invfact[n] = modinv(fact[n]);
	for(int i = n - 1; i >= 0; i--)
		invfact[i] = (i + 1) * invfact[i + 1] % MOD;
		
	for(int i = 0; i < n; i++){
		scanf("%d %d", &l[i], &r[i]);
		
		c[l[i]]++;
		c[r[i] + 1]--;
	}
	for(int i = 2; i <= n; i++)
		c[i] += c[i - 1];
		
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a[i], &b[i]);
		a[i]--, b[i]--;
	}
	
	for(int j = 0; j <= 2 * m; j++)
	for(int i = 1; i <= n; i++){
		pref[j][i] = (C(c[i] - j, i - j) + pref[j][i - 1]) % MOD;
	}
	
	long long res = 0;
	for(int mask = 0; mask < (1 << m); mask++){
		int cnt = 0, li = 1, ri = n;
		for(int i = 0; i < m; i++)if(mask & (1 << i)){
			if(!vis[a[i]]){
				vis[a[i]] = true;
				cnt++;
			}
			li = max(li, l[a[i]]);
			ri = min(ri, r[a[i]]);
			
			if(!vis[b[i]]){
				vis[b[i]] = true;
				cnt++;
			}
			li = max(li, l[b[i]]);
			ri = min(ri, r[b[i]]);
		}
		for(int i = 0; i < m; i++){
			vis[a[i]] = false;
			vis[b[i]] = false;
		}
		
		if(li > ri)continue;
		
		if(__builtin_popcount(mask) % 2 == 0){
			res = (res + pref[cnt][ri] - pref[cnt][li - 1] + MOD) % MOD;
		}else{
			res = (res - pref[cnt][ri] + pref[cnt][li - 1] + MOD) % MOD;
		}
	}
	printf("%lld\n", res);
	
	return 0;
}