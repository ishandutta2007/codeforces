#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const int MOD = 998244353;

int n, k, m, li[MAXN], ri[MAXN], xi[MAXN];

int d[MAXN], c[MAXN];
long long dp[MAXN], sum[MAXN];

int main(){
	scanf("%d %d %d", &n, &k, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &li[i], &ri[i], &xi[i]);
		li[i]--, ri[i]--;
	}
	
	long long res = 1;
	for(int b = 0; b < k; b++){
		for(int i = 0; i < n; i++){
			d[i] = 1 << 20;
			c[i] = 0;
		}
		for(int i = 0; i < m; i++){
			if(xi[i] & (1 << b)){
				c[ri[i]]++;
				if(li[i] > 0)c[li[i] - 1]--;
			}else{
				d[li[i]] = min(ri[i], d[li[i]]);
			}
		}
		
		int ci = 0;
		for(int i = n - 1; i >= 0; i--){
			if(i < n - 1)d[i] = min(d[i], d[i + 1]);
			
			ci += c[i];
			if(ci == 0){
				c[i] = 0;
				//c[i] = i;
			}else{
				c[i] = 1;
				//if(i < n - 1)c[i] = c[i + 1];
				//else c[i] = 1 << 20;
			}
		}
		
		for(int i = n; i >= 0; i--){
			if(i == n){
				if(c[i - 1] == 1){
					dp[i] = 0;
					sum[i] = 0;
				}else{
					dp[i] = 1;
					sum[i] = 1;
				}
			}else{
				if(i > 0 && c[i - 1] == 1){
					dp[i] = 0;
					sum[i] = sum[i + 1];
				}else{
					if(d[i] == (1 << 20))dp[i] = 1;
					else dp[i] = 0;
					
					dp[i] = (dp[i] + sum[i + 1] - (d[i] + 2 <= n ? sum[d[i] + 2] : 0) + MOD) % MOD;
					sum[i] = (dp[i] + sum[i + 1]) % MOD;
				}
			}
		}
		/*if(b == 2){
			for(int i = 0; i <= n; i++)
				cout << dp[i] << ' ';
			cout << endl;
		}*/
		res = (res * dp[0]) % MOD;
	}
	printf("%lld\n", res);
	
	return 0;
}