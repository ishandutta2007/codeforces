#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,N=3e5+5;
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
int n,a[N],i,m,f[N],k[N],b[N],p1[N],p2[N],p3[N],ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),m+=a[i];
	for(i=0;i<m;++i){
		p1[i]=1ll*i*poww(m,mo-2)%mo;
		p2[i]=1ll*poww(m,mo-2)*(m-i)%mo*poww(n-1,mo-2)%mo*(n-2)%mo;
		p3[i]=1ll*poww(m,mo-2)*(m-i)%mo*poww(n-1,mo-2)%mo;
	}
	k[0]=1ll*(poww(1+mo-p2[0],mo-2))*p3[0]%mo;
	b[0]=(poww(1+mo-p2[0],mo-2))%mo;
	for(i=1;i<m;++i){
		int w=poww((1+2ll*mo-p2[i]-1ll*p1[i]*k[i-1]%mo)%mo,mo-2);
assert(w!=0);
		k[i]=1ll*p3[i]*w%mo;b[i]=(1ll*p1[i]*b[i-1]+1)%mo*w%mo;
	}
	for(i=m-1;i>=0;--i)f[i]=(1ll*k[i]*f[i+1]+b[i])%mo;
//for(i=0;i<m;++i)printf("%d %lld\n",f[i],(1ll*p1[i]*(i?f[i-1]:0)+1ll*p2[i]*f[i]+1ll*p3[i]*f[i+1]+1)%mo);
	for(i=1;i<=n;++i)ans=(ans+f[a[i]])%mo;
	ans=(ans+1ll*(mo-(n-1))*f[0])%mo;
	ans=1ll*ans*poww(n,mo-2)%mo;
	printf("%d\n",ans);
}