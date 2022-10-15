#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,K,a[N];
ll s[N];
ll S(ll l,ll r){return (l+r)*(r-l+1)/2;}
inline void work(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
	ll ans=0;
	if(K<=n){
		for(int i=K;i<=n;i++)
			ans=max(ans,s[i]-s[i-K]);
		ans+=S(1,K-1);
		printf("%lld\n",ans);
		return;
	}
	ans=s[n]+1ll*K*n-S(1,n);
	printf("%lld\n",ans);
}
int main(){	
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}