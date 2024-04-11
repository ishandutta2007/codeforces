#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mp make_pair
#define fr first
#define sc second

template<int N=100010>
struct tree{
	int n;
	vector<int> G[N];
	void add_edge(int a,int b){
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	int c[N];
	
	//tree dp
	/*int par[N];
	int dep[N];
	void dfs(int v,int p,int d){
		par[v]=p;
		dep[v]=d;
		for(int u: G[v]){
			if(u==p)continue;
			dfs(u,v,d+1);
		}
	}*/
	
	//merge tech
	ll ret[N];
	struct val{
		int sz;
		ll ret;
		int k;
		map<int,int> m;
		val(){
			sz=ret=k=0;
		}
	};
	void add(val *x, pair<int,int> p){
		x->m[p.fr]+=p.sc;
		if(x->m[p.fr]>x->k){
			x->k=x->m[p.fr];
			x->ret=p.fr;
		}
		else if(x->m[p.fr]==x->k){
			x->ret+=p.fr;
		}
	}
	void merge_val(val *x, val *y){
		x->sz+=y->sz;
		for(auto p: y->m){
			add(x,p);
		}
	}
	val* dp[N];
	void upd(int v){
		dp[v]->sz++;
		add(dp[v],mp(c[v],1));
	}
	int dfs_dp(int v,int p){
		auto sz=mp(-1,-1);
		for(int u: G[v]){
			if(u==p)continue;
			sz=max(sz,mp(dfs_dp(u,v),u));
		}
		auto repr=sz.sc;
		if(repr==-1){
			dp[v]=new val;
		}
		else dp[v]=dp[repr];
		for(int u: G[v]){
			if(u==p||u==repr)continue;
			merge_val(dp[v],dp[u]);
		}
		upd(v);
		ret[v]=dp[v]->ret;
		return dp[v]->sz;
	}
};

int main(){
	tree<100010> T;
	scanf("%d",&T.n);
	for(int i=0;i<T.n;i++)scanf("%d",&T.c[i]);
	for(int i=0;i<T.n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b); a--; b--;
		T.add_edge(a,b);
	}
	T.dfs_dp(0,-1);
	for(int i=0;i<T.n;i++){
		printf("%lld%c",T.ret[i],(i+1==T.n)?'\n':' ');
	}
}