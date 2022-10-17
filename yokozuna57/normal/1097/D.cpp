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
typedef pair<ll,ll> P;
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
	if(k%2 == 1){
		ret *= x; ret %= M;
	}
	return ret;
}

vector<P> pr(ll n){
	vector<P> ret;
	for(ll i = 2 ; i*i <= n ; i ++){
		if(n%i == 0){
			P p = P(i,0);
			while(n%i == 0){
				n /= i;
				p.sc ++;
			}
			ret.push_back(p);
		}
	}
	if(n > 1)ret.push_back(P(n,1));
	return ret;
}

int main(){
	ll n,k;
	cin >> n >> k;
	
	vector<P> vec = pr(n);
	ll ret = 1;
	ll inv[52] = {};
	rep(i,52){
		inv[i] = modpow(i+1,M-2);
	}
	for(P p: vec){
		ll dp[52] = {};
		dp[p.sc] = 1;
		rep(i,k){
			rep(j,p.sc+1){
				//dp[j] /= (ld)j+1.0;
				dp[j] *= inv[j];
				dp[j] %= M;
			}
			rrep(j,p.sc){
				dp[j] += dp[j+1];
				if(dp[j] >= M)dp[j] -= M;
			}
		}
		ll sum = 0;
		rep(i,p.sc+1){
			sum += modpow(p.fr,i)*dp[i];
			sum %= M;
		}
		ret *= sum;
		ret %= M;
	}
	cout << ret << endl;
}