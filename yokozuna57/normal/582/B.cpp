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

int main(){
	int n,t;
	int a[102] = {};
	scanf("%d%d",&n,&t);
	rep1(i,n){
		scanf("%d",&a[i]);
	}
	
	int dp[302][302] = {};
	int dp__[302][102] = {};
	rep1(s,300){
		rep1(i,n){
			if(a[i] < s)dp__[s][i] = 0;
			else {
				rep(j,i){
					if(a[j] <= a[i])dp__[s][i] = max ( dp__[s][i] , dp__[s][j]+1 );
				}
			}
		}
		rep1(i,n){
			dp[s][a[i]] = max ( dp[s][a[i]] , dp__[s][i] );
		}
		rep1(i,300){
			dp[s][i] = max ( dp[s][i] , dp[s][i-1] );
		}
	}
	
	
	int cnt[302] = {};
	for(int i = 1 ; i <= n ; i++){
		cnt[a[i]] ++;
	}
	int MAX = 0;
	for(int i = 1 ; i <= 300 ; i ++)MAX = max ( MAX , cnt[i] );
	
	int dp_[302] = {};
	int ret = 0;
	rep(ppp,min(300,t)){
		int MAX_ = 0;
		rrep1(i,300){
			for(int j = i+1 ; j <= 300 ; j ++){
				dp_[j] = max ( dp_[j] , dp_[i]+dp[i][j] );
			}
			MAX_ = max ( MAX_ , dp_[i] );
		}
		ret = max ( ret , MAX_ + (t-ppp)*MAX );
	}
	rep1(i,300)ret = max ( ret , dp_[i] );
	cout << ret << endl;
	
	
	/*int dp0[102] = {};
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 0 ; j < i ; j ++){
			if(a[j] <= a[i])dp0[i] = max ( dp0[i] , dp0[j]+1 );
		}
	}
	int dp1[102] = {};
	for(int i = n ; i >= 1 ; i --){
		dp1[i] = 1;
		for(int j = i+1 ; j <= n ; j ++){
			if(a[j] >= a[i])dp1[i] = max ( dp1[i] , dp1[j]+1 );
		}
	}*/
	
	//rep(i,6)cout << dp0[i] << " "; cout << endl;
	//rep(i,6)cout << dp1[i] << " "; cout << endl;
	
	/*int cnt[302] = {};
	for(int i = 1 ; i <= n ; i++){
		cnt[a[i]] ++;
	}
	int b[302] = {};
	for(int i = 1 ; i <= n ; i ++){
		b[a[i]] = max ( b[a[i]] , dp0[i] );
	}
	for(int i = 1 ; i < 302 ; i ++){
		b[i] = max ( b[i] , b[i-1] );
	}
	int c[302] = {};
	for(int i = 1 ; i <= n ; i ++){
		c[a[i]] = max ( c[a[i]] , dp1[i] );
	}
	for(int i = 300 ; i >= 0 ; i --){
		c[i] = max ( c[i] , c[i+1] );
	}
	
	if(t == 1){
		cout << b[300] << endl;
		return 0;
	}
	
	int ret = 0;
	for(int i = 1 ; i <= 300 ; i ++){
		ret = max ( ret , b[i] + c[i] + cnt[i]*(t-2) );
	}
	cout << ret << endl;*/
}