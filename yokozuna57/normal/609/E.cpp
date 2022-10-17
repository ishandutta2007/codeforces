#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF=1000000000;

#define mp make_pair
#define fr first
#define sc second

template <int N = 200010>
struct UF{
	int par[N],r[N];
	int w[N];
	UF(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
			r[i] = 0;
			w[i]=INF;
		}
	}
	void init(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
			r[i] = 0;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		return find(par[x]);
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	void unit(int x,int y,int w_){
		if(same(x,y))return;
		x = find(x);
		y = find(y);
		if(r[x] < r[y]){
			par[x] = y;
			w[x]=w_;
		}
		else {
			par[y] = x;
			w[y]=w_;
			if(r[x] == r[y]){
				r[x] ++;
			}
		}
	}
};

int n,m;
int u[200010],v[200010];
ll w[200010];

UF<200010> uf;
vector<int> ch[200010];
int dep[200010];

void dfs(int v,int p,int d){
	dep[v]=d;
	for(auto u: ch[v]){
		dfs(u,v,d+1);
	}
}
ll f(int v,int u){
	if(dep[v]>dep[u])swap(v,u);
	while(dep[v]<dep[u]){
		if(v==uf.par[u])return uf.w[u];
		u=uf.par[u];
	}
	while(uf.par[u]!=uf.par[v]){
		u=uf.par[u];
		v=uf.par[v];
	}
	return max(uf.w[u],uf.w[v]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%lld",&u[i],&v[i],&w[i]);
		u[i]--; v[i]--;
	}
	static vector<pair<ll,int>> vec;
	for(int i=0;i<m;i++){
		vec.push_back(mp(w[i],i));
	}
	sort(vec.begin(),vec.end());
	ll sum=0;
	for(auto ed: vec){
		if(uf.same(u[ed.sc],v[ed.sc]))continue;
		sum+=ed.fr;
		uf.unit(u[ed.sc],v[ed.sc],w[ed.sc]);
	}
	int root;
	for(int i=0;i<n;i++){
		if(uf.par[i]==i)root=i;
		else ch[uf.par[i]].push_back(i);
	}
	dfs(root,-1,0);
	
	/*for(int i=0;i<n;i++){
		cout<<uf.par[i]<<" "<<uf.w[i]<<endl;
	}*/
	
	for(int i=0;i<m;i++){
		printf("%lld\n",sum-f(u[i],v[i])+w[i]);
	}
}