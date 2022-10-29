#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
using namespace std;


long long int dp[2][100003];


double pow10(double x, int n) {
	for (int i=0;n>i;i++) x*=10;
	return x;
}



int main () {
	int n,p;
	while (scanf("%d %d",&n,&p) != EOF) {
		memset(dp,0,sizeof(dp));


		for (int x=0;n>x;x++) {
			int l,r;
			scanf("%d %d",&l,&r);
			if (r%p==0) dp[1][x]++;
			int tl = (l%p==0?l/p-1:l/p);
			int tr = (r%p==0?r/p-1:r/p);
			dp[1][x] += (tr-tl);         // 
			dp[0][x] = r-l+1-dp[1][x];
			if (x==0) {
				dp[1][n]=dp[1][0];
				dp[0][n]=dp[0][0];
			}
		}
		
		/*for (int x=0;2>x;x++) {
			for (int y=0;n>y;y++) {
				cout << dp[x][y] << ' ';
			}
			cout << endl;
		}*/
		
		double ans=0.0;
		
		for (int x=0;n>x;x++) {
			if (false);
			else  {
				double a=((dp[1][x]*(dp[1][x+1]+dp[0][x+1]) + dp[0][x] * dp[1][x+1]) * 2);
				ans += a*1000/((dp[0][x]+dp[1][x])*(dp[0][x+1] + dp[1][x+1]));
			}
		}
		
		
		printf("%.15f\n",ans);
	}
}