#include<iostream>
using namespace std;
typedef long long ll;
const ll mo=1000000007;
int n,i,j;
ll s,x,y,z,f[25],ans;
inline ll inv(ll x){
	ll y=1,i;
	for(i=mo-2;i;i>>=1,x=x*x%mo)if(i&1)y=y*x%mo;
	return y;
}
inline ll C(ll x,ll y){
	ll a=1,b=1;
	for(ll i=1;i<=y;++i)b=b*i%mo;
	for(ll i=x;i>=x-y+1;--i)a=a*i%mo;
	return a*inv(b)%mo;
}
ll lucas(ll x,ll y){
	if(!y)return 1;
	return lucas(x/mo,y/mo)*C(x%mo,y%mo)%mo;
}
int main(){
	cin>>n>>s;
	for(i=1;i<=n;++i)cin>>f[i];
	for(i=0;i<1<<n;++i){
		x=s;
		y=1;
		for(j=0;j<n;++j)if(i&(1<<j))x-=f[j+1]+1,y=-y;
		if(x<0)continue;
		ans=(ans+mo+y*lucas(x+n-1,n-1))%mo;
	}
	cout<<ans<<endl;
	return 0;
}