#include<bits/stdc++.h>
#define maxn 10010
using namespace std;
typedef long long ll;
const ll M=(ll)1e9;
struct edge{
	int r,nxt;
	ll w;
}e[maxn<<1];
ll deg[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
int fr[maxn],to[maxn],n,m;
int q[maxn],l,r,cur[maxn],dep[maxn],head[maxn],esz,S,T;
void addedge(int u,int v,ll w){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;e[esz].w=w;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;e[esz].w=0;
}
bool bfs(){
	for(int i=S;i<=T;++i)cur[i]=head[i],dep[i]=0;
	l=r=0,q[r++]=S,dep[S]=1;
	while(l<r){
		int u=q[l++];
		for(int t=head[u];t;t=e[t].nxt)if(e[t].w&&!dep[e[t].r])
			dep[e[t].r]=dep[u]+1,q[r++]=e[t].r;
	}
	return dep[T]!=0;
}
ll find(int u,ll flow){
	if(u==T)return flow;
	ll used=0,a=0;
	for(int& t=cur[u];t;t=e[t].nxt)if(e[t].w&&dep[e[t].r]==dep[u]+1){
		a=find(e[t].r,min(flow-used,e[t].w));
		used+=a,e[t].w-=a,e[t^1].w+=a;
		if(flow==used)return used;
	}
	return used;
}
ll dinic(){
	ll ans=0,a;
	while(bfs())ans+=find(S,1ll<<60);//,printf("[%.9lf]\n",a);
	return ans;
}
ll sol(ll t){
	ll sum=0;
	esz=1,S=0,T=n+1;
	for(int i=S;i<=T;++i)head[i]=deg[i]=0;
	for(int i=1;i<=m;++i){
		ll l=a[i]*t+b[i],r=c[i]*t+d[i];
		deg[to[i]]+=l;
		deg[fr[i]]-=l;
//		addedge(S,to[i],l);
//		addedge(fr[i],T,l);
		addedge(fr[i],to[i],r-l);
//		sum+=l;
	}
	for(int i=1;i<=n;++i)
		if(deg[i]>0)sum+=deg[i],addedge(S,i,deg[i]);
		else addedge(i,T,-deg[i]);
	return sum-dinic();
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
	//	fr[i]=rand()%n+1,to[i]=rand()%n+1;
	//	while(fr[i]==to[i])fr[i]=rand()%n+1,to[i]=rand()%n+1;
	//	a[i]=rand()%20,b[i]=rand()%20,c[i]=rand()%20,d[i]=rand()%20+a[i]+c[i];
		scanf("%d%d%lld%lld%lld%lld",&fr[i],&to[i],&a[i],&b[i],&c[i],&d[i]);
		b[i]*=M,d[i]*=M;
	}
	ll l=0,r=M;
	for(int i=0;r-l>3;++i){
		ll mid1=(l+l+r)/3,mid2=(l+r+r)/3;
		ll f1=sol(mid1),f2=sol(mid2);
		//printf("[%lld,%lld]",f1,f2);
		if(f1>f2)l=mid1;
		else r=mid2;
	}
	ll l1=0,r1=l;
	for(int i=0;l1<r1;++i){
		ll mid=(l1+r1)/2;
		if(sol(mid)==0)r1=mid;
		else l1=mid+1;
	}
	ll l2=l,r2=M;
	for(int i=0;l2<r2;++i){
		ll mid=(l2+r2)/2;
		if(sol(mid)==0)l2=mid+1;
		else r2=mid;
	}
//	printf("[%.10lf,%.10lf]",sol(0),sol(1));
	printf("%.10lf",(double)(l2-l1)/(double)M);
}