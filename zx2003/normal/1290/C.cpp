#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,i,j,c,x,ans;
char s[N];
vector<int>a[N];
int st[N*2][2],su[N*2][2],g[N*2];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
int W(int x){
	for(int i=0;i<2;++i)if(st[x][i])return su[x][i];
	return min(su[x][0],su[x][1]);
}
void uni(int x,int y,bool fl){
	x=gfa(x);y=gfa(y);if(x==y)return;
	if(fl)ans-=W(x)+W(y);
	g[x]=y;
	for(j=0;j<2;++j)st[y][j]|=st[x][j],su[y][j]+=su[x][j];
	if(fl)ans+=W(y);
}
int main(){
	scanf("%d%d%s",&m,&n,s+1);
	for(i=1;i<=n;++i){
		scanf("%d",&c);
		for(;c--;)scanf("%d",&x),a[x].push_back(i);
	}
	for(i=1;i<=n*2;++i)g[i]=i,su[i][i<=n]=1;
	for(i=1;i<=m;++i){
		sort(a[i].begin(),a[i].end());
		a[i].erase(unique(a[i].begin(),a[i].end()),a[i].end());
		if(a[i].size()==1){
			int x=gfa(a[i][0]);
			ans-=W(x);
			if(s[i]=='0')st[x][1]=st[gfa(a[i][0]+n)][0]=1;else st[x][0]=st[gfa(a[i][0]+n)][1]=1;
			ans+=W(x);
		}else if(a[i].size()==2){
			int x=a[i][0],y=a[i][1];
			if(s[i]=='1')uni(x,y,1),uni(x+n,y+n,0);
				else uni(x+n,y,1),uni(x,y+n,0);
		}
		printf("%d\n",ans);
	}
	return 0;
}