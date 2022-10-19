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

ld a,b,c,d;
pair<ld,ld> g(ld x,ld y,ld m){
	ld r = 4000000000000000000.0 , s = -4000000000000000000.0;
	ld ans[4];
	ans[0] = (x-m)*(y-m);
	ans[1] = (x-m)*(y+m);
	ans[2] = (x+m)*(y-m);
	ans[3] = (x+m)*(y+m);
	rep(i,4){
		r = min ( r , ans[i] );
		s = max ( s , ans[i] );
	}
	return pair<ld,ld>(r,s);
}

bool f(ld m){
	pair<ld,ld> x = g(a,d,m);
	pair<ld,ld> y = g(b,c,m);
	if(max(x.fr,y.fr) <= min(x.sc,y.sc))return true;
	else return false;
}

int main(){
	cin >> a >> b >> c >> d;
	
	ld l = 0 , r = 2000000000.0;
	while(r-l >= 0.000000001){
		ld m = (l+r)/2.0;
		if(f(m))r = m;
		else l = m;
	}
	
	cout.precision(20);
	cout << r << endl;
}