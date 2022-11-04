#include<bits/stdc++.h>
using namespace std;
const int N=300005;
vector<int> e[N];
int n,m,tot,be[N];
int sz[N],cnt[N];
int from[N],dis[N],q[N];
void bfs(int S){
	memset(from,-1,sizeof(from));
	memset(dis,66,sizeof(dis));
	int h=0,t=1; q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=0;i<e[x].size();i++)
			if (dis[e[x][i]]>1e9){
				dis[e[x][i]]=dis[x]+1;
				from[e[x][i]]=x;
				q[++t]=e[x][i];
			}
	}
}
void out(int x){
	if (from[x]!=-1) out(from[x]);
	printf("%d ",x);
}
void mark(int x){
	be[x]=tot;
	for (int i=0;i<e[x].size();i++)
		if (!be[e[x][i]]) mark(e[x][i]);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	bfs(1);
	if (dis[n]<=4){
		printf("%d\n",dis[n]);
		out(n);
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (dis[i]==2){
			puts("4");
			out(i);
			printf("1 %d",n);
			return 0;
		}
	tot=be[1]=1;
	for (int i=0;i<e[1].size();i++){
		tot++;
		if (!be[e[1][i]]) mark(e[1][i]);
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<e[i].size();j++)
			if (be[i]==be[e[i][j]]) cnt[be[i]]++;
	for (int i=1;i<=n;i++) sz[be[i]]++;
	for (int k=2;k<=tot;k++)
		if (cnt[k]<1ll*sz[k]*(sz[k]-1)){
			puts("5");
			printf("1 ");
			int ns=1;
			for (int i=1;i<=n;i++)
				if (be[i]==k){
					int deg=0;
					for (int j=0;j<e[i].size();j++)
						if (be[e[i][j]]==k) ++deg;
					if (deg!=sz[k]-1) ns=i;
				}
			e[1].clear();
			for (int i=2;i<=n;i++){
				vector<int> ne;
				for (int j=0;j<e[i].size();j++)
					if (e[i][j]!=1) ne.push_back(e[i][j]);
				e[i]=ne;
			}
			bfs(ns);
			for (int i=1;i<=n;i++)
				if (dis[i]==2){
					out(i);
					break;
				}
			printf("%d %d",ns,n);
			return 0;
		}
	puts("-1");
}