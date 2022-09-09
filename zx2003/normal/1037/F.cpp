#include<bits/stdc++.h>
typedef long long ll;
const int N=1e6+5,mo=1e9+7;
int n,k,a[N],i,lb[N],rb[N],st[N],w,ans;
inline ll calc(int x,int y){
	if(k==1)return 1ll*x*y-1;
	int xx,yy;
	xx=x/k;xx+=x%k!=0;yy=y/k;yy+=y%k!=0;
	ll ans=1ll*xx*yy-1+1ll*(x-xx)*(y/k);
	xx=x%k;yy=y%k;
	if(xx>1 && yy>1)ans+=std::max(0,xx-std::max(1,(k-yy+1)));
	if(yy>1)ans+=1ll*(x/k)*std::max(0,k-std::max(1,(k-yy+1)));
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);--k;
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i){
		for(;w && a[st[w]]<a[i];--w);
		lb[i]=st[w];st[++w]=i;
	}
	st[0]=n+1;w=0;
	for(i=n;i;--i){
		for(;w && a[st[w]]<=a[i];--w);
		rb[i]=st[w];st[++w]=i;
	}
	for(i=1;i<=n;++i)ans=(ans+std::max(0ll,calc(i-lb[i],rb[i]-i))%mo*a[i])%mo;
	printf("%d\n",ans);
	return 0;
}