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

vector<P> ret;
void a(){
	sor(ret);
	vector<P> ret_;
	ll l = ret[0].fr,r = ret[0].sc;
	for(int i = 1 ; i < ret.size() ; i ++){
		P p = ret[i];
		if(p.fr >= r+2){
			ret_.pb(P(l,r));
			l = p.fr;
			r = p.sc;
		}
		else {
			r = max( r , p.sc );
		}
	}
	ret_.pb(P(l,r));
	ret = ret_;
}
void b(){
	vector<P> ret_;
	for(int i = 0 ; i < ret.size() ; i ++){
		ret_.pb(P(ret[i].fr+1,ret[i].sc+1));
		ret_.pb(P(ret[i].fr+5,ret[i].sc+5));
		ret_.pb(P(ret[i].fr+10,ret[i].sc+10));
		ret_.pb(P(ret[i].fr+50,ret[i].sc+50));
	}
	ret = ret_;
	a();
}
void c(){
	vector<P> ret_;
	for(int i = 0 ; i < ret.size() ; i ++){
		for(int j = i ; j < ret.size() ; j ++){
			ret_.pb(P(ret[i].fr+ret[j].fr,ret[i].sc+ret[j].sc));
		}
	}
	ret = ret_;
	a();
}

int main(){
	int n;
	cin >> n;
	
	ret.pb(P(0,0));
	for(int i = 29 ; i >= 0 ; i --){
		c();
		if(n&(1<<i))b();
	}
	ll cnt = 0;
	for(int i = 0 ; i < ret.size() ; i ++){
		cnt += ret[i].sc-ret[i].fr+1;
	}
	cout << cnt << endl;
}