#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long int dp[5001][5001];
long long int f[5001];

long long int power(long long int x,long long int b){
	long long int res=1;
	while(b){
		if(b&1)	res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	dp[0][0]=1;
	for(int i=1;i<=5000;i++)
		for(int j=1;j<=i;j++)
			dp[i][j]=((dp[i-1][j-1]-dp[i-1][j]*(i-1))%mod+mod)%mod;
	f[0]=1;
	long long int fac=n;
	long long int inv=power(m,mod-2),p=inv;
	for(int i=1;i<=k;i++){
		f[i]=fac*p%mod;
		for(int j=1;j<i;j++)
			f[i]-=dp[i][j]*f[j]%mod;
		f[i]=(f[i]%mod+mod)%mod;
		fac=fac*(n-i)%mod;
		p=inv*p%mod;
	}
	cout<<f[k]<<endl;
}