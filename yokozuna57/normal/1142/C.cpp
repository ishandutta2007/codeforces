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

int main(){
	static ll n;
	static ll x[100010],y[100010];
	scanf("%lld",&n);
	rep1(i,n)scanf("%lld%lld",&x[i],&y[i]);
	
	static ll s[100010],t[100010];
	rep1(i,n){
		s[i] = -x[i];
		t[i] = y[i]-x[i]*x[i];
	}
	vector<P> vec;
	rep1(i,n){
		vec.pb(P(s[i],t[i]));
	}
	sor(vec);
	vector<P> vec_;
	rep(i,vec.size()){
		if(vec_.size() > 0 && vec[i].fr == vec_[vec_.size()-1].fr){
			vec_.pop_back();
		}
		vec_.push_back(vec[i]);
	}
	vec = vec_;
	
	vector<P> ls;
	rep(i,vec.size()){
		//cout << vec[i].fr << " " << vec[i].sc << endl;
		if(ls.size() < 2){
			ls.push_back(vec[i]);
			continue;
		}
		P p = vec[i];
		while(ls.size() >= 2){
			P q = ls[ls.size()-1];
			P r = ls[ls.size()-2];
			if(p.fr == q.fr){
				ls.pop_back();
				continue;
			}
			ll b = -(-p.sc+q.sc);
			ll b_ = (-p.fr+q.fr);
			if(b_ < 0){ b *= -1; b_ *= -1; }
			ll c = q.fr*b+q.sc*b_;
			ll c_ = r.fr*b+r.sc*b_;
			if(c <= c_){
				ls.pop_back();
				continue;
			}
			else break;
		}
		ls.push_back(p);
	}
	cout << ls.size()-1 << endl;
}