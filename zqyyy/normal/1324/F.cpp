#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N],f[N],g[N];
vector<int>G[N];
void dfs1(int x,int fa){
	for(auto y:G[x]){
		if(y==fa)continue;
		dfs1(y,x),f[x]+=max(f[y]+a[y],0);
	}
}
void dfs2(int x,int fa){
	for(auto y:G[x]){
		if(y==fa)continue;
		g[y]=a[y]+f[y]+max(g[x]-max(f[y]+a[y],0),0);
		dfs2(y,x);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()?1:-1;
	for(int i=1,x,y;i<n;i++){
		x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);
	}
	dfs1(1,0),g[1]=f[1]+a[1],dfs2(1,0);
	for(int i=1;i<=n;i++)printf("%d ",g[i]);
	return 0;
}