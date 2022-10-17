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
#define rep(i,x) for(ll i=0;i<x;i++)
#define rep1(i,x) for(ll i=1;i<=x;i++)
#define rrep(i,x) for(ll i=x-1;i>=0;i--)
#define rrep1(i,x) for(ll i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

const char a[4] = { 'A' , 'C' , 'G' , 'T' };
const ll M = 1000000007;

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= M;
	if(k%2 == 1){ret *= x; ret %= M;}
	return ret;
}

ll dom(ll x){
	return modpow(x,M-2);
}

ll C(ll n,ll k,ll comb){
	if(n < k)return 0;
	if(n == k)return 1;
	comb *= n; comb %= M;
	comb *= dom(n-k); comb %= M;
	return comb;
}

int main(){
	ll n,k;
	string s;
	cin >> n >> k >> s;
	
	if(k == 0){
		ll ret = 0;
		rep(i,n){
			ll x = s[i]-48;
			ret += x * modpow(10,n-1-i);
			ret %= M;
			//cout << ret << endl;
		}
		cout << ret << endl;
		return 0;
	}
	
	ll ret = 0;
	ll sum = 0;
	ll comb = 0;
	rep(i,n-1){
		ll x = s[i]-48;
		sum += x;
		comb = C(i,k-1,comb);
		ll y = modpow(10,n-2-i);
		y *= sum; y %= M;
		y *= comb; y %= M;
		ret += y;
		ret %= M;
	}
	
	comb = 0;
	rep(i,n){
		ll x = s[i]-48;
		comb = C(i,k,comb);
		x *= comb; x %= M;
		x *= modpow(10,n-1-i); x %= M;
		ret += x;
		ret %= M;
	}
	
	cout << ret << endl;
}