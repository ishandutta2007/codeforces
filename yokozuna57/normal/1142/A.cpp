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

ll gcd(ll x,ll y){
	if(y == 0)return x;
	return gcd(y,x%y);
}

int main(){
	ll n,k,a,b;
	cin >> n >> k >> a >> b;
	
	ll ret1=n*k,ret2=1;
	rep(i,2)rep(j,2){
		ll d = 0;
		if(i == 0)d += k-a;
		else d += a;
		if(j == 0)d += k-b;
		else d += b;
		rep(c,n){
			ll ret = n*k/gcd(n*k,c*k+d);
			ret1 = min( ret1 , ret );
			ret2 = max( ret2 , ret );
		}
	}
	cout << ret1 << " " << ret2 << endl;
}