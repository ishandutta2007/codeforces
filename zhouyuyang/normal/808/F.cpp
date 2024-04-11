#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 1e9
using namespace std;
int n,k,S,T,tot,flow;
int head[105],dis[105],q[105];
struct edge{int to,next,f;}e[20005];
int a[105],b[105],c[105],fl[200005];
void add(int x,int y,int z){
	e[++tot]=(edge){y,head[x],z};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	int h=0,t=1,x;
	for (int i=1;i<=T;i++) dis[i]=-1;
	dis[S]=0; q[1]=S;
	while (h!=t){
		x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f)
				dis[e[i].to]=dis[x]+1,q[++t]=e[i].to;
	}
	return dis[T]!=-1;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int rest=flow,k;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			rest-=k; e[i].f-=k; e[i^1].f+=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for (int i=2;i<=100000;i++)
		for (int j=i+i;j<=200000;j+=i)
			fl[j]=1;
	int l=1,r=n+1,mid,ans;
	S=n+1,T=n+2;
	while (l<=r){
		mid=(l+r)/2;
		memset(head,0,sizeof(head));
		tot=1,flow=0;
		int mx=-1,pos=-1;
		for (int i=1;i<=n;i++)
			if (c[i]<=mid&&b[i]==1&&a[i]>mx)
				mx=a[i],pos=i;
		for (int i=1;i<=n;i++)
			if (c[i]<=mid){
				if (b[i]==1&&pos!=i) continue;
				flow+=a[i];
				if (b[i]&1){
					add(S,i,a[i]);
					for (int j=1;j<=n;j++)
						if (c[j]<=mid&&!(b[j]&1)&!fl[b[i]+b[j]])
							add(i,j,inf);
				}
				else add(i,T,a[i]);
			}
		while (bfs()) flow-=dfs(S,inf);
		if (flow>=k) r=mid-1,ans=mid;
		else l=mid+1;
	}
	if (l>n) printf("-1");
	else printf("%d",ans);
}