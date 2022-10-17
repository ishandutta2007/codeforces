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

ll dp[52] = {};
vector<int> ans;

void dfs(int n,int t,ll k){
	if(t == n)return;
	if(k <= dp[n-t-1]){
		ans.pb(t+1);
		dfs(n,t+1,k);
	}
	else {
		ans.pb(t+2);
		ans.pb(t+1);
		dfs(n,t+2,k-dp[n-t-1]);
	}
}

int main(){
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2 ; i <= 50 ; i ++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	ll n,k;
	cin >> n >> k;
	dfs(n,0,k);
	
	rep(i,ans.size()){
		printf("%d%c",ans[i],(i == ans.size()-1)?'\n':' ');
	}
}