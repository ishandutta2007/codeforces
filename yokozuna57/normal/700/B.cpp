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
typedef pair<int,int> P;
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

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int n,k;
vector<int> G[200010];
ll dep[200010];
int par[200010];
bool uni[200010];
ll dp[200010];

int dfs(int v,int p,int d){
	dep[v] = d;
	par[v] = p;
	dp[v] = 0;
	rep(i,G[v].size()){
		if(G[v][i] != p)dp[v] += dfs(G[v][i],v,d+1);
	}
	if(uni[v])dp[v]++;
	return dp[v];
}

ll solve(int v,int t){
	int T = t; t = t - (2*k-dp[v]);
	if(t == dp[v])return 0;
	ll ret = 0;
	int nex = -1,MAX = 0;
	rep(i,G[v].size()){
		if(G[v][i] != par[v]){
			if(MAX < dp[G[v][i]]){
				MAX = dp[G[v][i]];
				nex = G[v][i];
			}
		}
	}
	if(MAX-t <= (dp[v]-t)/2)return dep[v]*(dp[v]-t);
	else return dep[v]*2*(dp[v]-MAX) + solve(nex,T+2*(dp[v]-MAX));
}

int main(){
	scanf("%d%d",&n,&k);
	rep1(i,n)uni[i] = false;
	rep(i,2*k){
		int u;
		scanf("%d",&u);
		uni[u] = true;
	}
	rep(i,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].pb(y);
		G[y].pb(x);
	}
	dfs(1,0,1);
	
	ll ret = 0;
	rep1(i,n)if(uni[i])ret += dep[i];
	cout << ret - solve(1,0) << endl;
}