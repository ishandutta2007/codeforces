#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,x,y,i,s[2],ans1,ans2;
vector<int>e[N];
void dfs(int x,int fa,int d){
	if(e[x].size()==1)++s[d];
	int lc=0;
	for(int y:e[x])if(y!=fa)dfs(y,x,d^1),lc+=e[y].size()==1;
	if(lc>1)ans2-=lc-1;
}
int main(){
	scanf("%d",&n);
	ans2=n-1;
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	for(i=1;i<=n;++i)if(e[i].size()>1)break;dfs(i,0,0);
	ans1=s[0] && s[1]?3:1;
	printf("%d %d\n",ans1,ans2);
}