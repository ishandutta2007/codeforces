#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n;
ll K,a[N],s[N];
inline void work(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)s[i]=s[i-1]+a[i];
	if(s[n]+a[1]<=K){puts("0");return;}
	ll ans=1e18;K=s[n]+a[1]-K;
	for(int i=1;i<=n;i++){
		ll l=K-((s[n]-s[i])-a[1]*(n-i));
		if(l<=0){ans=min(ans,(ll)n-i);continue;}
		ll r=(l+n-i)/(n-i+1);
		ans=min(ans,r+n-i);
	}
	printf("%lld\n",ans);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}