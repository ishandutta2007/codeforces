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
int ne[101][101];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vi a(n), b(n);
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];
	REP(i, m){
		int u, v;
		cin >> u >> v; u--; v--;
		ne[v][u] = ne[u][v] = INF;
	}
	REP(i, n) ne[i][i] = INF;
	Graph g(2*n+2);
	REP(i, n)REP(j, n) add_edge(g, i, n+j, ne[i][j]);
	REP(i, n) add_edge(g, 2*n, i, a[i]);
	REP(i, n) add_edge(g, n+i, 2*n+1, b[i]);
	if(accumulate(ALL(a), 0) != accumulate(ALL(b), 0) || max_flow(g, 2*n, 2*n+1) < accumulate(ALL(b), 0)){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		REP(i, n)REP(j, n){
			cout << g[g[i][j].dst][g[i][j].rev].weight << " \n"[j+1 == n];
		}
	}
	return 0;
}