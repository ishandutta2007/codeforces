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

vector<P> prime_factory(int n){
	vector<P> ret;
	
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			P p=P(i,0);
			while(n%i==0){
				p.sc++;
				n/=i;
			}
			ret.pb(p);
		}
	}
	if(n!=1)ret.pb(P(n,1));
	
	return ret;
}

vector<int> divisors(int n){
	vector<P> vec = prime_factory(n);
	vector<int> ret;
	ret.pb(1);
	rep(i,vec.size()){
		int s = ret.size();
		int p = vec[i].fr , q = vec[i].sc;
		rep(j,s){
			int t = ret[j];
			rep1(k,q){
				t *= p;
				ret.pb(t);
			}
		}
	}
	return ret;
}

ll gcd(ll x,ll y){
	if(y == 0)return x;
	return gcd(y,x%y);
}

int n;
int a[200010];
int g[200010];
bool b[200010];
ll cnt(ll d){
	//rep(i,n)printf("%d",b[i]?1:0); puts("");
	int t = -1;
	rep(i,n){
		if(!b[i]){ t = i; break; }
	}
	if(t == -1){
		ll ret = 0;
		rep1(i,n-1)if(g[i] == d)ret ++;
		return ret*n;
	}
	ll ret = 0;
	ll u = 0 , v = 0;
	for(int i = t-1 ; i >= 0 ; i --){
		if(b[i]){
			u ++;
			if(g[u] == d)v ++;
			ret += v;
		}
		else {
			u = 0;
			v = 0;
		}
	}
	for(int i = n-1 ; i > t ; i --){
		if(b[i]){
			u ++;
			if(g[u] == d)v ++;
			ret += v;
		}
		else {
			u = 0;
			v = 0;
		}
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	rep1(i,n-1)g[i] = gcd(i,n);
	
	vector<int> vec = divisors(n);
	ll ret = 0;
	rep(i,vec.size()){
		if(vec[i] == n)continue;
		for(int l = 0 ; l < vec[i] ; l ++){
			int MAX = 0;
			for(int loc = l ; loc < n ; loc += vec[i]){
				MAX = max ( MAX , a[loc] );
				b[loc] = false;
			}
			for(int loc = l ; loc < n ; loc += vec[i]){
				if(a[loc] == MAX)b[loc] = true;
			}
		}
		ret += cnt(vec[i]);
	}
	
	cout << ret << endl;
}