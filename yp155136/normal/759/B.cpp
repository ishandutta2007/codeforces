#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 +6;

LL a[MAX_N];
LL dp[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&a[i]);
		}
		a[0] = a[1];
		int _50=1,_120=1;
		for (int i=1;n>=i;i++) {
			while (a[i]-a[_50]>=90) _50++;
			while (a[i]-a[_120]>=1440) _120++;
			dp[i] = min(dp[i-1]+20,dp[_50-1]+50);
			dp[i] = min(dp[_120-1]+120,dp[i]); 
		}
		for (int i=1;n>=i;i++) {
			//cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
			printf("%I64d\n",dp[i]-dp[i-1]);
		}
	}
}