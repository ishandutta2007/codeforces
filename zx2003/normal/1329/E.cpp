#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
int T,m,i;
ll n,k,p[N],q[N],L,R;
pair<ll,int>a[N];
inline ll getl(){
	ll l=1,r=1ll<<60,m,tot;
	for(i=1;i<=::m;++i)r=min(r,p[i]);
	for(;l<r;){
		m=l+r+1>>1;
		for(tot=0,i=1;i<=::m;++i)tot+=p[i]/m;
		if(tot-::m>=k)l=m;else r=m-1;
	}
	return l;
}
inline ll getr(){
	ll l=1,r=0,m,tot;
	for(i=1;i<=::m;++i)r=max(r,p[i]);
	for(;l<r;){
		m=l+r>>1;
		for(tot=0,i=1;i<=::m;++i)tot+=(p[i]+m-1)/m;
		if(tot-::m<=k)r=m;else l=m+1;
	}
	return l;
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%lld%d%lld",&n,&m,&k);
		for(i=1;i<=m;++i)scanf("%lld",p+i);
		p[m+1]=n-p[m];for(i=m;i;--i)p[i]-=p[i-1];++m;
		L=getl();R=getr();
		for(i=1;i<=m;++i)q[i]=p[i]/L;
		for(i=1;i<=m;++i)if((p[i]+q[i]-1)/q[i]>R)break;
		if(i>m){printf("%lld\n",R-L);continue;}
		ll mn=1ll<<60,ans=1ll<<60;
		for(i=1;i<=m;++i)mn=min(mn,p[i]/q[i]),a[i]={(p[i]+q[i]-1)/q[i],i};
		sort(a+1,a+m+1);
		for(i=m;i;--i){
			ll z;int j;tie(z,j)=a[i];
			ans=min(ans,max(z,R)-mn);
			if(z<=R)break;
			q[j]=(p[j]+R-1)/R;mn=min(mn,p[j]/q[j]);
		}
		printf("%lld\n",ans);
	}
}