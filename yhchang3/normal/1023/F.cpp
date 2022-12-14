#include<bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> p,sz;
	void init(int n){
		p.resize(n);sz.resize(n);
		for(int i=0;i<n;i++)
			sz[p[i]=i]=1;
	}
	int F(int x){
		return x==p[x]?x:p[x]=F(p[x]);
	}
	bool U(int x,int y){
		x=F(x),y=F(y);
		if(x==y)	return false;
		if(sz[x]<sz[y])	swap(x,y);
		p[y]=x;
		sz[x]+=sz[y];
		return true;
	}
	void UU(int x,int y){
		p[x]=y;
	}
};
vector<pair<int,int> > e[500010];
vector<int> ra,rb,rw;
int pt[500010],f[500010],dep[500010];

void dfs(int x,int p,int t){
	f[x]=p;
	pt[x]=t;
	for(auto& it:e[x])
		if(it.first!=p){
			dep[it.first]=dep[x]+1;
			dfs(it.first,x,it.second);
		}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k,m;
	cin>>n>>k>>m;
	DSU D;
	D.init(n+1);
	for(int i=1,u,v;i<=k;i++){
		cin>>u>>v;
		D.U(u,v);
		e[u].emplace_back(v,0);
		e[v].emplace_back(u,0);
	}
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		if(D.U(u,v)){
			e[u].emplace_back(v,1);
			e[v].emplace_back(u,1);
		}
		else{
			ra.emplace_back(u);
			rb.emplace_back(v);
			rw.emplace_back(w);
		}
	}
	dfs(1,0,0);
	long long int ans=0;
	int cnt=0;
	D.init(n+1);
	for(int i=0;i<rw.size();i++){
		int u=ra[i],v=rb[i],w=rw[i];
		u=D.F(u),v=D.F(v);
		while(u!=v){
			if(dep[u]>dep[v]){
				if(pt[u]==0){
					ans+=w;
					cnt++;
				}
				D.UU(u,f[u]);
			}
			else{
				if(pt[v]==0){
					ans+=w;
					cnt++;
				}
				D.UU(v,f[v]);
			}
			u=D.F(u);v=D.F(v);
		}
	}
	if(cnt!=k)
		cout<<-1<<'\n';
	else
		cout<<ans<<'\n';
}