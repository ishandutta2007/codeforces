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
typedef pair<ll,P> P1;

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
	if(k&(ll)1){ ret *= x; ret %= M; }
	return ret;
}
ll inv(ll x){
	return modpow(x,M-2);
}

const int MAX_N_math_C = 4002;
ll fact[MAX_N_math_C],fact_inv[MAX_N_math_C];
void math_C_init(){
	fact[0] = 1; fact_inv[0] = 1;
	rep1(i,MAX_N_math_C-1){
		fact[i] = fact[i-1] * i; fact[i] %= M;
		fact_inv[i] = inv(fact[i]);
	}
}
ll math_C(ll n,ll k){
	ll ret = fact[n]*fact_inv[k]; ret %= M;
	ret *= fact_inv[n-k]; ret %= M;
	return ret;
}

int main(){
	math_C_init();
	ll n;
	cin >> n;
	
	ll dp[2][4002] = {};
	ll memo[4002] = {};
	memo[0] = 1;
	int t = 0 , t_ = 1;
	dp[0][0] = 1;
	rep1(i,n){
		rep(j,4002)dp[t_][j] = 0;
		memo[i] = 0;
		rep(j,i+1){
			dp[t_][j] = dp[t][j]*j + dp[t][j-1];
			dp[t_][j] %= M;
			memo[i] += dp[t_][j];
		}
		memo[i] %= M;
		swap(t,t_);
	}
	
	ll ret = 0;
	rep1(i,n){
		ret += math_C(n,i)*memo[n-i];
		ret %= M;
	}
	cout << ret << endl;
}