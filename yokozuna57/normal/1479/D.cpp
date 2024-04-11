#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second
struct Graph{
	int n;
	vector<vector<pair<int,int>>> G;
	virtual void init(int n_){
		n=n_;
		G.resize(n);
	}
	virtual void add_edge(int u,int v,int i=0){
		G[u].push_back(mp(v,i));
	}
};
struct Tree : Graph{
	void in(int index){
		scanf("%d",&n);
		init(n);
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a-=index; b-=index;
			add_edge(a,b,i);
			add_edge(b,a,i);
		}
	}
};
struct LCA{
	Tree *T;
	void init(Tree *T_){
		T=T_;
		make();
	}
	int LOG;
	vector<vector<int>> par;
	vector<int> dep;
	void dfs(int v,int p,int d){
		par[v][0]=p;
		dep[v]=d;
		for(auto ed: T->G[v]){
			if(ed.fr==p)continue;
			dfs(ed.fr,v,d+1);
		}
	}
	void make(){
		LOG=32-__builtin_clz(T->n);
		par.resize(T->n,vector<int>(LOG));
		dep.resize(T->n);
		dfs(0,-1,0);
		for(int j=1;j<LOG;j++){
			for(int i=0;i<T->n;i++){
				if(par[i][j-1]==-1)par[i][j]=-1;
				else par[i][j]=par[par[i][j-1]][j-1];
			}
		}
	}
	int get(int u,int v){
		if(dep[u]<dep[v])swap(u,v);
		for(int j=LOG-1;j>=0;j--){
			if(par[u][j]!=-1&&dep[par[u][j]]>=dep[v])u=par[u][j];
		}
		if(u==v)return u;
		for(int j=LOG-1;j>=0;j--){
			if(par[u][j]!=par[v][j]){
				u=par[u][j];
				v=par[v][j];
			}
		}
		return par[u][0];
	}
};

template<class T>
struct pool{
	int cnt;
	vector<T> pool;
	void init(int n){
		pool.resize(n);
	}
	T* get(T* org=nullptr){
		if(pool.size()<=cnt){
			static bool flag=false;
			if(!flag)cerr<<"ERR: pool shortage"<<endl;
			flag=true;
			pool.resize(pool.size()+100);
		}
		if(org!=nullptr)pool[cnt]=*org;
		return &pool[cnt++];
	}
};

struct seg{
	static pool<seg> pl;
	seg *chl,*chr;
	ull a;
	seg(){
		chl=chr=nullptr;
		a=0ull;
	}
	void upd(int s,ull x,int l,int r){
		if(s<l||r<=s)return;
		a^=x;
		if(r==l+1)return;
		if(s<(l+r)/2){
			chl=pl.get(chl);
			chl->upd(s,x,l,(l+r)/2);
		}
		else{
			chr=pl.get(chr);
			chr->upd(s,x,(l+r)/2,r);
		}
	}
	/*seg* upd(int s,ull x,int l,int r){
		cerr<<s<<" "<<x<<" "<<l<<" "<<r<<endl;
		if(s<l||r<=s)return this;
		seg* ret=pl.get(this);
		ret->a^=x;
		if(r==l+1)return ret;
		if(s<(l+r)/2)ret->chl=chl->upd(s,x,l,(l+r)/2);
		else ret->chr=chr->upd(s,x,(l+r)/2,r);
	}*/
	ull query(int s,int t,int l,int r){
		if(t<=l||r<=s)return 0ull;
		if(s<=l&&r<=t)return a;
		ull retl=(chl==nullptr)?0:chl->query(s,t,l,(l+r)/2);
		ull retr=(chr==nullptr)?0:chr->query(s,t,(l+r)/2,r);
		return retl^retr;
	}
};
pool<seg> seg::pl;

std::random_device seed_gen;
std::mt19937_64 rnd(seed_gen());

struct solver : Tree{
	int q;
	int a[300010];
	int u[300010],v[300010],l[300010],r[300010];
	LCA lca;
	ull x[300010];
	seg* root[300010];
	void dfs(int v,int p){
		if(v==0)root[v]=seg::pl.get();
		else root[v]=seg::pl.get(root[p]);
		root[v]->upd(a[v],x[a[v]],0,n);
		for(auto ed: G[v]){
			if(ed.fr==p)continue;
			dfs(ed.fr,v);
		}
	}
	void run(){
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]--;
		}
		init(n);
		for(int i=0;i<n-1;i++){
			int s,t;
			scanf("%d%d",&s,&t);
			s--; t--;
			add_edge(s,t);
			add_edge(t,s);
		}
		for(int i=0;i<q;i++){
			scanf("%d%d%d%d",&u[i],&v[i],&l[i],&r[i]);
			u[i]--; v[i]--; l[i]--; r[i]--;
		}
		lca.init(this);
		for(int i=0;i<n;i++)x[i]=rnd();
		seg::pl.init(n*20);
		dfs(0,-1);
		for(int i=0;i<q;i++){
			int w=lca.get(u[i],v[i]);
			ull ret=root[u[i]]->query(l[i],r[i]+1,0,n)^root[v[i]]->query(l[i],r[i]+1,0,n);
			if(l[i]<=a[w]&&a[w]<=r[i])ret^=x[a[w]];
			if(ret==0)puts("-1");
			else {
				//int l_=l[i],r_=r[i];
				int l_=0,r_=n;
				while(l_<r_){
					int m_=(l_+r_)/2;
					ret=root[u[i]]->query(l[i],m_+1,0,n)^root[v[i]]->query(l[i],m_+1,0,n);
					if(l[i]<=a[w]&&a[w]<=m_)ret^=x[a[w]];
					if(ret!=0)r_=m_;
					else l_=m_+1;
				}
				printf("%d\n",l_+1);
			}
		}
	}
}solver;

int main(){
	solver.run();
}