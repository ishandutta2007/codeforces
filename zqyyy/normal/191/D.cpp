#include <bits/stdc++.h>
using namespace std;
inline char gc(){
	static char buf[500001],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,500000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int f=1,r=0;char c=gc();
	while(!isdigit(c))f^=c=='-',c=gc();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=gc();
	return f?r:-r;
}
const int N=1e5+7,M=3e5+7;
struct Edge{int to,nxt;}e[M<<1];
int s_e=1,head[N];
inline void add_e(int x,int y){
	e[++s_e]={y,head[x]},head[x]=s_e;
}
bool vis[N],ins[N];
int n,m,ans,fa[N],deg[N];
void dfs(int x,int in){
	vis[x]=ins[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		if(i==(in^1))continue;
		int y=e[i].to;
		if(!vis[y])fa[y]=x,dfs(y,i);
		else if(ins[y]){
			int u=x,sum=deg[x]>2;
			while(u^y)u=fa[u],sum+=deg[u]>2;
			if(sum<2)ans++;
		}
	}
	ins[x]=0;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add_e(x,y),add_e(y,x),deg[x]++,deg[y]++;
	}
	for(int i=1;i<=n;i++)ans+=deg[i]&1;
	ans>>=1,dfs(1,0);
	printf("%d %d\n",ans,m);
	return 0;
}