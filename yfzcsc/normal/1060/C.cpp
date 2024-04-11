#include<bits/stdc++.h>
#define maxn 2010
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
ll n,m,a[maxn],b[maxn],tpa,tpb,X;
pii ca[maxn*maxn],cb[maxn*maxn];
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<=m;++i)scanf("%lld",&b[i]),b[i]+=b[i-1];
	scanf("%lld",&X);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			ca[++tpa]=pii(a[j]-a[i-1],j-i+1);
	for(int i=1;i<=m;++i)
		for(int j=i;j<=m;++j)
			cb[++tpb]=pii(b[j]-b[i-1],j-i+1);
	sort(ca+1,ca+tpa+1);
	sort(cb+1,cb+tpb+1);
	ll ans=0,mx=0;
	for(int i=tpa,j=0;i>=1;--i){
		while((ll)ca[i].first*cb[j+1].first<=X&&j<tpb){
			j++,mx=max(mx,(ll)cb[j].second);
		}
		ans=max(ans,mx*ca[i].second);
	}
	printf("%lld",ans);
}