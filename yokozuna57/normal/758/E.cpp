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

const ll INF=1000000000000000001;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

vector<P1> G[200010];
ll a[200010],b[200010];
ll c[200010];
bool dfs(int v,int p,ll w,ll s){
	bool ret = true;
	ll A=0,B=0;
	rep(i,G[v].size()){
		if(G[v][i].fr == p)continue;
		ret &= dfs(G[v][i].fr,v,G[v][i].sc.fr,G[v][i].sc.sc);
		A += a[G[v][i].fr];
		B += b[G[v][i].fr];
	}
	B = min(B,s);
	ret &= A <= B;
	a[v] = A+max((ll)1,w-s+A);
	b[v] = B+w;
	return ret;
}
map<P,P> ans;
void _dfs(int v,int p,ll w,ll s){
	ll C = c[v];
	rep(i,G[v].size()){
		if(G[v][i].fr == p)continue;
		C -= a[G[v][i].fr];
	}
	ll wd = min(C,w);
	s += wd-w;
	ans[P(v,p)] = P(wd,s);
	ans[P(p,v)] = P(wd,s);
	C -= wd;
	rep(i,G[v].size()){
		if(G[v][i].fr == p)continue;
		ll d = min(C,b[G[v][i].fr]-a[G[v][i].fr]);
		C -= d;
		c[G[v][i].fr] = a[G[v][i].fr]+d;
		_dfs(G[v][i].fr,v,G[v][i].sc.fr,G[v][i].sc.sc);
	}
}

int main(){
	static int n;
	static int x[200010],y[200010];
	static ll w[200010],p[200010];
	scanf("%d",&n);
	rep(i,n-1){
		scanf("%d%d%I64d%I64d",&x[i],&y[i],&w[i],&p[i]);
	}
	rep(i,n){
		G[x[i]].pb(mp1(y[i],w[i],p[i]));
		G[y[i]].pb(mp1(x[i],w[i],p[i]));
	}
	bool ret = dfs(1,0,0,INF);
	if(!ret){
		puts("-1");
		return 0;
	}
	
	c[1] = b[1];
	_dfs(1,0,0,INF);
	printf("%d\n",n);
	rep(i,n-1){
		P pp = ans[P(x[i],y[i])];
		printf("%d %d %I64d %I64d\n",x[i],y[i],pp.fr,pp.sc);
	}
}