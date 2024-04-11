#include<bits/stdc++.h>
#define maxn 101000
using namespace std;
typedef pair<int,int> par;
int n,tp,m,k,a[maxn];
long long ans;
par sta[maxn],sta2[maxn<<1];
void sol(int l,int r){
	int tp2=0;
	for(int i=1;i<=r;++i)
		if(!tp2||sta2[tp2].first!=sta[i].first)sta2[++tp2]=sta[i];
		else if((sta2[tp2].second+=sta[i].second)==k)ans-=k,tp2--;
		else if(sta2[tp2].second>k)ans-=k,sta2[tp2].second-=k;
	for(int i=l;i<=tp;++i)
		if(!tp2||sta2[tp2].first!=sta[i].first)sta2[++tp2]=sta[i];
		else if((sta2[tp2].second+=sta[i].second)==k)ans-=k,tp2--;
		else if(sta2[tp2].second>k)ans-=k,sta2[tp2].second-=k;
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	ans=1ll*n*m;
	for(int i=1;i<=n;++i)
		if(!tp||sta[tp].first!=a[i])sta[++tp]=par(a[i],1);
		else if((++sta[tp].second)==k)tp--,ans-=1ll*m*k;
	if(!tp)return puts("0"),0;
	if(tp==1){
		long long all=1ll*sta[tp].second*m;
		ans-=all/k*k;
		return printf("%lld",ans),0;
	}
	int l=1,r=tp;
	while(l<r){
		if(sta[l].first!=sta[r].first)break;
		else if(sta[l].second+sta[r].second>k){ans-=1ll*k*(m-1);break;}
		else if(sta[l].second+sta[r].second==k)l++,r--,ans-=1ll*k*(m-1);
		else break;
	}
//	printf("[%lld(%d,%d)]",ans,l,r);
	if(l==r){
		long long all=1ll*sta[l].second*m;
		ans-=all/k*k;
	//	printf("[%lld]",all/k*k);
		if(all%k==0)sol(l+1,r-1);
	} else if(r+1==l)sol(l,r);
	printf("%lld",ans);
}