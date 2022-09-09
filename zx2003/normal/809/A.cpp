#include<bits/stdc++.h>
const int N=300005,mo=1000000007,inv2=500000004;
int n,a[N],i,su,ans,mi=1,iv=inv2;
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n;for(i=1;i<=n;++i)std::cin>>a[i];
	std::sort(a+1,a+n+1);
	for(i=1;i<=n;++i){
		if(i>1)ans=(ans+1ll*a[i]*(mi+mo-1)-2ll*su*mi%mo)%mo;
		mi=(mi+mi)%mo;iv=1ll*iv*inv2%mo;
		su=(su+1ll*a[i]*iv)%mo;
	}std::cout<<ans<<'\n';
	return 0;
}