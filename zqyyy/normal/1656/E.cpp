#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,dep[N],a[N];
vector<int>G[N];
inline void clear(){
	for(int i=1;i<=n;i++)G[i].clear();	
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1,a[x]=dep[x]&1?G[x].size():-G[x].size();
	for(int y:G[x])if(y^fa)dfs(y,x);	
}
inline void work(){
	n=read();
	for(int i=1,x,y;i<n;i++)x=read(),y=read(),G[x].push_back(y),G[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
}
int main(){
	int test=read();
	while(test--)work(),clear();
	return 0;
}