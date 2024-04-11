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

ll phi(ll x){
	ll ret = 1;
	for(ll i = 2 ; i*i <= x ; i ++){
		if(x%i == 0){
			ret *= (i-1);
			x /= i;
			while(x%i == 0){
				x /= i;
				ret *= i;
			}
		}
	}
	if(x != 1)ret *= x-1;
	return ret;
}

ll gcd(ll x,ll y){
	if(y == 0)return x;
	return gcd(y,x%y);
}

long long modpow(long long x,ll k,ll M){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2,M);
	ret *= ret;
	ret %= M;
	if(k%2 == 1){
		ret *= x;
		ret %= M;
	}
	return ret;
}

pair<ll,ll> f(ll a,ll b,ll c,ll X){
	ll ph = phi(abs(b));
	ll ret_x = modpow(abs(a),ph-1,abs(b));
	if(a < 0 && ph%2 == 0)ret_x *= -1;
	ret_x *= -c;
	ret_x %= abs(b);
	if(ret_x <= X-abs(b)){
		ret_x += ((X-ret_x)/abs(b))*abs(b);
	}
	else if(ret_x > X){
		ret_x -= ((ret_x-X+abs(b)-1)/abs(b))*abs(b);
	}
	ll ret_y = (-c-a*ret_x)/b;
	return pair<ll,ll>(ret_x,ret_y);
}

pair<ll,ll> minu(pair<ll,ll> p){
	p.fr *= -1;
	return p;
}

pair<ll,ll> hanten(pair<ll,ll> p){
	swap(p.fr,p.sc);
	return p;
}

long double dist(ld x1,ld y1,ld x2,ld y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
long double dist_(ld x1,ld y1,ld x2,ld y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main(){
	cout.precision(20);
	ll a,b,c;
	ll x[2],y[2];
	scanf("%lld%lld%lld",&a,&b,&c);
	scanf("%lld%lld",&x[0],&y[0]);
	scanf("%lld%lld",&x[1],&y[1]);
	
	/*ll g = gcd(abs(a),abs(b));
	if(a == 0 || b == 0 || abs(c)%g != 0){
		cout << dist_(x[0],y[0],x[1],y[1]) << endl;
		return 0;
	}
	a /= g;
	b /= g;
	c /= g;*/
	if(a == 0 || b == 0){
		cout << dist_(x[0],y[0],x[1],y[1]) << endl;
		return 0;
	}
	
	vector<pair<ld,ld>> vec[2];
	/*for(int i = 0 ; i < 2 ; i ++){
		vec[i].push_back(f(a,b,c,x[i]));
		vec[i].push_back(minu(f(-a,b,c,-x[i])));
		vec[i].push_back(hanten(f(b,a,c,y[i])));
		vec[i].push_back(hanten(minu(f(-b,a,c,-y[i]))));
	}*/
	for(int i = 0 ; i < 2 ; i ++){
		vec[i].push_back(pair<ld,ld>(x[i],(-a*(ld)x[i]-c)/(ld)b));
		vec[i].push_back(pair<ld,ld>((-b*(ld)y[i]-c)/(ld)a,y[i]));
	}
	long double ret = dist_(x[0],y[0],x[1],y[1]);
	for(int i = 0 ; i < vec[0].size() ; i ++){
		for(int j = 0 ; j < vec[1].size() ; j ++){
			ret = min( ret ,
				dist_(x[0],y[0],vec[0][i].fr,vec[0][i].sc)
				+ dist(vec[0][i].fr,vec[0][i].sc,vec[1][j].fr,vec[1][j].sc)
				+ dist_(vec[1][j].fr,vec[1][j].sc,x[1],y[1]) );
		}
	}
	/*for(int i = 0 ; i < vec[0].size() ; i ++){
		printf("%lld %lld\n",vec[0][i].fr,vec[0][i].sc);
	}
	for(int i = 0 ; i < vec[1].size() ; i ++){
		printf("%lld %lld\n",vec[1][i].fr,vec[1][i].sc);
	}*/
	cout << ret << endl;
}