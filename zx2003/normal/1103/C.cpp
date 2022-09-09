#include<bits/stdc++.h>
using namespace std;
const int N=250005;
int n,m,k,u,v,w,i,j;
vector<int>e[N],e2[N],leaf;
int dep[N],dad[N],md;
void dfs(int x,int fa){
	int ch=0;md=max(md,dep[x]=dep[dad[x]=fa]+1);
	for(int i=0;i<e[x].size();++i)if(e[x][i]!=fa){
		if(!dep[e[x][i]])dfs(e[x][i],x),++ch;
			else e2[x].push_back(e[x][i]);
	}
	if(ch==0)leaf.push_back(x);
}
inline bool cmp(int x,int y){return dep[x]<dep[y];}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;for(i=1;i<=m;++i)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	dfs(1,0);
	if(1ll*md*k>=n){
		cout<<"PATH\n";
		u=*max_element(leaf.begin(),leaf.end(),cmp);
		cout<<dep[u]<<'\n';
		for(;u;u=dad[u])cout<<u<<' ';
	}else{
		cout<<"CYCLES\n";
		for(i=0;i<k;++i){
			u=leaf[i];
			for(j=0;j<e2[u].size() && (dep[u]-dep[e2[u][j]]+1)%3==0;++j);
			if(j<e2[u].size()){
				cout<<dep[u]-dep[e2[u][j]]+1<<'\n';v=u;
				do{cout<<v<<' ';}while(v!=e2[u][j]?v=dad[v]:0);
			}else{
				v=e2[u][0];w=e2[u][1];
				if(dep[w]>dep[v])swap(w,v);
				cout<<dep[v]-dep[w]+2<<'\n';
				cout<<u<<' ';
				do{cout<<v<<' ';}while(v!=w?v=dad[v]:0);
			}
			cout<<'\n';
		}
	}
	return 0;
}