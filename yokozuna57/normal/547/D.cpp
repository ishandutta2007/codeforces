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

vector<int> G[200010];
int color[200010];
void dfs(int v,int t){
	color[v] = t;
	rep(i,G[v].size()){
		if(color[G[v][i]] == 0)dfs(G[v][i],3-t);
	}
}

int main(){
	static int n;
	static int x[200010],y[200010];
	scanf("%d",&n);
	rep(i,n){
		scanf("%d%d",&x[i],&y[i]);
	}
	
	static vector<int> h[200010],w[200010];
	rep(i,n){
		h[x[i]].pb(i);
		w[y[i]].pb(i);
	}
	
	rep(i,200010){
		for(int j = 0 ; j+1 < h[i].size() ; j += 2){
			G[h[i][j]].pb(h[i][j+1]);
			G[h[i][j+1]].pb(h[i][j]);
		}
		for(int j = 0 ; j+1 < w[i].size() ; j += 2){
			G[w[i][j]].pb(w[i][j+1]);
			G[w[i][j+1]].pb(w[i][j]);
		}
	}
	
	rep(i,200010){
		color[i] = 0;
	}
	
	rep(i,n){
		if(color[i] == 0){
			dfs(i,1);
		}
		printf("%c",(color[i] == 1)?'b':'r');
	}
}