#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,r,f[N],s[N],p[N],sum[N];
double dp[N][N*100];
bool check(double x){
	for(int i=r+1;i<=sum[n];i++)dp[n+1][i]=x;
	for(int i=n;i;i--){
		for(int j=0;j<=max(sum[i-1],r);j++){
			if(j>r)dp[i][j]=x; else dp[i][j]=min(x,(dp[i+1][j+f[i]]+f[i])*p[i]/100+(dp[i+1][j+s[i]]+s[i])*(100-p[i])/100);
		}
	}
	return dp[1][0]<x;
}
int main(){
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&f[i],&s[i],&p[i]);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i];
	double l=0,r=10000000000;
	for(int i=1;i<=100;i++){
		double mid=(l+r)/2;
		if(check(mid))r=mid; else l=mid;
	}
	printf("%.10lf\n",l);
}