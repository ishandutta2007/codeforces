#include<bits/stdc++.h>
using namespace std;


const int N=250000,LOG=18;
int p[LOG+1][N+1],dep[N+1];

vector<int> e[N+1];

void dfs(int x,int fa){
	p[0][x]=fa;
	for(int i=0;i+1<=LOG;i++)
		p[i+1][x]=p[i][p[i][x]];
	for(int it:e[x])
		if(it!=fa){
			dep[it]=dep[x]+1;
			dfs(it,x);
		}
}

int LCA(int a,int b){
	if(dep[a]>dep[b])	swap(a,b);
	int k=0;
	for(int i=dep[b]-dep[a];i;i>>=1){
		if(i&1)	b=p[k][b];
		k++;
	}
	if(a==b)	return a;
	for(int i=LOG;i>=0;i--)
		if(p[i][a]!=p[i][b]){
			a=p[i][a];
			b=p[i][b];
		}
	return p[0][a];
}
int dep2[N+1];
vector<int> ee[N+1];

void dfs2(int x,int fa){
	for(int it:ee[x])
		if(it!=fa){
			dep2[it]=dep2[x]+1;
			dfs2(it,x);
		}
}
struct DSU{
	int p[N+1],sz[N+1];
	void init(int n){
		for(int i=1;i<=n;i++)
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
}D;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		e[x].emplace_back(y);
		e[y].emplace_back(x);
	}
	dfs(1,0);
	vector<pair<int,int> > e2;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		ee[x].emplace_back(y);
		ee[y].emplace_back(x);
		e2.emplace_back(x,y);
	}
	dfs2(1,0);
	for(auto& it:e2)
		if(dep2[it.first]>dep2[it.second])
			swap(it.first,it.second);
	sort(e2.begin(),e2.end(),[&](pair<int,int>& a,pair<int,int>& b){
		return dep2[a.second]>dep2[b.second];
	});
	cout<<n-1<<'\n';
	D.init(n);
	for(auto& it:e2){
		int u=it.first,v=it.second;
		int l=LCA(u,v);
		int ans;
		if(D.F(v)==D.F(l)){
			ans=u;
			for(int i=LOG;i>=0;i--)
				if(dep[ans]-(1<<i)>dep[l]&&D.F(v)!=D.F(p[i][ans]))
					ans=p[i][ans];
		}
		else{
			ans=v;
			for(int i=LOG;i>=0;i--)
				if(dep[ans]-(1<<i)>dep[l]&&D.F(v)==D.F(p[i][ans]))
					ans=p[i][ans];
		}
		cout<<ans<<' '<<p[0][ans]<<' '<<u<<' '<<v<<'\n';
		D.U(ans,p[0][ans]);
	}
}