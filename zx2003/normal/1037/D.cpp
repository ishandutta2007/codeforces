#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,x,y,fa[N],i,bfn[N];
set<pair<int,int>>S;
vector<int>e[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	S.insert({0,1});bfn[1]=0;
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		if(S.empty() || !S.count({bfn[x],x}) || S.begin()->first!=bfn[x])break;
		S.erase({bfn[x],x});for(int y:e[x])if(y!=fa[x])fa[y]=x,S.insert({bfn[y]=i,y});
	}
	puts(i<=n?"No":"Yes");
}