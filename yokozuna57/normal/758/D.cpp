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

const ll INF=1000000000000000001;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	ll n;
	string s;
	cin >> n >> s;
	
	ll a[60][10];
	ll dp[60];
	rep(i,60){
		rep(j,10)a[i][j] = -1;
		dp[i] = INF;
	}
	rep(i,s.size()){
		a[i][1] = s[i]-'0';
		if(i>0)for(int j = 2 ; j <= 9 ; j ++){
			if(a[i-1][j-1] > 0)a[i][j] = a[i-1][j-1]*10+a[i][1];
		}
		rep1(j,9){
			if(a[i][j] != -1 && a[i][j] < n){
				if(j == i+1)dp[i] = a[i][j];
				else if(dp[i-j]<=INF/n)dp[i] = min ( dp[i] , dp[i-j]*n+a[i][j] );
			}
		}
	}
	cout << dp[s.size()-1] << endl;
}