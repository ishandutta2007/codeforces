#include<bits/stdc++.h>
const int mo=1e9+7;
int n,i,j,k,v[2505],s,ans,a[100005],f[100005],mx;
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",v+i),s+=v[i],mx=std::max(mx,v[i]);
	for(i=1;i<=mx;++i)
		a[i]=(1ll*i*a[i-1]+1ll*i*(s-1)%mo*poww(s-i,mo-2))%mo*poww(i+1,mo-2)%mo;
	f[1]=(s-2+poww(s,mo-2))%mo;
	for(i=2;i<=mx;++i)f[i]=1ll*i*(f[i-1]+mo-a[i-1])%mo*poww(i-1,mo-2)%mo;
	for(i=1;i<=n;++i)ans=(ans+f[v[i]])%mo;
	printf("%d\n",ans);
	return 0;
}