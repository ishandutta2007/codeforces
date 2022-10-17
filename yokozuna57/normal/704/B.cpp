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

const ll INF = 1000000000000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	static ll n,s,e;
	static ll x[5002],a[5002],b[5002],c[5002],d[5002];
	scanf("%I64d%I64d%I64d",&n,&s,&e);
	rep1(i,n)scanf("%I64d",&x[i]);
	rep1(i,n)scanf("%I64d",&a[i]);
	rep1(i,n)scanf("%I64d",&b[i]);
	rep1(i,n)scanf("%I64d",&c[i]);
	rep1(i,n)scanf("%I64d",&d[i]);
	
	static ll dp[2][5002];
	static int t = 0 , t_ = 1;
	rep(i,5002)dp[t][i] = INF;
	dp[t][0] = 0;
	
	if(e < s){
		rep1(i,n){
			rep(j,5002)dp[t_][j] = INF;
			if(i == s){
				rep(j,n+1){
					dp[t_][j] = min ( dp[t_][j] , dp[t][j] + a[i]+d[i] );
					dp[t_][j] = min ( dp[t_][j] , dp[t][j+1] + (2*x[i]+a[i]+c[i]) );
				}
			}
			else if(i == e){
				rep(j,n+1){
					if(j > 0)dp[t_][j] = min ( dp[t_][j] , dp[t][j-1] + (-2*x[i]+b[i]+d[i]) );
					dp[t_][j] = min ( dp[t_][j] , dp[t][j] + a[i]+d[i] );
				}
			}
			else {
				rep(j,n+1){
					if(j > 0)dp[t_][j] = min ( dp[t_][j] , dp[t][j-1] + (-2*x[i]+b[i]+d[i]) );
					if(j == 1 && e < i && i < s)dp[t_][j] = min ( dp[t_][j] , dp[t][j] + b[i]+c[i] );
					else dp[t_][j] = min ( dp[t_][j] , dp[t][j] + min ( c[i]+b[i] , a[i]+d[i] ) );
					dp[t_][j] = min ( dp[t_][j] , dp[t][j+1] + (2*x[i]+a[i]+c[i]) );
				}
			}
			if(i != n)dp[t_][0] = INF;
			swap(t,t_);
		}
		cout << dp[t][0] - (x[s]-x[e]+d[e]+a[s]) << endl;
	}
	else {
		rep1(i,n){
			rep(j,5002)dp[t_][j] = INF;
			if(i == s){
				rep(j,n+1){
					if(j > 0)dp[t_][j] = min ( dp[t_][j] , dp[t][j-1] + (-2*x[i]+b[i]+d[i]) );
					dp[t_][j] = min ( dp[t_][j] , dp[t][j] + c[i]+b[i] );
				}
			}
			else if(i == e){
				rep(j,n+1){
					dp[t_][j] = min ( dp[t_][j] , dp[t][j] + c[i]+b[i] );
					dp[t_][j] = min ( dp[t_][j] , dp[t][j+1] + (2*x[i]+a[i]+c[i]) );
				}
			}
			else {
				rep(j,n+1){
					if(j > 0)dp[t_][j] = min ( dp[t_][j] , dp[t][j-1] + (-2*x[i]+b[i]+d[i]) );
					if(j == 1 && s < i && i < e)dp[t_][j] = min ( dp[t_][j] , dp[t][j] + a[i]+d[i] );
					else dp[t_][j] = min ( dp[t_][j] , dp[t][j] + min ( c[i]+b[i] , a[i]+d[i] ) );
					dp[t_][j] = min ( dp[t_][j] , dp[t][j+1] + (2*x[i]+a[i]+c[i]) );
				}
			}
			if(i != n)dp[t_][0] = INF;
			swap(t,t_);
		}
		cout << dp[t][0] - (x[e]-x[s]+c[e]+b[s]) << endl;
	}
	
	/*rep1(i,n){
		rep(j,5002)dp[t_][j] = INF;
		rep(j,n+1){
			if(j > 0)dp[t_][j] = min ( dp[t_][j] , dp[t][j-1] + (-2*x[i]+b[i]+d[i]) );
			dp[t_][j] = min ( dp[t_][j] , dp[t][j] + min ( c[i]+b[i] , a[i]+d[i] ) );
			dp[t_][j] = min ( dp[t_][j] , dp[t][j+1] + (2*x[i]+a[i]+c[i]) );
		}
		if(i != n)dp[t_][0] = INF;
		swap(t,t_);
	}
	
	if(e < s){
		cout << dp[t][0] - (x[s]-x[e]+d[e]+a[s]) << endl;
	}
	else {
		cout << dp[t][0] - (x[e]-x[s]+c[e]+b[s]) << endl;
	}*/
}