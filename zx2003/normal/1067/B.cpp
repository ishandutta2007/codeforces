#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,x,y,i;
vector<int>e[N];
int u,md,dad[N];
void dfs1(int x,int fa,int d){
	if(d>md)md=d,u=x;dad[x]=fa;
	for(int y:e[x])if(y!=fa)dfs1(y,x,d+1);
}
void E(){puts("No");exit(0);}
void dfs(int x,int fa,int dep){
	if(fa)e[x].erase(find(e[x].begin(),e[x].end(),fa));
	if(e[x].empty()){if(dep!=k)E();}else if(e[x].size()<3)E();
	for(int y:e[x])dfs(y,x,dep+1);
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	md=-1;dfs1(1,0,0);md=-1;dfs1(u,0,0);if(md!=k*2)E();
	for(x=u,i=k;i--;x=dad[x]);
	dfs(x,0,0);
	puts("Yes");
	return 0;
}