#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long int power(long long int a,long long int b){
	long long int res = 1;
	a%=mod;
	while(b){
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int main(){
	long long int n;
	cin>>n;
	long long int ans=2*(power(3,n*n)-power(power(3,n)-3,n)+mod)%mod;
	long long int choose=1;
	for(int i=1;i<=n;i++){
		choose = choose*(n-i+1)%mod*power(i,mod-2)%mod;
		long long int term =3*(power(3,n*(n-i))-power(power(3,n-i)-1,n)+mod)%mod;
		if(i&1)
			ans=((ans-choose*term)%mod+mod)%mod;
		else
			ans=(ans+choose*term)%mod;
	}
	cout<<ans<<endl;
}