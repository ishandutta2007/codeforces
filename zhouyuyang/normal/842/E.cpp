#include<bits/stdc++.h>
#define N 300005
using namespace std;
int n,D,fa[N][20],dep[N];
vector<int> p1,p2;
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for (int i=0;i<=19;i++,tmp/=2)
		if (tmp&1) x=fa[x][i];
	for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void work(int x){
	if (p1.size()&&dis(x,p1[0])>D){
		++D;
		for (int i=0;i<p2.size();i++)
			if (dis(p2[i],x)==D) p1.push_back(p2[i]);
		p2.clear(); p2.push_back(x);
	}
	else if (p2.size()&&dis(x,p2[0])>D){
		++D;
		for (int i=1;i<p1.size();i++)
			if (dis(p1[i],x)==D) p2.push_back(p1[i]);
		p1.clear(); p1.push_back(x);
	}
	else if (p1.size()&&dis(x,p1[0])==D) p2.push_back(x);
	else if (p2.size()&&dis(x,p2[0])==D) p1.push_back(x);
}
int main(){
	scanf("%d",&n);
	p1.push_back(1);
	D=0;
	for (int i=2;i<=n+1;i++){
		int x; scanf("%d",&x);
		dep[i]=dep[x]+1; fa[i][0]=x;
		for (int j=1;j<=19;j++)	
			fa[i][j]=fa[fa[i][j-1]][j-1];
		work(i);
		printf("%d\n",p1.size()+p2.size());
	}
}