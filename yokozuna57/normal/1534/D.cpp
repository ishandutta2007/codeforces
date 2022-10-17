#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

struct UF{
	vector<int> par,r;
	UF(int n){ init(n); }
	UF(){}
	void init(int n=-1){
		if(n==-1)n=par.size();
		par.resize(n);
		r.resize(n);
		iota(par.begin(),par.end(),0);
		fill(r.begin(),r.end(),0);
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
 	bool same(int x,int y){ return find(x)==find(y); }
	void unit(int x,int y){
		if(same(x,y))return;
		x=find(x);
		y=find(y);
		if(r[x]>r[y])swap(x,y);
		par[x]=y;
		if(r[x]==r[y])r[y]++;
	}
};

int n;
int d[2002][2002];
pair<int,int> dist[2002];

void query(int r){
	cout<<"? "<<r+1<<endl;
	fflush(stdout);
	for(int i=0;i<n;i++)cin>>d[r][i];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
	cin>>n;
	
	vector<pair<int,int>> ret;
	UF uf(n);
	query(0);
	for(int i=0;i<n;i++){
		dist[i]=mp(d[0][i],0);
		if(d[0][i]==1){
			ret.push_back(mp(0,i));
			uf.unit(0,i);
		}
	}
	
	while(ret.size()<n-1){
		int v=-1;
		for(int i=0;i<n;i++)if(dist[i].fr==2){ v=i; break; }
		int p=dist[v].sc;
		query(v);
		int u=-1;
		for(int i=0;i<n;i++)if(d[p][i]==1&&d[v][i]==1){ u=i; break; }
		for(int i=0;i<n;i++){
			if(d[p][i]==d[v][i])d[u][i]=d[p][i]-1;
			else d[u][i]=(d[v][i]+d[p][i])/2;
		}
		for(int i=0;i<n;i++){
			dist[i]=min(dist[i],mp(d[v][i],v));
			dist[i]=min(dist[i],mp(d[u][i],u));
			if(d[v][i]==1){
				if(!uf.same(v,i)){
					ret.push_back(mp(v,i));
					uf.unit(v,i);
				}
			}
			if(d[u][i]==1){
				if(!uf.same(u,i)){
					ret.push_back(mp(u,i));
					uf.unit(u,i);
				}
			}
		}
	}
	cout<<"!"<<endl;
	for(auto p: ret){
		cout<<p.fr+1<<" "<<p.sc+1<<endl;
	}
	fflush(stdout);
}