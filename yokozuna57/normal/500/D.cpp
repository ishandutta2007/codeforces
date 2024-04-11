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

vector<int> G[100010];
int chi[100010];
int par[100010];
bool used[100010];

void dfs(int v,int p){
	used[v] = true;
	par[v] = p;
	chi[v] = 0;
	rep(i,G[v].size()){
		if(G[v][i] != p){
			if(!used[G[v][i]])dfs(G[v][i],v);
			chi[v] += chi[G[v][i]];
		}
	}
	chi[v] ++;
}

int main(){
	static int n;
	static int a[100010],b[100010],l[100010];
	
	scanf("%d",&n);
	rep1(i,n-1){
		scanf("%d%d%d",&a[i],&b[i],&l[i]);
		G[a[i]].pb(b[i]);
		G[b[i]].pb(a[i]);
	}
	
	rep(i,100010)used[i] = false;
	dfs(1,-1);
	
	LD ret = 0.0;
	rep1(i,n){
		if(par[a[i]] == b[i])swap(a[i],b[i]);
		LD x = (LD)n-chi[b[i]],y = (LD)chi[b[i]];
		ret += l[i] * x * (x-1) * y;
		ret += l[i] * x * y * (y-1);
	}
	LD div = (LD)n * ((LD)n-1) * ((LD)n-2) / 6.0;
	ret /= div;
	
	
	int q;
	scanf("%d",&q);
	
	rep(i,q){
		int r,w;
		scanf("%d%d",&r,&w);
		
		LD add = 0.0;
		LD x = (LD)n-chi[b[r]],y = (LD)chi[b[r]];
		add += (w-l[r]) * x * (x-1) * y;
		add += (w-l[r]) * x * y * (y-1);
		add /= div;
		
		ret += add;
		l[r] = w;
		
		printf("%.10f\n",ret);
	}
}