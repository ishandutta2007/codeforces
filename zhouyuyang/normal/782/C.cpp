#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm> 
#define N 200005
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],deg[N],co[N],x,y,n,ans,tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot; deg[x]++;
}
void dfs(int x,int c,int fa){
	co[x]=c;
	int p=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			p++;
			while (p==co[x]||p==co[fa]) p++;
			dfs(e[i].to,p,x);
		}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=n;i++) ans=max(ans,deg[i]+1);
	dfs(1,1,0);
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",co[i]); 
}