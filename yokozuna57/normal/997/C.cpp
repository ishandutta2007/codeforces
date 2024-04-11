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

const ll M = 998244353;

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= M;
	if(k%2 == 1){
		ret *= x;
		ret %= M;
	}
	return ret;
}

ll inv(ll x){
	return modpow(x,M-2);
}

ll C[1000010] = {};
ll pow2[1000010];
ll pow3[1000010];

int main(){
	ll n;
	cin >> n;
	C[0] = 1;
	for(int i = 0 ; i < n ; i ++){
		C[i+1] = C[i]*(n-i); C[i+1] %= M;
		C[i+1] *= inv(i+1); C[i+1] %= M;
	}
	pow2[0] = 1;
	pow3[0] = 1;
	for(int i = 0 ; i < n ; i ++){
		pow2[i+1] = pow2[i]*2; pow2[i+1] %= M;
		pow3[i+1] = pow3[i]*3; pow3[i+1] %= M;
	}
	
	ll X = modpow(3,n*n);
	for(int j = 0 ; j <= n ; j ++){
		ll x = C[j];
		x *= modpow(1+M-pow3[j],n); x %= M;
		if(j&1)X += x;
		else X += M-x;
	}
	X %= M;
	
	ll Y = 0;
	for(int i = 2 ; i <= n ; i ++){
		ll y = C[i];
		y *= pow2[i]-2; y %= M;
		y *= modpow(pow3[n]+M-3,n-i); y %= M;
		Y += y;
	}
	Y *= 2; Y %= M;
	
	ll Z = 0;
	for(int i = 3 ; i <= n ; i ++){
		ll z = C[i];
		z *= pow3[i]+3*(M-pow2[i])+3; z %= M;
		z *= modpow(pow3[n]+M-3,n-i); z %= M;
		Z += z;
	}
	Z *= 2; Z %= M;
	
	//cout << X << " " << Y << " " << Z << endl;
	
	ll ret = 3*X+3*(M-Y)+2*(M-Z);
	ret %= M;
	cout << ret << endl;
}