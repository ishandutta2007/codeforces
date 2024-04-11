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
typedef pair<ll,P> P1;

typedef pair<int,pair<ld,ld>> segment;
#define seg(a,b,c) pair<int,pair<ld,ld>>(a,pair<ld,ld>(b,c))

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
	int n;
	static ll x[1000010];
	static ll y[1000010];
	static ll a[1000010];
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%lld%lld%lld",&x[i],&y[i],&a[i]);
	}
	x[0] = 0;
	y[0] = 1000000001;
	
	vector<P1> vec;
	for(int i = 0 ; i <= n ; i ++){
		vec.push_back(mp1(x[i],y[i],a[i]));
	}
	sor(vec);
	for(int i = 0 ; i <= n ; i++){
		x[i] = vec[i].fr;
		y[i] = vec[i].sc.fr;
		a[i] = vec[i].sc.sc;
	}
	
	static ll dp[1000010];
	deque<pair<int,pair<ld,ld>>> deq;
	dp[0] = 0;
	deq.push_back(seg(0,-1000000000.0,1000000000.0));
	for(int j = 1 ; j <= n ; j ++){
		while(deq.back().sc.fr > y[j])deq.pop_back();
		dp[j] = x[j]*y[j]-a[j]+dp[deq.back().fr]-x[deq.back().fr]*y[j];
		while(1){
			int i = deq.front().fr;
			ld y_ = (ld)(dp[j]-dp[i])/(ld)(x[j]-x[i]);
			if(y_ >= deq.front().sc.sc){
				deq.pop_front();
			}
			else {
				deq.front().sc.fr = y_;
				deq.push_front(seg(j,-1000000000.0,y_));
				break;
			}
		}
	}
	
	ll ret = 0;
	for(int i = 1 ; i <= n ; i ++){
		ret = max( ret , dp[i] );
	}
	cout << ret << endl;
}