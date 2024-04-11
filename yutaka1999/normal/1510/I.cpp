#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
#define a first
#define b second

template<class t,class u>bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u>bool chmin(t&a,u b){if(a>b){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>&p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t>
ostream&operator<<(ostream&os,const vector<t>&v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

template<class t>
using vc=vector<t>;

using vi=vc<int>;

using pi=pair<int,int>;

const int nmax=1010;
const int mmax=10010;
ll w[mmax];
int ac[nmax];

ll sq(ll x){return x*x;}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	w[0]=1LL<<50;
	rep(i,mmax-1)w[i+1]=w[i]*0.9;
	
	mt19937_64 rnd;
	int n,m;cin>>n>>m;
	rep(_,m){
		string s;cin>>s;
		int mx=*max_element(ac,ac+n);
		ll d[2]{0,0};
		rep(i,n){
			if(s[i]=='0')d[0]+=w[mx-ac[i]];
			else d[1]+=w[mx-ac[i]];
		}
		ll sum=d[0]+d[1];
		if(ll(rnd()%sum)<d[0])cout<<0<<endl;
		else cout<<1<<endl;
		
		int res;cin>>res;
		rep(i,n)if(s[i]-'0'==res)ac[i]++;
	}
}