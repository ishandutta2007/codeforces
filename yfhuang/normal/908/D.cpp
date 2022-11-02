#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

LL k,pa,pb;

LL gcd(LL a,LL b){
	if(b == 0) return a;
	return gcd(b,a % b);
}
const LL mod = 1e9 + 7;
LL qpow(LL a,LL n){
	LL ret = 1;
	while(n > 0){
		if(n & 1) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

LL inv(LL a){
	return qpow(a,mod - 2);
}

LL dp[1005][1005];

int main(){
	cin >> k >> pa >> pb;
	LL Inv = inv(pa + pb);
	LL Invb = inv(pb);
	for(int i = k;i >= 0;i--){
		for(int j = k;j >= 0;j--){
			if(i == k){
				dp[i][j] = i;
			}else if(j == k){
				dp[i][j] = pb * (i + j) + pa;
				dp[i][j] %= mod;
				dp[i][j] = dp[i][j] * Invb % mod;	
			}else{
				if(j > 0){
					LL tmp;
					if(i + j >= k) tmp = i + j;
					else tmp = dp[i + j][j];
					dp[i][j] = pa * dp[i][j + 1] + pb * tmp;
					dp[i][j] %= mod;
					dp[i][j] = dp[i][j] * Inv % mod;
				}else{
					dp[i][j] = dp[i][j + 1];
				}
			}
		}
	}
	cout << dp[0][0] << endl;
	return 0;
}