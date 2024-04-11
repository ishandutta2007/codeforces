#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1e5+10;

int maintain[MAXN];

vector<int> edge[MAXN],redge[MAXN];
bool visit[MAXN],invalid[MAXN];
int scc[MAXN];
int cntscc;
int cnt[MAXN];
vector<int> topo;

void rdfs(int x){
	visit[x]=true;
	for(int it:redge[x])
		if(!visit[it])
			rdfs(it);
	topo.emplace_back(x);
}

void dfs(int x){
	scc[x]=cntscc;
	for(int it:edge[x])
		if(!scc[it])
			dfs(it);
		else if(scc[it]!=cntscc)
			invalid[cntscc]=true;
}

int main(){
	int n,m,h;
	cin>>n>>m>>h;
	for(int i=1;i<=n;i++)
		cin>>maintain[i];
	for(int i=1,x,y;i<=m;i++){
		//construct the directed graph
		cin>>x>>y;
		if((maintain[x]+1)%h==maintain[y]){
			edge[x].emplace_back(y);
			redge[y].emplace_back(x);
		}
		if((maintain[y]+1)%h==maintain[x]){
			edge[y].emplace_back(x);
			redge[x].emplace_back(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(!visit[i])
			rdfs(i);
	for(int i=n-1;i>=0;i--)
		if(!scc[topo[i]]){
			cntscc++;
			dfs(topo[i]);
		}
	for(int i=1;i<=n;i++)
		cnt[scc[i]]++;
	int whichscc=-1;
	for(int i=1;i<=cntscc;i++)
		if(!invalid[i])
			if(whichscc==-1||cnt[i]<cnt[whichscc])
				whichscc=i;
	cout<<cnt[whichscc]<<endl;
	for(int i=1;i<=n;i++)
		if(scc[i]==whichscc)
			cout<<i<<' ';
	cout<<endl;
}