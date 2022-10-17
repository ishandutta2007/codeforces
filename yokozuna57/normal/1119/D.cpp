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
	static int n;
	static ll s[100010];
	static int q;
	static ll l[100010],r[100010];
	scanf("%d",&n);
	rep1(i,n)scanf("%lld",&s[i]);
	scanf("%d",&q);
	rep1(i,q)scanf("%lld%lld",&l[i],&r[i]);
	
	sort(s+1,s+1+n);
	vector<ll> v;
	rep1(i,n-1)v.pb(s[i+1]-s[i]);
	sor(v);
	vector<P> w;
	rep1(i,q)w.pb(P(r[i]-l[i],i));
	sor(w);
	
	static ll ans[100010];
	ll ret = 0;
	ll pre = -1;
	ll k = 0;
	ll n_ = n;
	for(P p: w){
		if(pre < p.fr){
			while(k < v.size() && v[k] <= p.fr){
				ret += (v[k]-1-pre)*n_;
				pre = v[k]-1;
				n_ --;
				k ++;
			}
			ret += (p.fr-pre)*n_;
			pre = p.fr;
		}
		ans[p.sc] = ret;
	}
	rep1(i,q){
		printf("%lld%c",ans[i],(i==q)?'\n':' ');
	}
}