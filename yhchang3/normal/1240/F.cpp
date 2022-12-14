#include<bits/stdc++.h>
using namespace std;

int col[1001];
bool vis[1001];

int w[101],it[101][2];
vector<pair<int,int> > e[101];
vector<pair<int,int> > ch;


void dfs(int x,int cur,int tot,int type){
	for(;it[x][type]<e[x].size();it[x][type]++)
		if(!vis[e[x][it[x][type]].second]&&col[e[x][it[x][type]].second]==cur){
			ch.emplace_back(e[x][it[x][type]]);
			vis[e[x][it[x][type]].second]=true;
			it[x][type]++;
			dfs(e[x][it[x][type]-1].first,cur^tot,tot,type^1);
			return;
		}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(v,i);
		e[v].emplace_back(u,i);
		vector<int> uc(k+1),vc(k+1);
		for(auto it:e[u])
			uc[col[it.second]]++;
		for(auto it:e[v])
			vc[col[it.second]]++;
		int mu=2000,mv=2000;
		for(int j=1;j<=k;j++)
			mu=min(mu,uc[j]),mv=min(mv,vc[j]);
		for(int j=1;j<=k;j++)
			uc[j]-=mu,vc[j]-=mv;
		int cu,cv,cc=0;
		for(int j=1;j<=k;j++){
			if(uc[j]!=2&&vc[j]!=2){
				cc=j;
				break;
			}
			if(vc[j]==0)	cu=j;
			if(uc[j]==0)	cv=j;
		}
		if(cc!=0){
			col[i]=cc;
			continue;
		}
		ch.clear();
		for(int j=1;j<=n;j++)
			it[j][0]=it[j][1]=0;
		for(int j=1;j<=i;j++)
			vis[j]=false;
		int ct=cv^cu;
		dfs(u,cu,ct,0);
		for(auto it:ch)
			col[it.second]^=ct;
		col[i]=cu;
	}
	for(int i=1;i<=m;i++)
		cout<<col[i]<<'\n';
}