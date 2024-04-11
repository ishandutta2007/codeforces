#include<bits/stdc++.h>
#define chk(v1,v2,v3,d) (v1%d==0?v1/=d:(v2%d==0?v2/=d:v3/=d))
#define ll long long
const ll mo1=10000000000ll;
const ll mo2=10000000009ll;
using namespace std;

ll mul(ll x,ll y,ll mo){
	ll ans=(ll)(1.0*x/mo*y);
	ans=(x*y-ans*mo);
	return (ans%mo+mo)%mo;
}
ll S1(ll x,ll y,ll mo){
	ll v1=x+y,v2=y-x+1,v3=1;
	chk(v1,v2,v3,2);
	return mul(v1%mo,v2%mo,mo);
}
ll S2(ll x,ll mo){
	ll v1=x,v2=x+1,v3=2*x+1;
	chk(v1,v2,v3,2); chk(v1,v2,v3,3);
	return mul(mul(v1%mo,v2%mo,mo),v3%mo,mo);
}
ll S2(ll x,ll y,ll mo){
	return (S2(y,mo)+mo-S2(x-1,mo))%mo;
}
ll calc(ll x,ll y,ll mo){
	if (!x||!y) return 0;
	ll ans=0;
	if (x>y){
		ans+=S1(1,y*y,mo);
		ans+=mul(S1(y*y+y+2,y*y+2*y+1,mo),x-y,mo);
		ans+=mul(S2(y+1,x,mo)-mul(x-y,mul(y+1,y+1,mo),mo)+mo,y,mo);
	}
	else{
		ans+=S1(1,x*x,mo);
		ans+=mul(S1(x*x+1,x*x+x,mo),y-x,mo);
		ans+=mul(S2(x,y-1,mo)-mul(y-x,mul(x,x,mo),mo)+mo,x,mo);
	}
	return ans%mo;
}
void solve(){
	int x,y,X,Y;
	scanf("%d%d%d%d",&x,&y,&X,&Y);
	ll ans1=calc(X,Y,mo1)-calc(X,y-1,mo1)-calc(x-1,Y,mo1)+calc(x-1,y-1,mo1);
	ll ans2=calc(X,Y,mo2)-calc(X,y-1,mo2)-calc(x-1,Y,mo2)+calc(x-1,y-1,mo2);
	ans1=(ans1%mo1+mo1)%mo1; ans2=(ans2%mo2+mo2)%mo2;
	if (ans1==ans2) printf("%lld\n",ans1);
	else if (ans1>=1000000000) printf("...%lld\n",ans1);
	else printf("...0%09lld\n",ans1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}