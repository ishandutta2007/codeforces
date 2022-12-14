#include<iostream>
using namespace std;
const int mod = 1e9+7;

long long int dp[5001][5001];

long long int pow(long long int a,long long int b){
	long long int res=1;
	a%=mod;
	while(b){
		if(b&1)	res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int main(){
	int n,k;
	cin>>n>>k;
	for(int j=0;j<=k;j++)
		if(n-j>=0)
			dp[j][0]=(pow(2,n-j)+mod-1)%mod;
	for(int i=1;i<=k;i++)
		for(int j=k-i;j>=0;j--)
			dp[j][i]=(dp[j][i-1]-dp[j+1][i-1]+mod)*(n-j)%mod;
	cout<<dp[0][k]<<endl;
}