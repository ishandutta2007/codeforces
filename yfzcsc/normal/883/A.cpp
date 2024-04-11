#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
int n,m,a;
ll d,t[maxn],nxt,ans;
int main(){
	scanf("%d%d%d%lld",&n,&m,&a,&d);
	for(int i=1;i<=m;++i)
		scanf("%lld",&t[i]);
	nxt=d/a+1;
	m=unique(t+1,t+m+1)-t-1;
	ll p1=1,p2=1;
	while(p1<=n&&p2<=m){
//		printf("[%lld,%lld]\n",p1,p2);
		if(p1*a>t[p2]){
			ll x=t[p2]+d;
			p1=x/a+1;
			while(p2<=m&&t[p2]<=x)p2++;
			ans++;
		} else {
			ll y=min((ll)n,t[p2]/a);
			ll z=(y-p1)/nxt+1;
			ans+=z,p1+=z*nxt;
			ll x=(p1-nxt)*a+d;
			while(p2<=m&&t[p2]<=x)p2++;
		}
	}
//	printf("[%lld,%lld]\n",p1,p2);
	if(p1<=n){
		ans+=(n-p1)/nxt+1;
	} 
	while(p2<=m){
		ll x=t[p2]+d;
		while(p2<=m&&t[p2]<=x)p2++;
		ans++;
	}
	printf("%lld",ans);
}