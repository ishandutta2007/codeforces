#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int INF=1000000000;

struct tree{
	int n;
	vector<vector<int>> G;
	tree(){}
	tree(int n_){
		n=n_;
		G=vector<vector<int>>(n);
	}
	
	void add_edge(int a,int b){
		G[a].push_back(b);
		G[b].push_back(a);
	}
	void input(int ind){
		scanf("%d",&n);
		G=vector<vector<int>>(n);
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a-=ind; b-=ind;
			add_edge(a,b);
		}
	}
	
	void dfs_dist(int v,int p,int d,vector<int> &dist){
		dist[v]=d;
		for(int u: G[v]){
			if(u==p)continue;
			dfs_dist(u,v,d+1,dist);
		}
	}
	
	//centroids
	int cent;
	vector<tree*> subtree;
	vector<pair<int,int>> id;
	int dfs_sz(int v,int p,vector<int> &par,vector<int> &sz){
		par[v]=p;
		sz[v]=1;
		for(int u: G[v]){
			if(u==p)continue;
			sz[v]+=dfs_sz(u,v,par,sz);
		}
		return sz[v];
	}
	int dfs_id(int v,int p,pair<int,int> id_){
		id[v]=id_; id_.sc++;
		for(int u: G[v]){
			if(u==p)continue;
			id_.sc=dfs_id(u,v,id_);
			subtree[id_.fr]->add_edge(id[v].sc,id[u].sc);
		}
		return id_.sc;
	}
	void cent_div(){
		vector<int> sz(n),par(n);
		dfs_sz(0,-1,par,sz);
		cent=0;
		while(1){
			if(sz[cent]<=n/2){
				cent=par[cent];
				continue;
			}
			bool upd=false;
			for(int u: G[cent]){
				if(u==par[cent])continue;
				if(sz[u]>n/2){
					cent=u;
					upd=true;
					break;
				}
			}
			if(!upd)break;
		}
		id=vector<pair<int,int>>(n);
		for(int u: G[cent]){
			subtree.push_back(new tree(u==par[cent]?(n-sz[cent]):sz[u]));
			dfs_id(u,cent,mp(subtree.size()-1,0));
		}
		for(auto t: subtree)t->cent_div();
	}
	
	vector<int> dist;
	vector<int> val;
	void f(vector<int> &d){
		dist=vector<int>(n);
		dfs_dist(cent,-1,0,dist);
		val=vector<int>(n);
		for(int i=0;i<n;i++){
			val[dist[i]]=max(val[dist[i]],d[i]);
		}
		for(int i=0;i+1<n;i++){
			val[i+1]=max(val[i+1],val[i]);
		}
		vector<vector<int>> d_(subtree.size());
		for(int i=0;i<subtree.size();i++)d_[i]=vector<int>(subtree[i]->n);
		for(int i=0;i<n;i++){
			if(i==cent)continue;
			d_[id[i].fr][id[i].sc]=d[i];
		}
		for(int i=0;i<subtree.size();i++){
			subtree[i]->f(d_[i]);
		}
	}
	bool solve(int v,int d){
		if(d-1-dist[v]>=0&&val[min(n-1,d-1-dist[v])]>=d)return true;
		if(v==cent)return false;
		return subtree[id[v].fr]->solve(id[v].sc,d);
	}
	
	//debug
	void output(){
		cerr<<n<<endl;
		for(int i=0;i<n;i++){
			cerr<<i<<"-";
			for(int j: G[i]){
				cerr<<j<<",";
			}
			cerr<<endl;
		}
	}
	void debug_centroids(){
		output();
		for(auto t: subtree)t->debug_centroids();
	}
};

tree T;
int k;
int a[200010];

int main(){
	T.input(1);
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	
	T.cent_div();
	
	if(1){
		vector<int> d(T.n,INF);
		queue<int> que;
		for(int i=0;i<k;i++){
			d[a[i]]=0;
			que.push(a[i]);
		}
		while(!que.empty()){
			int v=que.front(); que.pop();
			for(int u: T.G[v]){
				if(d[u]>d[v]+1){
					d[u]=d[v]+1;
					que.push(u);
				}
			}
		}
		T.f(d);
	}
	for(int i=0;i<T.n;i++){
		int l=0,r=T.n-1;
		while(l<r){
			int mid=(l+r+1)/2;
			if(T.solve(i,mid))l=mid;
			else r=mid-1;
		}
		printf("%d%c",l,(i+1==T.n)?'\n':' ');
	}
}