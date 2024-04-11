#include <bits/stdc++.h>
#define time __time__
using namespace std;
const int N=600005,M=N*2;
struct Gragh{
	int cnt,x[M],y[M],nxt[M],fst[N];
	void clear(){
		cnt=1;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,x[cnt]=a,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g,g2;
int n,m;
int flag[M];
int vis[N],st[N],in[N],dfn[N],low[N],bh[N],ans,time,top;
void Tarjan(int x){
	dfn[x]=low[x]=++time;
	st[++top]=x;
	in[x]=vis[x]=1;
	for (int i=g.fst[x];i;i=g.nxt[i]){
		if (flag[i/2])
			continue;
		flag[i/2]=1;
		if (!vis[g.y[i]]){
			Tarjan(g.y[i]);
			low[x]=min(low[x],low[g.y[i]]);
		}
		else if (in[g.y[i]])
			low[x]=min(low[x],low[g.y[i]]);
	}
	if (dfn[x]==low[x]){
		ans++;
		in[st[top]]=0;
		bh[st[top]]=ans;
		while (st[top--]!=x){
			in[st[top]]=0;
			bh[st[top]]=ans;
		}
	}
}
int q[N],head,tail;
int depth[N];
int findfar(int s){
	head=tail=0;
	memset(depth,0,sizeof depth);
	depth[s]=1;
	q[++tail]=s;
	while (head<tail){
		int x=q[++head];
		for (int i=g2.fst[x];i;i=g2.nxt[i])
			if (depth[g2.y[i]]==0){
				depth[g2.y[i]]=depth[x]+1;
				q[++tail]=g2.y[i];
			}
	}
	return q[tail];
}
int main(){
	scanf("%d%d",&n,&m);
	g.clear();
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g.add(x,y),g.add(y,x);
	}
	Tarjan(1);
	g2.clear();
	for (int i=1;i<=g.cnt;i++)
		if (bh[g.x[i]]!=bh[g.y[i]])
			g2.add(bh[g.x[i]],bh[g.y[i]]);
	int p=findfar(1);
	int k=findfar(p);
	printf("%d",depth[k]-1);
	return 0;
}