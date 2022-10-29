#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_P = 56;

LL x[MAX_P],y[MAX_P];
LL sum[MAX_P];
LL dp[2][MAX_P];  //+1, when j=j;

int main () {
	LL a,b;
	while (scanf("%I64d %I64d",&a,&b) != EOF) {
		memset(dp,0,sizeof(dp));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		LL s=a,d=b;
		int i=1;
		while (a>0) {
			x[i++] = a%2;
			a/=2;
		}
		int j=1;
		while (b>0) {
			y[j++] = b%2;
			b/=2;
		}
		//x --> sum , y-->XOR
		LL cnt=1;
		bool _1=false;
		
		dp[0][0]=1;
		int n=max(i,j);
		for (int c=1;n>=c;c++) {
			if (x[c]==0 && y[c]==0) {
				dp[0][c] = dp[0][c-1]*1;  //00
				dp[1][c] = dp[0][c-1]*1;  //11
			}
			else if (x[c]==0 && y[c]==1) {
				dp[1][c] = dp[1][c-1]*2;  //10 or 01
			}
			else if (x[c]==1 && y[c]==0) {
				dp[0][c] = dp[1][c-1]*1;  //00
				dp[1][c] = dp[1][c-1]*1;  //11
			}
			else if (x[c]==1 && y[c]==1) {
				dp[0][c] = dp[0][c-1]*2; //10 or 01
			}
			//cout<<"dp[0]["<<c<<"] = "<<dp[0][c]<<" , dp[1]["<<c<<"] = "<<dp[1][c]<<endl;
		}
		printf("%I64d\n",dp[0][n] - (s==d?2:0));
	}
}