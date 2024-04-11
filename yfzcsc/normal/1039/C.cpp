#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 501000
using namespace std;
struct edge{
	int u,v;
	long long w;
}e[maxn];
int f[maxn],n,m;
long long k,c[maxn];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	k=(1ll<<k)-1;
	for(int i=1;i<=n;++i)scanf("%lld",&c[i]);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(c[u]==c[v])return puts("0"),0;
		e[i]=edge{u,v,c[u]^c[v]};
	}
	sort(e+1,e+m+1,[](edge a,edge b){return a.w<b.w;});
	for(int i=1;i<=n;++i)f[i]=i;
	int ans=0,cnt=n,use=0;
	for(int i=1,j;i<=m;i=j){
		use++;
		for(j=i;j<=m&&e[j].w==e[i].w;++j){
			if(find(e[j].u)!=find(e[j].v))cnt--;
			f[find(e[j].u)]=find(e[j].v);
		}
		if(e[i].w<=k)ans=(ans+qpow(2,cnt))%mod;
		for(j=i;j<=m&&e[j].w==e[i].w;++j){
			f[e[j].u]=e[j].u;
			f[e[j].v]=e[j].v;
		}
		cnt=n;
	}
	ans=(ans+1ll*qpow(2,n)*((k+1-use)%mod))%mod;
	printf("%d",ans);
}