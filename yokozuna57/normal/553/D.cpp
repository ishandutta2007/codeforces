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

int main(){
	static int n,m,k;
	static int c[100010];
	static vector<int> G[100010];
	scanf("%d%d%d",&n,&m,&k);
	rep(i,k){
		scanf("%d",&c[i]);
	}
	rep(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}
	
	static vector<int> ord;
	static bool used[100010];
	rep(i,100010)used[i] = false;
	rep(i,k){
		used[c[i]] = true;
		ord.pb(c[i]);
	}
	
	static int cnt[100010] = {};
	priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> que;
	rep1(i,n){
		if(used[i])continue;
		rep(j,G[i].size()){
			if(!used[G[i][j]])cnt[i] ++;
		}
		que.push( pair<ld,int> ( (ld)cnt[i]/(ld)G[i].size() , i ) );
	}
	
	static ld MIN = -1.0 , ret = -1;
	while(!que.empty()){
		pair<ld,int> p = que.top(); que.pop();
		if(used[p.sc])continue;
		if(p.fr >= MIN){
			MIN = p.fr;
			ret = p.sc;
		}
		used[p.sc] = true;
		ord.pb(p.sc);
		rep(i,G[p.sc].size()){
			int v = G[p.sc][i];
			if(used[v])continue;
			cnt[v] --;
			que.push( pair<ld,int> ( (ld)cnt[v]/(ld)G[v].size() , v ) );
		}
	}
	
	static vector<int> ans;
	bool t = false;
	rep(i,ord.size()){
		if(ord[i] == ret)t = true;
		if(t)ans.pb(ord[i]);
	}
	
	printf("%d\n",ans.size());
	rep(i,ans.size()){
		printf("%d%c",ans[i],(i == ans.size()-1)?'\n':' ');
	}
}