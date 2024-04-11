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
	int n;
	int a[102];
	scanf("%d",&n);
	rep1(i,n)scanf("%d",&a[i]);
	
	int dp[102][3];
	rep(i,102)rep(j,3)dp[i][j] = INF;
	
	dp[0][0] = 0;
	rep1(i,n){
		dp[i][0] = min ( dp[i-1][0] , min(dp[i-1][1],dp[i-1][2]) ) + 1;
		if(a[i] == 1 || a[i] == 3)dp[i][1] = min ( dp[i-1][0] , dp[i-1][2] );
		if(a[i] == 2 || a[i] == 3)dp[i][2] = min ( dp[i-1][0] , dp[i-1][1] );
	}
	cout << min ( dp[n][0] , min(dp[n][1],dp[n][2]) ) << endl;
}