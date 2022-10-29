#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int n;ll cost[maxn],A[maxn];
char s[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&cost[i]);
	scanf("%s",s+1);
	int w=1;
	while(w<=n&&s[w]!='W')w++;
//	printf("{%d}",w);
	ll a=0,mxa=0,ans=0;
	for(int i=1;i<=w-1;++i){
		if(s[i]=='G')a+=cost[i];
		else a-=cost[i];
		mxa=min(mxa,a);
	}
	ans=-mxa*5;
	a=-mxa;
//	printf("[%lld]",ans);
	for(int i=1;i<=w-1;++i){
		if(s[i]=='G')ans+=cost[i]*5ll,a+=cost[i];
		else a-=cost[i],ans+=cost[i];
	}
	for(int i=n;i>=w;--i)
		A[i]=min(A[i+1]+(s[i]=='L'?-cost[i]:cost[i]),0ll);	
	if(a>-A[w])ans-=(a+A[w])*2;
	else ans-=(a+A[w])*3;
//	printf("[%lld]",ans);
	a=-A[w];
	for(int i=w;i<=n;++i){
		if(s[i]=='L'){
			a-=cost[i];
			ans+=cost[i];
			continue;
		}
		if(s[i]=='G'){
			ll fff=-A[i+1]-a;
			fff=max(fff,-cost[i]);
			ans+=3*cost[i]+2*fff,a+=fff;
			continue;
		}
		a+=cost[i],ans+=3*cost[i];
	}
	printf("%lld",ans-a);
}