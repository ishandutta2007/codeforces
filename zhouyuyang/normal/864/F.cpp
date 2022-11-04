#include<bits/stdc++.h>
using namespace std;
struct node{
	int s,k,w;
};
vector<node> q[3010];
int n,m,Q,x,y,z,head[3010],nex[3010],vet[3010],pre[3010],ans[400010],num,f[13][3010],u,t,id;
void add(int x,int y){
	vet[++num]=y; nex[num]=head[x]; head[x]=num;
}
void dfs(int v,int fa){
	for (int i=head[v];i;i=nex[i])
	  if (vet[i]!=fa&&((!pre[vet[i]])||pre[vet[i]]>v)) pre[vet[i]]=v,dfs(vet[i],fa);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=m;i++) scanf("%d%d",&x,&y),add(y,x);
	for (int i=1;i<=Q;i++) scanf("%d%d%d",&x,&y,&z),q[y].push_back((node){x,z,i});
	for (int i=1;i<=n;i++)
	  if (q[i].size()){
	  	memset(pre,0,sizeof(pre));
	  	dfs(i,i);
	  	for (int j=1;j<=n;j++) f[0][j]=pre[j];
	  	for (int j=1;j<=12;j++)
	  	  for (int k=1;k<=n;k++) f[j][k]=f[j-1][f[j-1][k]];
 	    for (int j=0;j<q[i].size();j++){
 	    	u=q[i][j].s; t=q[i][j].k-1; id=q[i][j].w;
 	    	if ((!pre[u])||(f[12][u])){ans[id]=-1; continue;}
 	    	for (int k=0;t;t>>=1,k++)
				 if (t&1) u=f[k][u];
 	    	ans[id]=u?u:-1;
 	    }
	  }
  for (int i=1;i<=Q;i++) printf("%d\n",ans[i]);
}