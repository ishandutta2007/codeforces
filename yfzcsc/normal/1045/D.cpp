#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef double ldb;
int q,n,fa[maxn],dg[maxn],fr[maxn],to[maxn];
ldb sum[maxn],dp[maxn][2],pi[maxn];
vector<int>G[maxn],nG[maxn];
void dfs(int u,int f){
	fa[u]=f;
	for(auto v:G[u])if(v!=f)dfs(v,u);
}
ldb cal(){
	ldb ans=1-pi[1];
	for(int i=2;i<=n;++i)
		ans-=pi[fr[i]]*pi[to[i]];
	for(int i=1;i<=n;++i)
		ans+=(dg[i]-1)*pi[i];
	return ans;
}
int main(){
//	n=1000;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
//		pi[i]=rand()%10/10.0;
		scanf("%lf",&pi[i]);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		u++,v++;
//		u=rand()%(i-1)+1,v=i;
		dg[u]++,dg[v]++;
		G[u].push_back(v);
		G[v].push_back(u);
		fr[i]=u,to[i]=v;
	}
	int B=sqrt(n)+1;
	for(int i=1;i<=n;++i)
		for(auto c:G[i])if(dg[c]<=B)
			sum[i]+=pi[c];
	for(int i=1;i<=n;++i)
		for(auto c:G[i])
			if(dg[c]>B)nG[i].push_back(c);
	dg[1]++;
	ldb ans=cal();
//	printf("[%.10lf]",ans);
	scanf("%d",&q);
//q=1000;
	while(q--){
		int x;
		ldb p;
		scanf("%d%lf",&x,&p);
//x=rand()%n,p=rand()%10/10.0;
		x++;
		ans-=(dg[x]-1)*pi[x];
		ans+=(dg[x]-1)*p;
		if(x==1){
			ans-=1-pi[x];
			ans+=1-p;
		}
		if(dg[x]<=B){
//			puts("OK");
			for(auto c:G[x])
				ans+=pi[x]*pi[c],ans-=p*pi[c],
				sum[c]-=pi[x],sum[c]+=p;
		} else {
			for(auto c:nG[x])
				ans+=pi[x]*pi[c],ans-=p*pi[c];
			ans+=sum[x]*pi[x],ans-=sum[x]*p;
		}
		pi[x]=p;
//		printf("[%.10lf]",cal());
		printf("%.10lf\n",ans);
	}
}