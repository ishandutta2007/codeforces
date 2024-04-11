#include<bits/stdc++.h>
#define maxn 301000
using namespace std;
typedef pair<int,int> par;
const int inf=1e9+7;
int n,m,ans=inf,a[maxn],tg[maxn],sz[maxn],dg[maxn],f[maxn],vis[maxn],pre[maxn],q[maxn],l,r;
vector<int>G[maxn];
void try4(){
	memset(vis,0,sizeof(vis));
	if(G[1].size()==0)return ;
	for(auto p:G[1])vis[p]=true;
	for(int a=2;a<n;++a)if(vis[a]==1)
		for(auto b:G[a])if(b!=1&&vis[b]==0){
			printf("4\n");
			printf("%d %d %d %d %d",1,a,b,1,n);
			exit(0);
		}
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	f[fy]=fx,sz[fx]+=sz[fy];
}
void try5(){
	memset(vis,0,sizeof(vis));
	if(G[1].size()==0)return ;
	int tp=0;
	for(auto p:G[1])vis[p]=1;
	for(int i=1;i<=n;++i)f[i]=i,sz[i]=1;
	for(int i=2;i<=n;++i)if(vis[i])a[++tp]=i;
	for(int i=1;i<=tp;++i)for(auto p:G[a[i]])if(p!=1)
		merge(a[i],p);
	for(int i=1;i<=tp;++i){
		int id=a[i],siz=0;
		for(auto p:G[id])if(p!=1)siz++,tg[p]=i;
		if(siz==sz[find(id)])continue;
		for(auto p:G[id])if(p!=1)
			for(auto q:G[p])if(q!=1&&q!=id&&tg[q]!=i){
					printf("5\n");
					printf("%d %d %d %d %d %d\n",1,id,p,q,id,n);
					exit(0);
				}
	}
}
void add(int u,int v){
	G[u].push_back(v),G[v].push_back(u);
}
int main(){
	scanf("%d%d",&n,&m);
//	n=600;
//	for(int i=1;i<n-1;++i)for(int j=i;j<(i==1?n:n-1);++j)if(i!=j)add(i,j);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),add(u,v);
	q[r++]=1,pre[1]=-1;
	while(l<r){
		int u=q[l++];
		for(auto p:G[u])if(!pre[p])
			pre[p]=u,q[r++]=p;
	}
	if(pre[n]){
		int sum=0,nw=n;
		while(pre[nw]!=-1)nw=pre[nw],sum++;
		ans=sum;
	}
	if(ans>4)try4();
	if(ans>5)try5();
	if(ans==inf)return puts("-1"),0;
	vector<int>seq;
	while(n!=-1)seq.push_back(n),n=pre[n];
	printf("%d\n",ans);
	reverse(seq.begin(),seq.end());
	for(auto p:seq)printf("%d ",p);
}