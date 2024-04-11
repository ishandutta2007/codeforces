#include <bits/stdc++.h>
using namespace std;

using ll=long long;

//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

ll read(){
	ll i;
	scanf("%lld",&i);
	return i;
}

void print(ll x){
	printf("%lld\n",x);
}

using vi=vector<int>;
using pi=pair<int,int>;
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back

template <class T>
void chmin(T&a,T b){
	if(a>b)a=b;
}
template <class T>
void chmax(T&a,T b){
	if(a<b)a=b;
}

const int inf=INT_MAX/2-100;

const int Nmax=510;
vi g[Nmax];
int dist[Nmax][Nmax];

int Query(int i){
	cout<<i+1<<endl;
	string res;
	cin>>res;
	if(res=="FOUND"){
		return -1;
	}else{
		int w;
		cin>>w;
		return w-1;
	}
}

void Solve(int n){
	vi cand(n);
	REP(i,n)
		cand[i]=i;
	vi avail(n,1);
	while(1){
		int s=cand.size();
		/*if(s==1){
			int res=Query(cand[0]);
			assert(res==-1);
			return;
		}*/
		pi waf(inf,-1);
		for(auto v:cand){
			int num=0;
			for(auto to:g[v]){
				if(avail[to]){
					int c=0;
					for(auto w:cand)if(v!=w){
						if(dist[v][w]==1+dist[to][w]){
							c++;
						}
					}
					chmax(num,c);
				}
			}
			chmin(waf,pi(num,v));
		}
		int root=waf.second;
		int res=Query(root);
		if(res==-1)
			return;
		vi nx;
		for(auto v:cand)if(v!=root){
			if(dist[root][v]==1+dist[res][v]){
				nx.PB(v);
			}else
				avail[v]=0;
		}
		swap(nx,cand);
	}
}

signed main(){
	int n=read(),m=read();
	REP(_,m){
		int last=-1;
		int k=read();
		REP($,k){
			int a=read()-1;
			if(last!=-1){
				g[a].PB(last);
				g[last].PB(a);
			}
			last=a;
		}
	}
	
	REP(i,n)REP(j,n){
		dist[i][j]=inf;
	}
	REP(i,n){
		dist[i][i]=0;
		for(auto j:g[i]){
			dist[i][j]=1;
		}
	}
	
	REP(k,n)REP(i,n)REP(j,n){
		chmin(dist[i][j],dist[i][k]+dist[k][j]);
	}
	
	REP(_,n){
		Solve(n);
	}
}