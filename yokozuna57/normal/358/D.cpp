#include<iostream>
using namespace std;

int main(){
	int n,a[3002],b[3002],c[3002],dp[3002][2];
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	for(int i=0;i<n;i++)scanf("%d",&c[i]);
	dp[0][0]=a[0]; dp[0][1]=b[0];
	for(int i=1;i<n;i++){
		dp[i][0]=max(dp[i-1][0]+b[i],dp[i-1][1]+a[i]);
		dp[i][1]=max(dp[i-1][0]+c[i],dp[i-1][1]+b[i]);
		//cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	printf("%d\n",dp[n-1][0]);
}