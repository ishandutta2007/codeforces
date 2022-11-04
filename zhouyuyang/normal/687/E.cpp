#include<bits/stdc++.h>
#define N 5005
using namespace std;
struct edge{
	int to,next;
}e[N];
int head[N],tot;
int sta[N],top,blk;
int vis[N],be[N];
int dfn[N],low[N],T;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void tarjan(int x){
	sta[++top]=x; vis[x]=1;
	dfn[x]=low[x]=++T;
	for (int i=head[x];i;i=e[i].next)
		if (!dfn[e[i].to]){
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if (vis[e[i].to])
			low[x]=min(low[x],dfn[e[i].to]);
	if (dfn[x]==low[x]){
		blk++;
		int y=23333333;
		for (;y!=x;){
			y=sta[top--];
			vis[y]=0; be[y]=blk;
		}
	}
}
int dis[N],q[N];
int calc(int S){
	memset(dis,-1,sizeof(dis));
	int h=0,t=1; q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1){
				dis[e[i].to]=dis[x]+1;
				q[++t]=e[i].to;
			}
			else if (e[i].to==S)
				return dis[x]+1;
	}
	return 0;
}
int w[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]) tarjan(i);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
		for (int j=head[i];j;j=e[j].next)
			if (be[i]!=be[e[j].to]) vis[be[i]]=1;
	memset(w,110,sizeof(w));
	for (int i=1;i<=n;i++)
		w[be[i]]=min(w[be[i]],calc(i));
	int ans=n;
	for (int i=1;i<=blk;i++)
		if (!vis[i]&&w[i])
			ans+=1+w[i]*998;
	printf("%d",ans);
}