#include<bits/stdc++.h>
using namespace std;
const int N=50005,blk=256;
struct edge{int to,next;}e[N*2];
int head[N],dep[N],fa[N];
int anc[N],a[N],f[N][blk+1];
int n,q,tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			dep[e[i].to]=dep[x]+1;
			fa[e[i].to]=x;
			dfs(e[i].to);
		}
	if (dep[x]>=256){
		int cur=x,v;
		for (int i=0;i<blk;i++){
			v=(a[cur]^i)>>8;
			f[x][v^255]=max(f[x][v^255],(255<<8)|(i^a[cur]));
			cur=fa[cur];
		}
		anc[x]=cur;
		for (int j=0;j<=7;j++)
			for (int i=0;i<blk;i++)
				if (f[x][i]==-1&&f[x][i^(1<<j)]!=-1)
					f[x][i]=f[x][i^(1<<j)]^(blk<<j);
	}
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dep[1]=1;
	dfs(1);
	while (q--){
		int x,y,t,cur,ans=0;
		scanf("%d%d",&x,&y);
		t=dep[y]-dep[x]+1,cur=y;
		for (int i=0;i<t/blk;i++)
			ans=max(ans,f[cur][i]),cur=anc[cur];
		for (int i=t/blk*blk;i<t;i++)
			ans=max(ans,a[cur]^i),cur=fa[cur];
		printf("%d\n",ans);
	}
}