#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200010;
const ll mo=1000000007;
ll n,i,inv[N],f[N],a[N],inf[N],ans,x,y;
inline ll C(ll x,ll y){
	return f[x]*inf[y]%mo*inf[x-y]%mo;
}
int main(){
	cin>>n;
	inf[0]=inv[1]=inf[1]=f[0]=f[1]=1;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=2;i<=n;++i){
		f[i]=f[i-1]*i%mo;
		inv[i]=inv[mo%i]*(mo-mo/i)%mo;
		inf[i]=inf[i-1]*inv[i]%mo;
	}
	if(n%4==0){
		x=(n-2)>>1;
		for(i=1;i<=n;++i){
			if(i&1)ans=(ans+C(x,y)*a[i])%mo;
				else ans=(ans-C(x,y)*a[i]%mo+mo)%mo,++y;
		}
	}
	if(n%4==1){
		x=(n-1)>>1;
		for(i=1;i<=n;++i){
			if(i&1)ans=(ans+a[i]*C(x,y))%mo;
				else ++y;
		}
	}
	if(n%4==2){
		x=(n-2)>>1;
		for(i=1;i<=n;++i){
			ans=(ans+C(x,y)*a[i])%mo;
			y+=!(i&1);			
		}
	}
	if(n%4==3){
		x=(n-3)>>1;
		ans=(a[1]-a[n]+mo)%mo;
		for(i=2;i<n;++i){
			if(i&1)ans=(ans+(C(x,y+1)-C(x,y))*a[i]%mo+mo)%mo,++y;
				else ans=(ans+(C(x,y)<<1)*a[i])%mo;
		}
	}
	cout<<ans<<endl;
	return 0;
}