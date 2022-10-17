#include<iostream>
using namespace std;
int n,k,a[2002];

int z(int x){if(x<0)return -x; return x;}
bool f(long long int x){
	int dp[2002],ret=1;
	long long int ff[2002];
	dp[0]=1;
	ff[0]=0;
	for(int i=1;i<=k+1;i++)ff[i]=ff[i-1]+x;
	for(int i=1;i<n;i++){
		dp[i]=1;
		int p=max(0,i-k-1);
		for(int j=i-1;j>=p;j--){
			if(z(a[i]-a[j])<=ff[i-j])dp[i]=max(dp[i],dp[j]+1);
		}
		ret=max(ret,dp[i]);
	}
	if(ret>=n-k)return true;
	return false;
}
	

int solve(){
	long long int l=0,r=2000000000;
	while(l<r){
		long long int s=(l+r)/2;
		if(f(s))r=s;
		else l=s+1;
	}
	return l;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",solve());
}