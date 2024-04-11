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

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

ll n;
ll w[300010];
vector<P> G[300010];

ll dp[300010];
ll ret = 0;
void dfs(int v,int p){
	ll a = 0;
	ll b = 0;
	for(int i = 0 ; i < G[v].size() ; i ++){
		P ed = G[v][i];
		if(ed.fr == p)continue;
		dfs(ed.fr,v);
		b = max( b , dp[ed.fr]-ed.sc );
		if(a < b)swap(a,b);
	}
	ret = max( ret , a+b+w[v] );
	dp[v] = a+w[v];
}

int main(){
	scanf("%lld",&n);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%lld",&w[i]);
	}
	for(int i = 0 ; i < n-1 ; i ++){
		ll u,v,c;
		scanf("%lld%lld%lld",&u,&v,&c);
		G[u].push_back(P(v,c));
		G[v].push_back(P(u,c));
	}
	
	dfs(1,0);
	cout << ret << endl;
}