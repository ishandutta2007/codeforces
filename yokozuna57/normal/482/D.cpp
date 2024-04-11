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

const ll M = 1000000007;

int n;
vector<int> ch[100010];
ll s[100010],t[100010];
void dfs(int v){
	s[v] = 1;
	t[v] = 0;
	ll u = 1;
	//ll wt = 0;
	ll x = 1;
	ll y = 0;
	rep(i,ch[v].size()){
		dfs(ch[v][i]);
		ll _s = s[v]*(s[ch[v][i]]+1) + t[v]*t[ch[v][i]];
		ll _t = t[v]*(s[ch[v][i]]+1) + s[v]*t[ch[v][i]];
		s[v] = _s%M;
		t[v] = _t%M;
		u *= s[ch[v][i]]+1;
		u %= M;
		//wt += t[ch[v][i]];
		ll _x = x + y*t[ch[v][i]];
		ll _y = y + x*t[ch[v][i]];
		x = _x%M;
		y = _y%M;
	}
	//wt %= M;
	s[v] += M+s[v]-u;
	t[v] += M+t[v]-y;
	s[v] %= M;
	t[v] %= M;
	swap(s[v],t[v]);
}

int main(){
	int p[100010];
	scanf("%d",&n);
	for(int i = 2 ; i <= n ; i ++){
		scanf("%d",&p[i]);
		ch[p[i]].pb(i);
	}
	dfs(1);
	cout << (s[1]+t[1])%M << endl;
}