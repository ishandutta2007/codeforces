#include<bits/stdc++.h>
using namespace std;
 
const int mod = 998244353;
 
vector<int> edge[150001];
 
long long int dp[150001];
int power(int x,int b){
	int res = 1;
	while(b){
		if(b&1)	res=1LL*res*x%mod;
		x=1LL*x*x%mod;
		b>>=1;
	}
	return res;
}
const int MAXN = 150000,MAXLOG = 18;
int parent[MAXN+1][MAXLOG+1],dep[MAXN+1],sz[MAXN+1];//dep[root] init as 0
void dfs(int index,int father){
   parent[index][0]=father;
   sz[index]=1;
   for(int i=0;i+1<=MAXLOG;i++)
      parent[index][i+1]=parent[parent[index][i]][i];
   for(int i=0;i<edge[index].size();i++){
      int next=edge[index][i];
      if(next==father){
      	swap(edge[index][i],edge[index].back());
      	edge[index].pop_back();
      	i--;
      	continue;
      }
      dep[next]=dep[index]+1;
      dfs(next,index);
      sz[index]+=sz[next];
   }
}
 
int n;
long long int tag[150001];
bitset<150001> vis;
void push(int x,long long int now){
	if(vis[x]){
		now+=tag[x]*(n-sz[x]);
		dp[x]=(dp[x]+now)%mod;
		for(int it:edge[x])
			push(it,now-sz[it]*tag[x]);
	}
	else{
		dp[x]=(dp[x]+now)%mod;
		for(int it:edge[x])
			push(it,now);
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int block = 600,q;
	cin>>n>>q;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		edge[x].emplace_back(y);
		edge[y].emplace_back(x);
	}
	vector<pair<int,int> > pool;
	vector<int> mask[MAXN+1];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=17;j++)
			if(i&(1<<j))
				mask[i].emplace_back(j);
	dfs(1,0);
	int inv=power(n,mod-2);
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int v,d;
			cin>>v>>d;
			pool.emplace_back(make_pair(v,d));
		}
		else{
			int vv;
			cin>>vv;
			long long int ans=dp[vv];
			for(auto it:pool){
				int u=it.first,v=vv;
				long long int d = it.second;
				if(u==v)
					ans+=d*n;
				else if(dep[u]>=dep[v])
					ans+=d*sz[u];
				else{
   					for(int it:mask[dep[v]-dep[u]-1])
   						v=parent[v][it];
   					if(parent[v][0]==u)
   						ans+=d*(n-sz[v]);
   					else
   						ans+=d*sz[u];
				}
			}
			cout<<ans%mod*inv%mod<<'\n';
		}
		if(block==pool.size()){
			long long int sum = 0;
			for(auto it:pool){
				sum+=1LL*it.second*sz[it.first];
				tag[it.first]+=it.second;
				vis[it.first]=true;
			}
			push(1,sum);
			for(auto it:pool){
				tag[it.first]=0;
				vis[it.first]=false;
			}
			pool.clear();
		}
	}
}