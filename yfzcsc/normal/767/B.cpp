#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100100],ts,tf,n,tim,s[100100];
int main(){
	scanf("%lld%lld%lld%lld",&ts,&tf,&tim,&n);
	if(n==0){
		printf("%lld",ts);
		return 0;
	}
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	if(a[1]<ts)s[1]=ts+tim;
	else s[1]=a[1]+tim;
	for(int i=2;i<=n;++i)
		s[i]=max(s[i-1],a[i])+tim;//,printf("[%lld]",s[i]);
	if(a[1]>ts){
		printf("%lld",ts);
	} else {
		a[n+1]=tf+1;
		ll ans=1ll<<40,ansl=0;
		for(int i=1;i<=n+1;++i){
			ll pans=min(a[i]-1,tf-tim);
			if(binary_search(a+1,a+n+1,pans))continue;
			if(pans<=ts&&i==1){
//				printf("[ok,%lld]",ts-pans);
				if(ans>ts-pans)ans=ts-pans,ansl=pans;
			} else if(i==1){
				printf("%lld",pans);
				return 0;
			} else {
				if(pans+tim>tf)continue;
//				printf("[ok,%lld,%lld,%lld]\n",ans,pans,s[i-1]);
				if(max(s[i-1],pans)+tim>tf)continue;
				if(max(0ll,s[i-1]-pans)<ans)
					ans=max(0ll,s[i-1]-pans),ansl=pans;
			}
		}
//		printf("%lld,",ans);
		printf("%lld",ansl);
	}
	
}