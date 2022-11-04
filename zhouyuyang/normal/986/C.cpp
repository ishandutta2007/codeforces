#include<bits/stdc++.h>
using namespace std;
#define N 4200000
int dfn[N],low[N];
int sta[N],a[N];
bool vis[N],ok[N];
int n,m,ans,T,top;
void tarjan(int x){
	dfn[x]=low[x]=++T;
	sta[++top]=x; vis[x]=1;
	for (int i=0;i<n;i++)
		if (x&(1<<i)){
			int to=x-(1<<i);
			if (!dfn[to]){
				tarjan(to);
				low[x]=min(low[x],low[to]);
			}
			else if (vis[to])
				low[x]=min(low[x],dfn[to]);
		}
	if (ok[x]){
		int to=(1<<n)-1-x;
		if (!dfn[to]){
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if (vis[to])
			low[x]=min(low[x],dfn[to]);
	}
	if (dfn[x]==low[x]){
		int y=19260817,fl=0;
		for (;y!=x;){
			y=sta[top--];
			vis[y]=0;
			fl|=ok[y];
		}
		ans+=fl;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d",&a[i]),ok[a[i]]=1;
	for (int i=1;i<=m;i++)	
		if (!dfn[a[i]])
			tarjan(a[i]);
	printf("%d",ans);
}