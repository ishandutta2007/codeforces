#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=1<<25;
int n,i,x,y,f[N][2],ans=-inf;
vector<int>e[N];
void dfs(int x,int fa){
	for(int y:e[x])if(y!=fa)dfs(y,x);
	if(e[x].size()>1)for(int i=0;i<2;++i){
		int m1=-inf,m2=-inf,z=i?1:int(e[x].size())-2;
		for(int y:e[x])if(y!=fa && e[y].size()>1){
			int w=i?f[y][0]:max(f[y][0],f[y][1]);
			if(w>m1)m2=m1,m1=w;else m2=max(m2,w);
		}
		ans=max(ans,z+max(0,m1+max(m2,0)));
		if(!i)ans=max(ans,z+1+max(0,m1));
		f[x][i]=z+max(0,m1);
		if(!i)f[x][i]=max(f[x][i],z+1),ans=max(ans,z+2);
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	for(i=1;e[i].size()==1;++i);dfs(i,0);printf("%d\n",ans);
}