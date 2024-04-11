#include<bits/stdc++.h>
typedef long long ll;
const int N=1e6+5,mo=1e9+7;
int n,a[N],i,j,p[N],b[N],c[N],ans;
ll sz[N];
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i)scanf("%d",p+i+1);
	for(i=n;i;--i)sz[p[i]]+=sz[i]+=a[i];
	for(i=1;i<=n;++i)++b[std::min(ll(n+1),sz[1]/std::__gcd(sz[1],sz[i]))];
	for(i=n;i;--i)for(j=i*2;j<=n;j+=i)b[j]+=b[i];
	for(i=1;i<=n;++i)b[i]=b[i]==i;c[1]=1;
	for(i=1;i<=n;++i)if(b[i])for(j=i*2;j<=n;j+=i)if(b[j])c[j]=(c[j]+c[i])%mo;
	for(i=1;i<=n;++i)ans=(ans+c[i])%mo;printf("%d\n",ans);
	return 0;
}