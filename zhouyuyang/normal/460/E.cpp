#include<bits/stdc++.h>
using namespace std;
int n,r,tot,ans,ord[10],id[10];
struct P{int x,y;}lzh[5000];
bool cmp(P a,P b){
	return a.x*a.x+a.y*a.y>b.x*b.x+b.y*b.y;
}
int dis(P a,P b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void dfs(int x,int bg,int v){
	if (x==n+1){
		if (ans>=v) return;
		for (int i=1;i<x;i++)
			id[i]=ord[i];
		ans=v;
		return;
	}
	for (int i=bg;i<=18&&i<=tot;i++){
		int tmp=v; ord[x]=i;
		for (int j=1;j<x;j++)
			tmp+=dis(lzh[i],lzh[ord[j]]);
		dfs(x+1,i,tmp);
	}
}
int main(){
	scanf("%d%d",&n,&r);
	for (int i=-r;i<=r;i++)
		for (int j=-r;j<=r;j++)
			if (i*i+j*j<=r*r)
				lzh[++tot]=(P){i,j};
	sort(lzh+1,lzh+tot+1,cmp);
	dfs(1,1,0);
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
		printf("%d %d\n",lzh[id[i]].x,lzh[id[i]].y);
}