#include<bits/stdc++.h>
#define pa pair<ll,int>
#define ll long long
#define N 200005
using namespace std;
struct edge{int to,next,v;}e[N];
int head[N],vis[N];
int n,m,que,tot;
ll dis[N],d[N];
priority_queue<pa > q;
queue<int> Q[N];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void dijkstra(){
	for (int i=1;i<=n;i++)
		dis[i]=2e16,vis[i]=0;
	dis[1]=0; q.push(pa(0,1));
	while (!q.empty()){
		int x=q.top().second; q.pop();
		if (vis[x]) continue; vis[x]=1;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v){
				dis[e[i].to]=dis[x]+e[i].v;
				q.push(pa(-dis[e[i].to],e[i].to));
			}
	}
}
void change(){
	int s; scanf("%d",&s);
	while (s--){
		int x; scanf("%d",&x);
		e[x].v++;
	}
	for (int i=1;i<=n;i++){
		d[i]=min(dis[i]+n+1,(ll)2e16),
		vis[i]=0;
	}
	int h=0,t=1;
	d[1]=0; Q[0].push(1);
	for (int i=0;i<=n;i++)
		while (!Q[i].empty()){
			int x=Q[i].front(); Q[i].pop();
			if (vis[x]) continue; vis[x]=1;
			for (int j=head[x];j;j=e[j].next)
				if (d[e[j].to]>d[x]+e[j].v){
					d[e[j].to]=d[x]+e[j].v;
					Q[d[e[j].to]-dis[e[j].to]].push(e[j].to);
				}
		}
	for (int i=1;i<=n;i++)
		dis[i]=d[i];
}
int main(){
	scanf("%d%d%d",&n,&m,&que);
	for (int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v);
	}
	dijkstra();
	while (que--){
		int tp;
		scanf("%d",&tp);
		if (tp==2) change();
		else{
			int x; scanf("%d",&x);
			printf("%lld\n",dis[x]<1e16?dis[x]:-1);
		}
	}
}