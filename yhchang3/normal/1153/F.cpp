#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long int ex(long long int x,long long int b){
	x%=mod;
	long long int res=1;
	while(b){
		if(b&1)
			res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}
long long int f[4002][2001][2];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int n,k,l;
	cin>>n>>k>>l;
	f[0][0][0]=1;
	for(int i=0;i<=2*n;i++)
		for(int j=0;j<=n;j++)
			for(int x=0;x<2;x++){
				if(j)
					f[i+1][j-1][x]=(f[i+1][j-1][x]+j*f[i][j][x])%mod;
				if(j>=k&&!x)
					f[i+1][j][1]=(f[i+1][j][1]+f[i][j][x])%mod;
				if(i+j<2*n+x)
					f[i+1][j+1][x]=(f[i+1][j+1][x]+f[i][j][x])%mod;
			}
	long long int ans=f[2*n+1][0][1]*l%mod;
	for(int i=1;i<=2*n+1;i++)
		ans=ans*ex(i,mod-2)%mod;
	ans=ans*ex(2,n)%mod;
	for(int i=1;i<=n;i++)
		ans=ans*i%mod;
	cout<<ans<<endl;
	
}