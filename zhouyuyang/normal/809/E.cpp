#include<bits/stdc++.h>
#define mo 1000000007
#define N 200005
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],val[N],mu[N],phi[N];
int A[N],B[N],vis[N],sz[N],pri[N];
int sum0[N],sum1[N],sta[N*50];
int n,tot,cen,mn,fcen,s,ans;
vector<int> v[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	mu[1]=phi[1]=1;
	for (int i=2;i<=n;i++){
		if (!vis[i]){
			pri[++*pri]=i;
			mu[i]=mo-1;
			phi[i]=i-1;
		}
		for(int j=1;j<=*pri&&i*pri[j]<=n;j++){
			vis[i*pri[j]]=1;
			if (i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				mu[i*pri[j]]=0;
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
			mu[i*pri[j]]=mo-mu[i];
		}
	}
	for (int i=1;i<=n;i++){
		B[i]=1ll*i*power(phi[i],mo-2)%mo;
		for (int j=1;i*j<=n;j++){
			A[i*j]=(A[i*j]+1ll*mu[j]*B[i])%mo;
			v[i*j].push_back(i);
		}
	}
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void find(int x,int fa,int n){
	sz[x]=1;
	int tmp=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			find(e[i].to,x,n);
			sz[x]+=sz[e[i].to];
			tmp=max(tmp,sz[e[i].to]);
		}
	tmp=max(tmp,n-sz[x]);
	if (tmp<mn)
		mn=tmp,cen=x,fcen=fa;
}
void Que(int n,int dis){
	int tmp=0;
	for (int i=0;i<v[n].size();i++){
		int d=v[n][i];
		tmp=(tmp+1ll*A[d]*sum0[d]%mo*dis)%mo;
		tmp=(tmp+1ll*A[d]*sum1[d])%mo;
	}
	ans=(ans+1ll*tmp*phi[n])%mo;
}
void Ins(int n,int dis){
	for (int i=0;i<v[n].size();i++){
		int d=v[n][i]; sta[++s]=d;
		sum0[d]=(sum0[d]+phi[n])%mo;
		sum1[d]=(sum1[d]+1ll*phi[n]*dis)%mo;
	}
}
void dfsQ(int x,int fa,int d){
	Que(val[x],d);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to])
			dfsQ(e[i].to,x,d+1);
}
void dfsI(int x,int fa,int d){
	Ins(val[x],d);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to])
			dfsI(e[i].to,x,d+1);
}
void solve(int x,int n){
	mn=1e9;
	find(x,-1,n);
	vis[x=cen]=1;
	if (~fcen)
		sz[fcen]=n-sz[x];
	Ins(val[x],0);
	for (int i=head[x];i;i=e[i].next){
		if (vis[e[i].to]) continue;
		dfsQ(e[i].to,x,1),dfsI(e[i].to,x,1);
	}
	for (;s;s--) sum0[sta[s]]=sum1[sta[s]]=0;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to])
			solve(e[i].to,sz[e[i].to]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	init();
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	memset(vis,0,sizeof(vis));
	solve(1,n);
	printf("%d",1ll*ans*power(1ll*n*(n-1)/2%mo,mo-2)%mo);
}