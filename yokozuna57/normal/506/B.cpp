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

typedef long long LL;
typedef long double LD;
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
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

int par[150010],r[150010],lar[150010];
void init(){ rep(i,150010){ par[i]=i; r[i]=0; lar[i] = 1; } }
int find(int x){ if(x==par[x])return x; return par[x]=find(par[x]); }
bool same(int x,int y){ return find(x)==find(y); }
void unit(int x,int y){ if(same(x,y))return; x=find(x); y=find(y); if(r[x]<r[y]){par[x]=y; lar[y] += lar[x];} else { par[y]=x; lar[x] += lar[y]; if(r[x]==r[y])r[x]++; } }

int n,m;
vector<int> G[100010];
vector<int> rG[100010];

vector<int> vec[100010];

vector<int> vs;
bool used[100010];
void dfs(int v){
	used[v] = true;
	rep(i,G[v].size()){
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.pb(v);
}

int cnt(int v){
	vs.clear();
	rep(i,100010)used[i] = false;
	rep(i,vec[v].size()){
		if(!used[vec[v][i]]){
			dfs(vec[v][i]);
		}
	}
	rep(i,100010)used[i] = false;
	rrep1(i,vs.size()-1){
		int p = vs[i];
		rep(j,rG[p].size()){
			if(!used[rG[p][j]])return lar[v];
		}
		used[p] = true;
	}
	return lar[v]-1;
}

int main(){
	init();
	scanf("%d%d",&n,&m);
	rep(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].pb(b);
		rG[b].pb(a);
		unit(a,b);
	}
	
	rep1(i,n){
		vec[find(i)].pb(i);
	}
	
	int ret = 0;
	bool used_[100010];
	rep(i,100010)used_[i] = false;
	rep1(i,n){
		if(par[i] == i){
			ret += cnt(i);
			used_[i] = true;
		}
	}
	printf("%d\n",ret);
}