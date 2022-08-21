#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
#define chmin(x,y) x = min (x,y)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

/*
H

Bellman Ford|eV.
O(EV + FElogV)

DAG Bellman Ford ADP O(E + FElogV)()

HAt.

*/
typedef pair<int,int> P;
struct edge {int to,cap,cost,rev;};
const int MAX_V=1000,INF=1e9;
int V = 100;			//!!
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
void add_edge(int from, int to, int cap, int cost){
	edge e1={to,cap,cost,G[to].size()},e2={from,0,-cost,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
int min_cost_flow(int s, int t, int f){
	int res=0;
	fill(h,h+V,0);
	rep(v,V){
		for(edge e:G[v]){
			if(e.cap>0) chmin(h[e.to],h[v]+e.cost);
		}
	}
	while(f>0){
		priority_queue< P,vector<P>,greater<P> > que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();
			que.pop();
			int v=p.second;
			if(dist[v]<p.first) continue;
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==INF) return -1;
		for(int v=0;v<V;v++) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

int main() {
	int N, K; cin >> N >> K;
	vector<int> a(N);
	rep(i, N) cin >> a[i], a[i]--;
	vector<int> c(N);
	rep(x, N) cin >> c[x];
	vector<vector<int> > v(N);
	rep(i, N) v[a[i]].pb(i);
	ll ans = 0;
	rep(x, N) {
		int k = v[x].size();
		ans += (ll)k * c[x];
	}
	for (int u = 0; u + 1 < N; u++)
		add_edge(u, u + 1, K, 0);
	rep(x, N) {
		for (int j = 0; j + 1 < v[x].size(); j++) {
			int l = v[x][j], r = v[x][j + 1];
			if (l + 1 < r) add_edge(l + 1, r, 1, -c[x]);
			else ans -= c[x];
		}
	}
	ans += min_cost_flow(0, N - 1, K - 1);
	cout << ans << endl;
}