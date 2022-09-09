#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,mo=998244353;
int n,x,y,i,f[N][3],ans;//0 empty,1 matched,2 need to match
vector<int>e[N];
void dfs(int x,int fa){
	int f0=1,f1=0,f2=0;
	for(int y:e[x])if(y!=fa){
		dfs(y,x);
		int of0=f0,of1=f1,of2=f2;
		f0=1ll*(f[y][0]+f[y][1])*of0%mo;
		f1=((f[y][0]+2ll*f[y][1])*of1+1ll*(of0+of2)*(f[y][0]+f[y][2]))%mo;
		f2=(1ll*(f[y][0]+f[y][1])*of2+1ll*f[y][1]*(of0+of2))%mo;
	}
	f[x][0]=f0;f[x][1]=f1;f[x][2]=f2;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	printf("%d\n",(f[1][0]+f[1][1])%mo);
	return 0;
}