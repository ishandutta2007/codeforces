#include<bits/stdc++.h>
using namespace std;

const int mod = 1e6+3;
long long int v[11],a[11][11];

long long int inv[mod];

long long int ex(long long int x,long long int b){
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
	for(int i=1;i<mod;i++)
		inv[i]=ex(i,mod-2);
	for(int i=0;i<=10;i++){
		cout<<'?'<<' '<<i<<endl;
		cin>>v[i];
	}
	for(int i=0;i<=10;i++){
		a[i][0]=1;
		for(int j=1;j<=10;j++)
			a[i][j]=a[i][j-1]*i%mod;
	}
	for(int i=0;i<=10;i++){
		v[i]=v[i]*inv[a[i][i]]%mod;
		for(int j=10;j>=i;j--)
			a[i][j]=a[i][j]*inv[a[i][i]]%mod;
		for(int j=i+1;j<=10;j++){
			v[j]=((v[j]-a[j][i]*v[i])%mod+mod)%mod;
			for(int k=10;k>=i;k--)
				a[j][k]=((a[j][k]-a[j][i]*a[i][k])%mod+mod)%mod;
		}
	}
	for(int i=10;i>0;i--){
		for(int j=i-1;j>=0;j--){
			v[j]=((v[j]-a[j][i]*v[i])%mod+mod)%mod;
		}
	}
	for(int i=0;i<mod;i++){
		long long int ans=0;
		for(int j=0;j<=10;j++){
			ans=(ans+v[j]*ex(i,j))%mod;
		}
		if(ans==0){
			cout<<'!'<<' '<<i<<endl;
			return 0;
		}
			
	}
	cout<<'!'<<' '<<-1<<endl;
}