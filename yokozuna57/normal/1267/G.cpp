#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main(){
	int n,x;
	int c[102];
	scanf("%d%d",&n,&x);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&c[i]);
	}
	
	static ld dp[102][10002];
	for(int i = 0 ; i < 102 ; i ++){
		for(int j = 0 ; j < 10002 ; j ++){
			dp[i][j] = 0.0;
		}
	}
	dp[0][0] = 1.0;
	for(int i = 0 ; i < n ; i ++){
		for(int k = i ; k >= 0 ; k --){
			for(int s = 0 ; s < 10002 ; s ++){
				if(s+c[i] < 10002)dp[k+1][s+c[i]] += dp[k][s];
			}
		}
	}
	for(int k = 0 ; k <= n ; k ++){
		ld s = 0.0;
		for(int j = 0 ; j < 10002 ; j ++){
			s += dp[k][j];
		}
		for(int j = 0 ; j < 10002 ; j ++){
			dp[k][j] /= s;
		}
	}
	
	ld ret = 0.0;
	for(int k = 1 ; k <= n ; k ++){
		for(int j = 0 ; j <= 10000 ; j ++){
			if(j <= x/(ld)(2.0)*(n+k))ret += dp[k][j]*j/(ld)(k);
			else ret += dp[k][j]*x/(ld)(2.0)*(n+k)/(ld)(k);
		}
	}
	printf("%.12Lf\n",ret);
}