#include<iostream>
using namespace std;
long long int z(long long int x){
	if(x<0)x=-x;
	return x;
}

int main(){
	static long long int n,a[300000+2],b[300000+2],dp[300000+2];
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	dp[0]=0; b[0]=1;
	for(int i=1;i<=n;i++)b[i]=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=1){dp[0]+=1-a[i]; b[1]++;}
		else if(a[i]>=n){dp[0]+=a[i]-n; b[n]++;}
		else b[a[i]]++;
	}
	for(int i=0;i<n;i++){
		b[i]--;
		b[i+1]+=b[i];
		dp[i+1]=dp[i]+z(b[i]);
	}
	printf("%I64d\n",dp[n]);
}