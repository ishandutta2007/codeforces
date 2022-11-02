#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > e[500010];
int sta[500010],vis[500010],dis[500010],col[500010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		e[b].push_back({a,c});
	}

	if(n==1){
		cout<<"0\n1"<<endl;
		return 0;
	}

	dis[1]=-1;
	queue<int> q;q.push(n),vis[n]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto &it:e[u]){
			int v=it.first,w=it.second;
			sta[v]|=1<<w;
			if(!vis[v]&&sta[v]==3){
				vis[v]=1;
				col[v]=w;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	cout<<dis[1]<<endl;
	for(int i=1;i<=n;i++){
		if(sta[i]==0)cout<<0;
		if(sta[i]==1)cout<<1;
		if(sta[i]==2)cout<<0;
		if(sta[i]==3)cout<<col[i];
	}
	cout<<endl;
}