#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
#include <assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) sort(ALL(v)); v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

vi eratosthenes_sieve(int n){
	vi res(n+1);
	if(n<2) return res;
	res[2]=1;
	for(int i=3;i<=n;i+=2){
		if(i*i<=n && !res[i]) for(int j=i+i+i;j<=n;j+=i+i) res[j]=1;
		res[i]=!res[i];
	}
	return res;
}



typedef int Weight;
const Weight INF=99999999;
struct Edge{
	int src,dst;
	Weight weight;
	int rev;
	Edge(int f, int t, Weight c,int rev=0):src(f),dst(t),weight(c),rev(rev){}
};
typedef vector< vector<Edge> > Graph;

void add_edge(Graph &G,int s,int t,Weight cap){
	G[s].push_back(Edge(s,t,cap,G[t].size()));
	G[t].push_back(Edge(t,s,0,G[s].size()-1));
}


void bfs(const Graph &G,vector<int> &level,int s){
	level[s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		REP(i,G[v].size()){
			const Edge &e=G[v][i];
			if(e.weight>0 && level[e.dst] < 0){
				level[e.dst] = level[v] +1;
				que.push(e.dst);
			}
		}
	}
}
Weight dfs(Graph &G,vector<int> &level,vector<int> &iter,int v,int t,Weight flow){
	if(v==t)return flow;
	for(int &i=iter[v];i<(int)G[v].size();i++){
		Edge &e=G[v][i];
		if(e.weight>0&&level[v]<level[e.dst]){
			Weight d=dfs(G,level,iter,e.dst,t,min(flow,e.weight));
			if(d>0){
				e.weight-=d;
				G[e.dst][e.rev].weight+=d;
				return d;
			}
		}
	}
return 0;
}

// Dinic
// O(EV^2)
Weight max_flow(Graph &G,int s,int t){
	Weight flow = 0;
	while(true){
		vector<int> level(G.size(),-1);
		vector<int> iter(G.size(),0);
		bfs(G,level,s);
		if(level[t]<0)break; // 
		Weight f=0;
		while((f=dfs(G,level,iter,s,t,INF))>0){
			flow+=f;
		}
	}
	return flow;
}



int n, m;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vi ispl = eratosthenes_sieve(50000);
	scanf("%d", &n);
	vector<pii> d[2];
	REP(i, n){
		int x;
		scanf("%d", &x);
		d[x&1].eb(x, i);
	}
	Graph g(n+2);
	int s = n;
	int t = s+1;
	REP(i, d[0].size())REP(j, d[1].size())if(ispl[d[0][i].first + d[1][j].first]){
		add_edge(g, i, d[0].size()+j, 1);
	}
	REP(i, d[0].size()) add_edge(g, s, i, 2);
	REP(j, d[1].size()) add_edge(g, d[0].size()+j, t, 2);
	vector<vi> next(n);
	int mf = max_flow(g, s, t);
	if(mf != n){
		cout << "Impossible" << endl;
		return 0;
	}
	REP(i, d[0].size()) FOR(e, g[i]){
		if(e->weight == 0){
			int u = d[0][i].second;
			int v = d[1][e->dst - d[0].size()].second;
			next[u].pb(v);
			next[v].pb(u);
		}
	}
	vector<vi> ans;
	vi visited(n);
	REP(i, n)if(!visited[i]){
		ans.eb();
		vi &tar = ans.back();
		int p = -1;
		int u = i;
		do{
			tar.pb(u+1);
			visited[u] = 1;
			FOR(it, next[u])if(*it!=p){
				p = u;
				u = *it;
				break;
			}
		}while(u != i);
	}
	cout << ans.size() << endl;
	REP(i, ans.size()){
		cout << ans[i].size();
		FOR(it, ans[i]) cout << " " << *it;
		cout << endl;
	}
	return 0;
}