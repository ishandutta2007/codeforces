#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=105;
int n,a[N];
LL dp[N][3];
char s[N];
LL solve(int f){
	memset(dp,0,sizeof dp);
	dp[1][f]=1;
	for (int i=1;i<=n;i++){
		dp[i+1][2]=dp[i][2-(a[i]^1)];
		dp[i+1][a[i]]=dp[i][0]+dp[i][2];
		dp[i+1][a[i]^1]=0;
//		printf("%d %d %d\n",dp[i+1][0],dp[i+1][1],dp[i+1][2]);
	}
	return dp[n+1][f];
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		a[i]=(s[i]=='B');
	printf("%I64d",solve(0)+solve(1)+solve(2));
	return 0;
}