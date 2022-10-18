#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;

int n;
long long p10[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i <= n; i++){
		if(i == 0)p10[i] = 1;
		else p10[i] = p10[i - 1] * 10 % MOD;
	}
	
	for(int k = 1; k <= n; k++){
		if(k > 1)printf(" ");
	
		if(k == n){
			printf("10");
		}else{
			long long res = p10[n - k - 1] * 10 * 9 * 2 % MOD;
			if(k <= n - 2)res = (res + p10[n - k - 2] * (n - k - 1) % MOD * 10 * 9 * 9) % MOD;
		
			printf("%lld", res);
		}
	}
	printf("\n");
	
	return 0;
}