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
typedef pair<ll,P1> P2;

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
#define mp2(a,b,c,d) P2(a,mp1(b,c,d))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	static ll n,m;
	static ll l[200010],r[200010];
	static ll a[200010];
	scanf("%I64d%I64d",&n,&m);
	rep(i,n){
		scanf("%I64d%I64d",&l[i],&r[i]);
	}
	rep(i,m){
		scanf("%I64d",&a[i]);
	}
	
	vector<P2> vec;
	rep(i,n-1){
		vec.pb(mp2(l[i+1]-r[i],0,r[i+1]-l[i],i));
	}
	rep(i,m){
		vec.pb(mp2(a[i],1,a[i],i+1));
	}
	sor(vec);
	
	static ll ans[200010];
	priority_queue<P,vector<P>,greater<P>> que;
	rep(i,vec.size()){
		P1 p = vec[i].sc;
		if(p.fr == 0){
			que.push(p.sc);
		}
		else {
 			if(que.size() == 0)continue;
			if(que.top().fr < p.sc.fr){
				puts("No");
				return 0;
			}
			else {
				ans[que.top().sc] = p.sc.sc;
				que.pop();
			}
		}
	}
	if(que.size() > 0){
		puts("No");
		return 0;
	}
	else {
		puts("Yes");
		rep(i,n-1){
			printf("%I64d%c",ans[i],(i == n-2)?'\n':' ');
		}
	}
}