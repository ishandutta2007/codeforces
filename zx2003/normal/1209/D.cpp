#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,x,y,i,ans;
bool vi[N];
vector<pair<int,int>>e[N];
void dfs(int u,int fa){
	vi[u]=1;
	for(auto z:e[u])if(z.second!=fa){
		if(!vi[z.first])dfs(z.first,z.second);
			else ++ans;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;++i)scanf("%d%d",&x,&y),e[x].push_back(make_pair(y,i)),
		e[y].push_back(make_pair(x,i));
	for(i=1;i<=n;++i)if(!vi[i])dfs(i,0);
	printf("%d\n",ans/2);
	return 0;
}