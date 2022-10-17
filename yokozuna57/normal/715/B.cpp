#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const ll INF=1000000000000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

struct graph{
	int n,m;
	int u[10002],v[10002];
	ll w[10002];
	
	vector<P> G[1002];
	ll dist[1002];
	int pre[1002];
	bool used[1002];
	priority_queue<P,vector<P>,greater<P>> que;
	void solve(int s,int t){
		rep(i,1002)G[i].clear();
		rep(i,m){
			G[u[i]].pb(P(v[i],w[i]));
			G[v[i]].pb(P(u[i],w[i]));
		}
		rep(i,n){
			dist[i] = INF;
			used[i] = false;
			pre[i] = -1;
		}
		dist[s] = 0;
		que.push(P(0,s));
		while(!que.empty()){
			P p = que.top(); que.pop();
			if(!used[p.sc]){
				used[p.sc] = true;
				rep(i,G[p.sc].size()){
					P ed = G[p.sc][i];
					if(dist[ed.fr] > dist[p.sc] + ed.sc){
						dist[ed.fr] = dist[p.sc] + ed.sc;
						pre[ed.fr] = p.sc;
						que.push(P(dist[ed.fr],ed.fr));
					}
				}
			}
		}
	}
}G[2];

int main(){
	ll n,m,l,s,t;
	ll u[10002],v[10002],w[10002];
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&l,&s,&t);
	rep(i,m){
		scanf("%I64d%I64d%I64d",&u[i],&v[i],&w[i]);
	}
	
	rep(i,2){
		G[i].n = n;
		G[i].m = m;
		rep(j,m){
			G[i].u[j] = u[j];
			G[i].v[j] = v[j];
			G[i].w[j] = w[j];
			if(w[j] == 0){
				if(i == 0)G[i].w[j] = 1;
				else G[i].w[j] = INF;
			}
		}
		G[i].solve(s,t);
	}
	
	if(G[1].dist[t] < l || l < G[0].dist[t]){
		puts("NO");
		return 0;
	}
	puts("YES");
	
	bool used[10002];
	rep(i,10002)used[i] = false;
	map<P,int> M;
	rep(i,m){
		M[P(min(u[i],v[i]),max(u[i],v[i]))] = i;
	}
	int loc = t;
	while(loc != s){
		used[M[P(min(loc,G[0].pre[loc]),max(loc,G[0].pre[loc]))]] = true;
		loc = G[0].pre[loc];
	}
	rep(i,m){
		if(w[i] == 0 && !used[i]){
			w[i] = INF;
			G[0].w[i] = INF;
		}
	}
	
	rep(i,m){
		if(w[i] == 0){
			G[0].w[i] += l-G[0].dist[t];
			G[0].solve(s,t);
		}
	}
	
	rep(i,m){
		printf("%d %d %I64d\n",G[0].u[i],G[0].v[i],G[0].w[i]);
	}
}