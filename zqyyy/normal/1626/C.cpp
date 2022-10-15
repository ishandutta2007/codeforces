#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=107;
int n,k[N],h[N],a[N];
inline ll Get(ll l,ll r){
	l=max(l,0ll);
	return (l+r)*(r-l+1)/2;	
}
inline void work(){
	cin>>n;
	for(int i=1;i<=n;i++)k[i]=read(),a[i]=0;
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=n-1;i;i--)h[i]=max(h[i],h[i+1]-(k[i+1]-k[i]));
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(h[i]<=k[i]-k[i-1])a[i]=h[i],ans+=Get(1,a[i]);
		else a[i]=a[i-1]+k[i]-k[i-1],ans+=Get(a[i-1]+1,a[i]);
	}
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