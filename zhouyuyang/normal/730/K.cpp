#include<bits/stdc++.h>
#define pa pair<int,int>
#define M 2000005
#define N 400005
using namespace std;
int n,m,S,T;
int head[N],tot;
struct edge{
	int to,next;
}e[M];
int par[N],f[N];
int dep[N],lnk[N];
vector<int> cir[N];
int dir[M];
pa q[M];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int id){
	for (int i=head[x];i;i=e[i].next)
		if (i^id^1)
			if (!dep[e[i].to]){
				dep[e[i].to]=dep[x]+1;
				par[e[i].to]=x; lnk[x]=e[i].to;
				f[e[i].to]=i>>1;
				dfs(e[i].to,i);
			}
			else if (dep[e[i].to]<dep[x])
				cir[lnk[e[i].to]].push_back(i>>1);
}
void Main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for (int i=1;i<=n;i++){
		dep[i]=head[i]=0;
		par[i]=f[i]=lnk[i]=0;
		cir[i].clear();
	}
	for (int i=1;i<=m;i++)
		dir[i]=-1;
	tot=1; dep[S]=1;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(S,0);
	if (!dep[T]){
		puts("No");
		return;
	}
	int h=0,t=1;
	q[t]=pa(T,0);
	while (h!=t){
		int x=q[++h].first;
		int d=q[h].second;
		for (;par[x]&&dir[f[x]]==-1;x=par[x]){
			dir[f[x]]=d;
			for (auto i:cir[x]){
				dir[i]=d;
				if (e[i*2].to==par[x])
					q[++t]=pa(e[i*2+1].to,d^1);
				else q[++t]=pa(e[i*2].to,d^1);
			}
		}
	}
	for (int i=1;i<=m;i++)
		if (dir[i]==-1){
			//printf("%d\n",i);
			puts("No");
			return;
		}
	puts("Yes");
	for (int i=1;i<=m;i++)
		if (dir[i]^(dep[e[i*2].to]<dep[e[i*2+1].to]))
			printf("%d %d\n",e[i*2].to,e[i*2+1].to);
		else printf("%d %d\n",e[i*2+1].to,e[i*2].to);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) Main();
}