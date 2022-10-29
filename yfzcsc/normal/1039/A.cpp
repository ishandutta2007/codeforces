#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf=(ll)3e18;
int n,xi[maxn],tg[maxn];
ll t,a[maxn],b[maxn],c[maxn];
pii dp[maxn];
pii merge(pii a,pii b){
	return pii(max(a.first,b.first),min(a.second,b.second));
}
int main(){
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&xi[i]);
	for(int i=1;i<=n;++i)if(xi[i]<i)return puts("No"),0;
	for(int i=1;i<=n;++i)dp[i]=pii(a[i]+t,inf);
	for(int i=1;i<=n;++i){
		if(xi[i]<n)dp[xi[i]]=merge(dp[xi[i]],pii(-inf,a[xi[i]+1]+t-1));
		tg[i]++,tg[xi[i]]--;
		dp[xi[i]]=merge(dp[xi[i]],pii(a[i]+t,inf));
	}
	for(int i=1;i<=n;++i){
		tg[i]+=tg[i-1];
		if(tg[i])dp[i]=merge(dp[i],pii(a[i+1]+t,inf));
	}
	for(int i=1;i<=n;++i)if(dp[i].first>dp[i].second)return puts("No"),0;
	for(int i=n;i>=1;--i)c[i]=min(dp[i].second,i==n?inf:c[i+1]-1);
	for(int i=1;i<=n;++i)if(c[i]<1||c[i]<dp[i].first)return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=n;++i)printf("%lld ",c[i]);
}