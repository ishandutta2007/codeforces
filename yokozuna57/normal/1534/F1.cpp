#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

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
struct SCC{
	Graph *G;
	Graph rG;
	vector<int> vs;
	vector<bool> used;
	vector<int> cmp;
	void init(Graph *G_){
		G=G_;
		rG.init(G->n);
		for(int i=0;i<G->n;i++){
			for(auto ed: G->G[i]){
				rG.G[ed.fr].push_back(mp(i,ed.sc));
			}
		}
	}
	void dfs(int v){
		used[v]=true;
		for(auto ed: G->G[v]){
			if(!used[ed.fr])dfs(ed.fr);
		}
		vs.push_back(v);
	}
	void rdfs(int v,int k){
		used[v]=true;
		cmp[v]=k;
		for(auto ed: rG.G[v]){
			if(!used[ed.fr])rdfs(ed.fr,k);
		}
	}
	int run(){
		used.resize(G->n,false);
		cmp.resize(G->n);
		vs.clear();
		for(int v=0;v<G->n;v++){
			if(!used[v])dfs(v);
		}
		used=vector<bool>(G->n,false);
		int k=0;
		for(int i=vs.size()-1;i>=0;i--){
			if(!used[vs[i]])rdfs(vs[i],k++);
		}
		return k;
	}
};

Graph G,H;
SCC scc;

int main_(){
	int n,m;
	scanf("%d%d",&n,&m);
	G.init(n);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G.add_edge(a,b);
	}
	scc.init(&G);
	int k=scc.run();
	vector<vector<int>> cmp(k);
	for(int i=0;i<n;i++)cmp[scc.cmp[i]].push_back(i);
	
	printf("%d\n",k);
	for(int i=0;i<k;i++){
		printf("%d",(int)cmp[i].size());
		for(int x: cmp[i])printf(" %d",x);
		puts("");
	}
}

int n,m;
int a[400010];

inline int ToInt(int i,int j){
	return i*m+j;
}

bool used[400010];
int main(){
	scanf("%d%d",&n,&m);
	vector<vector<char>> c(n,vector<char>(m));
	for(int i=0;i<n;i++){
		scanf("\n");
		for(int j=0;j<m;j++)scanf("%c",&c[i][j]);
	}
	for(int i=0;i<m;i++)scanf("%d",&a[i]);
	
	vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>(m));
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			if(c[i][j]=='#')v[i][j]=mp(i,j);
			else {
				if(i==n-1)v[i][j]=mp(-1,-1);
				else v[i][j]=v[i+1][j];
			}
		}
	}
	
	G.init(n*m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(c[i][j]=='.')continue;
		if(i>0&&c[i-1][j]=='#')G.add_edge(ToInt(i,j),ToInt(i-1,j));
		if(j>0&&v[i][j-1].fr!=-1)G.add_edge(ToInt(i,j),ToInt(v[i][j-1].fr,v[i][j-1].sc));
		if(j+1<m&&v[i][j+1].fr!=-1)G.add_edge(ToInt(i,j),ToInt(v[i][j+1].fr,v[i][j+1].sc));
		if(i+1<n&&v[i+1][j].fr!=-1)G.add_edge(ToInt(i,j),ToInt(v[i+1][j].fr,v[i+1][j].sc));
	}
	
	/*for(int i=0;i<n*m;i++){
		for(auto ed: G.G[i])cerr<<ed.fr<<" "; cerr<<";"<<i<<endl;
	}*/
	
	scc.init(&G);
	int k=scc.run();
	
	//for(int i=0;i<n*m;i++)cerr<<scc.cmp[i]<<" "; cerr<<endl;
	
	H.init(k);
	for(int i=0;i<n*m;i++){
		for(auto ed: G.G[i]){
			if(scc.cmp[i]!=scc.cmp[ed.fr]){
				H.add_edge(scc.cmp[i],scc.cmp[ed.fr]);
				//cerr<<scc.cmp[i]<<" "<<scc.cmp[ed.fr]<<endl;
			}
		}
	}
	set<int> S;
	for(int j=0;j<m;j++){
		if(a[j]==0)continue;
		int cnt=0;
		for(int i=n-1;i>=0;i--){
			if(c[i][j]=='#'){
				cnt++;
				if(cnt==a[j]){
					S.insert(scc.cmp[ToInt(i,j)]);
					//cerr<<scc.cmp[ToInt(i,j)]<<endl;
					break;
				}
			}
		}
	}
	
	fill_n(used,n*m,false);
	int ret=0;
	for(int i=0;i<k;i++){
		if(!S.empty()&&*S.begin()==i){
			//cerr<<i<<" "<<*S.begin()<<endl;
			S.erase(S.begin());
			if(!used[i]){
				ret++;
				used[i]=true;
			}
		}
		if(used[i]){
			for(auto ed: H.G[i]){
				used[ed.fr]=true;
			}
		}
	}
	printf("%d\n",ret);
}