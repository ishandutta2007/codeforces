#include<bits/stdc++.h>

#define maxn 100100
using namespace std;
struct edge{
	int r,nxt;
}e[maxn<<1];
int head[maxn],esz,col[maxn],dp[maxn],ans;
void dfs1(int u,int f){
	dp[u]=col[u];
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f){
		dfs1(e[t].r,u);
		if(dp[e[t].r]!=col[u])dp[u]=-1;
	}	
}
void dfs2(int u,int f,int col){
//	printf("[%d,%d,%d]",u,f,col);
	int has=0,v=0;
	for(int t=head[u];t;t=e[t].nxt)
		if(e[t].r!=f&&dp[e[t].r]==-1)has++,v=e[t].r;
	if(!has){printf("YES\n%d\n",u);return ;}
	else if(has>=2){printf("NO\n");return ;}
	for(int t=head[u];t;t=e[t].nxt)
		if(e[t].r!=f&&e[t].r!=v){
			if(col&&dp[e[t].r]!=col){printf("NO\n");return ;}
			else col=dp[e[t].r];
		}
	if(col&&::col[u]!=col){printf("NO\n");return ;}
	else col=::col[u];
	dfs2(v,u,col);		
}
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<n;++i){
		int u,v;scanf("%d%d",&u,&v);
		e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
		e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
	}
	for(int i=1;i<=n;++i)scanf("%d",&col[i]);
	dfs1(1,0);
	dfs2(1,0,0);
}