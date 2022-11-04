#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7; 
struct data{int to,next;}e[N<<1];
int mn=N,c[N],cnt,head[N],fa[N],used[N],op,x,y,last,n,m,i;
void ins(int u,int v){
    e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
}
void insert(int u,int v){
    ins(u,v);ins(v,u);
}
void dfs(int x,int ans){
	c[x]=min(ans,x);
	for(int i=head[x];i;i=e[i].next)
	    if(e[i].to!=fa[x])
	        fa[e[i].to]=x,dfs(e[i].to,c[x]);
}
int main(){
	for(scanf("%d%d",&n,&m),i=1;i<n;++i)
	    scanf("%d%d",&x,&y),insert(x,y);
	for(scanf("%d%d",&op,&x),x=(x+last)%n+1,dfs(x,x),used[x]=1,m--;m--;){
		scanf("%d%d",&op,&x);x=(x+last)%n+1;
		if(op==1)for(;!used[x];x=fa[x])used[x]=1,mn=min(mn,x);
		else printf("%d\n",last=min(mn,c[x]));
	}
}