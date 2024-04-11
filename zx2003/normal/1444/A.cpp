#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,q,i,x;ll p,ans;
inline void upd(int x){
	ll p=::p;int q=::q;
	for(;p%q==0;p/=x);ans=max(ans,p);
}
inline void factor(int x){
	for(i=2;i*i<=x;++i)if(x%i==0)for(upd(i);x%i==0;x/=i);
	if(x>1)upd(x);
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%lld%d",&p,&q);
		if(p%q)ans=p;else ans=0,factor(q);
		printf("%lld\n",ans);
	}
}