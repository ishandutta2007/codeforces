#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mo=1e9+7;
typedef long long ll;
inline int poww(int x,ll y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int n,k,i,j,l,x,ans;
int p[N/5],xb,phi[N],ps[N];
bool b[N];
int g[N];
int gfa(int x){
	return g[x]==x?x:g[x]=gfa(g[x]);
}
int main(){
	for(i=2;i<N;++i){
		if(!b[i])p[++xb]=i,phi[i]=i-1;
		for(j=1;j<=xb;++j){
			x=i*p[j];if(x>=N)break;
			b[x]=1;
			if(i%p[j]==0){
				phi[x]=phi[i]*p[j];
				break;
			}
			phi[x]=phi[i]*(p[j]-1);
		}
	}
	for(i=phi[1]=1;i<N;++i)ps[i]=(ps[i-1]+phi[i])%mo;
	scanf("%d%d",&n,&k);
	for(i=1;i<n;++i){
		int d=(n-1)/i;
		ans=(ans+1ll*poww(k,i)*(ps[d+1]-1))%mo;
		ans=(ans+mo-1ll*poww(k,(d+1)*i-n)*phi[d+1]%mo)%mo;
	}
	for(i=n;i<=n*2-2;++i)ans=(ans+1ll*poww(k,i-n)*(n*2-1-i))%mo;
	/*
	for(i=1;i<n;++i)for(j=1;j<n;++j){
		if(i+j-__gcd(i,j)<n){
			if(i+j>=n)printf("%d %d\n",i,j);
			ans=(ans+poww(k,__gcd(i,j)))%mo;
			if(i+j>=n && __gcd(i,j)!=n-(n-i)-(n-j)){
				++i,--i;
			}
		}
			else ans=(ans+poww(k,n-(n-i)-(n-j)))%mo;
		if(ans<0){
			++i,--i;
		}
		for(int k=1;k<=n;++k)g[k]=k;
		for(int k=1;k+i<=n;++k)g[gfa(k+i)]=gfa(k);
		for(int k=1;k+j<=n;++k)g[gfa(k+j)]=gfa(k);
		int v=1;
		for(l=1;l<=n;++l)if(gfa(l)==l)v=1ll*k*v%mo;
		ans=(ans+v)%mo;
	}
	*/
	ans=1ll*ans*poww(poww(k,n),mo-2)%mo;
	printf("%d\n",ans);
	return 0;
}