#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int C[251][251];

long long int power(long long int x,int b){
	long long int res=1;
	while(b){
		if(b&1)	res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}

int main(){
	C[0][0]=1;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	long long int ans=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++){
			long long int tmp=1LL*C[n][i]*C[n][j]%mod*power(k-1,(i+j)*n-i*j)%mod*power(k,(n-i)*(n-j))%mod;
			if((i+j)&1)
				ans-=tmp;
			else
				ans+=tmp;
		}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
}