#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e6+7;
int n,K,L,ans,a[N];
ll f[N],g[N];
char str[N];
inline int check(ll mid){
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i],g[i]=g[i-1];
		if(i>=L){
			ll v=f[i-L]+mid;
			if(v<f[i])f[i]=v,g[i]=g[i-L]+1;
		}
	}
	return g[n];
}
inline int solve(){
	ll l=-1e10-1,r=1e10+1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)<=K)r=mid-1;
		else l=mid+1;
	}
	check(l);
	return f[n]-l*K;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),K=read(),L=read(),scanf("%s",str+1);
	if(1ll*K*L>=n)puts("0"),exit(0);
	for(int i=1;i<=n;i++)a[i]=str[i]<='Z';
	ans=solve();for(int i=1;i<=n;i++)a[i]^=1;
	ans=min(ans,solve());
	printf("%d\n",ans);
	return 0;
}