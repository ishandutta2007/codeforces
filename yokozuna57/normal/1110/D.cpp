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
	static int n,m;
	static int a;
	static int cnt[1000010] = {};
	scanf("%d%d",&n,&m);
	rep1(i,n){
		scanf("%d",&a);
		cnt[a] ++;
	}
	
	static int dp[2][5][3] = {};
	static int t = 0, t_ = 1;
	rep1(s,m+5){
		rep(i,5)rep(j,3){
			dp[t_][i][j] = 0;
		}
		rep(i,5)rep(j,3){
			rep(k,3){
				if(cnt[s] < i+k)break;
				dp[t_][j+k][k] = max( dp[t_][j+k][k] , dp[t][i][j]+k+(cnt[s]-(i+k))/3 );
			}
		}
		swap(t,t_);
	}
	
	cout << dp[t][0][0] << endl;
}