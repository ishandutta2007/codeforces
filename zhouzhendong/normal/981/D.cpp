#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=55;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=x*10+ch-48,ch=getchar();
	return x;
}
int n,k;
int dp[N][N];
LL a[N];
bool check(LL v){
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++){
			LL sum=0;
			for (int t=i-1;t>=0;t--){
				sum+=a[t+1];
				dp[i][j]|=(dp[t][j-1]&&((sum&v)==v));
			}
		}
	return dp[n][k];
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		a[i]=read();
	LL v=0;
	for (int i=56;i>=0;i--)
		if (check(v|(1LL<<i)))
			v|=1LL<<i;
	printf("%I64d",v);
	return 0;
}