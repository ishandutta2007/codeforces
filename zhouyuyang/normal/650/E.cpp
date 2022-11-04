#include<bits/stdc++.h> 
#define N 500005
using namespace std;
struct Ans{int a,b,c,d;}ans[N];
int n,x,y,cnt,f[N],fa[2][N];
vector<int> e[2][N];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
void dfs(int id,int x,int f){
	for (int i=0;i<e[id][x].size();i++)
		if (e[id][x][i]!=f){
			fa[id][e[id][x][i]]=x;
			dfs(id,e[id][x][i],x);
		}
}
void dfs2(int x){
	for (int i=0;i<e[0][x].size();i++)
		if (e[0][x][i]!=fa[0][x]){
			int u=e[0][x][i];
			dfs2(u);
			if (u!=fa[1][x]&&x!=fa[1][u])
				ans[++cnt]=(Ans){u,x,get(u),fa[1][get(u)]};
		}
}
int main(){
	scanf("%d",&n);
	for (int id=0;id<2;id++)
		for (int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			e[id][x].push_back(y);
			e[id][y].push_back(x);
		}
	dfs(0,1,0);
	dfs(1,1,0);
	f[1]=1;
	for (int i=2;i<=n;i++){
		int u=fa[1][i];
		if (fa[0][i]==u||fa[0][u]==i)
			f[i]=u;
		else f[i]=i;
	}
	dfs2(1);
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
		printf("%d %d %d %d\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d);
}