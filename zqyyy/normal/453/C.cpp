#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
struct Edge{
	int to,nxt;
}e[N<<1];
int cnt,head[N];
inline void add_e(int from,int to){
	e[++cnt].to=to;
	e[cnt].nxt=head[from];
	head[from]=cnt;
}
int n,m,s,sum,ans[N<<2];
bool v[N],vis[N];
void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(!vis[y])dfs(y);
	}
}
void dfs1(int x,int fa){
	ans[++sum]=x,v[x]^=1,vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;if(vis[y])continue;
		dfs1(y,x),ans[++sum]=x,v[x]^=1;
	}
	if(v[x] && fa){
		ans[++sum]=fa,ans[++sum]=x;
		v[x]^=1,v[fa]^=1;
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add_e(x,y),add_e(y,x);
	}
	for(int i=1;i<=n;i++){
		v[i]=read();
		if(vis[i])continue;
		if(v[i]){
			if(s)puts("-1"),exit(0);
			s=i,dfs(i);
		}
	}
	if(!s)puts("0"),exit(0);
	memset(vis,0,sizeof(vis));
	dfs1(s,0);if(v[s])sum--;
	printf("%d\n",sum);
	for(int i=1;i<=sum;i++)printf("%d ",ans[i]);
	return 0;
}