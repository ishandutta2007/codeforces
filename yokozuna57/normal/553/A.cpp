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

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= M;
	if(k%2 == 1){ ret *= x; ret %= M; }
	return ret;
}

ll dom(ll x){
	return modpow(x,M-2);
}

ll C(ll n,ll k){
	ll ret = 1;
	rep(i,k){ ret *= (n-i); ret %= M; }
	rep1(i,k){ ret *= dom(i); ret %= M; }
	return ret;
}

int main(){
	ll k;
	ll c[1002];
	cin >> k;
	rep(i,k){
		cin >> c[i];
	}
	
	ll dp[1002];
	ll sum = c[0];
	dp[0] = 1;
	rep1(i,k-1){
		sum += c[i];
		dp[i] = dp[i-1] * C(sum-1,c[i]-1);
		dp[i] %= M;
	}
	
	cout << dp[k-1] << endl;
}