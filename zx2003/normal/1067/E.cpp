#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,mo=998244353;
int n,x,y,i,ans;
vector<int>e[N];
int f[N][2],sz[N],mi[N];
void dfs(int x,int fa){
	int v0=1,v1=0;
	sz[x]=1;
	for(int y:e[x])if(y!=fa){
		dfs(y,x);sz[x]+=sz[y];
		v1=(2ll*(f[y][0]+f[y][1])*v1+1ll*f[y][1]*v0)%mo;
		v0=(2ll*f[y][0]+f[y][1])*v0%mo;
	}
	ans=(ans+2ll*v1*mi[n-sz[x]])%mo;
	f[x][0]=v1;f[x][1]=v0;
}
int main(){
	for(i=*mi=1;i<N;++i)mi[i]=2*mi[i-1]%mo;
	scanf("%d",&n);for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}