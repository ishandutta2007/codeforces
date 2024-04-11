#include<bits/stdc++.h>
#define ttt 18
using namespace std;
int n,fa[100100][ttt+2]={0},dep[520233]={0},m,a,b,c,ab,ac,bc,da,db,dc;
vector<int>r[520233];

void dfs(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for (int i=1;i<=ttt;i++){
		if (dep[x]<=(1<<i)) break;
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	int y;
	for (int i=0;i<r[x].size();i++){
		y=r[x][i];
		if (y==f) continue;
		dfs(y,x);
	}
}

int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=ttt;i>=0;i--){
		if ((dep[x]-(1<<i))>=dep[y]){
			x=fa[x][i];
		}
	}
	if (x==y) return x;
	for (int i=ttt;i>=0;i--){
		if (fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}

int main(){
	scanf("%d%d",&n,&m);
	int x;
	for (int i=2;i<=n;i++){
		scanf("%d",&x);
		r[x].push_back(i);
		r[i].push_back(x);
	}
	dfs(1,0);
	
	int mx,t;
	while (m--){
		scanf("%d%d%d",&a,&b,&c);
		ab=lca(a,b);
		ac=lca(a,c);
		bc=lca(b,c);
		//printf(" %d(%d) %d(%d) %d(%d)\n",ab,dep[ab],ac,dep[ac],bc,dep[bc]);
		
		mx=0;
		
		if (dep[ab]>=max(dep[ac],dep[bc])){
			da=dep[a]-dep[ab]+1;
			db=dep[b]-dep[ab]+1;
			dc=dep[c]-dep[ac]+dep[ab]-dep[ac]+1;
		}else if(dep[ac]>=max(dep[ab],dep[bc])){
			da=dep[a]-dep[ac]+1;
			dc=dep[c]-dep[ac]+1;
			db=dep[b]-dep[bc]+dep[ac]-dep[bc]+1;
		}else{
			db=dep[b]-dep[bc]+1;
			dc=dep[c]-dep[bc]+1;
			da=dep[a]-dep[ab]+dep[bc]-dep[ab]+1;
		}
		
		mx=max(da,max(db,dc));
		printf("%d\n",mx);
	}
}