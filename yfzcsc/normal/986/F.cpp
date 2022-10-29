#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<ll,ll> par;
const ll inf=1ll<<60;
namespace WXHAKIOI2019{
	par p[1000];
	ll tp,A,B,a[10]={2ll,3ll,5ll,7ll,11ll,13ll,17ll,19ll,23ll,29ll};
	inline ll mul(ll a,ll b,ll c){
		a%=c,b%=c;
		ll t=a*b-(ll)((ldb)a*b/c+0.5)*c;
		return t<0?t+c:t;
	}
	ll qpow(ll a,ll b,ll c){   
	    ll res=1;   
	    for (;b;b>>=1,a=mul(a,a,c))   
	        if (b&1) res=mul(res,a,c);   
	    return res;   
	}
	bool check(ll a,ll n,ll r,ll s){   
	    ll x=qpow(a,r,n),pre=x;   
	    for (int i=1;i<=s;i++){   
	        x=mul(x,x,n);   
	        if (x==1&&pre!=1&&pre!=n-1) return 0;   
	        pre=x;   
	    }   
	    if (x!=1) return 0;   
	    return 1;   
	}
	bool MR(ll n){   
	    if (n<=1) return 0;   
	    ll r=n-1,s=0;   
	    while (!(r&1)) r>>=1,s++;   
	    for (int i=0;i<9;i++){   
	        if (a[i]==n) return 1;   
	        if (!check(a[i],n,r,s)) return 0;   
	    }   
	    return 1;   
	}
	ll pol_rho(ll n,ll c){      
	    ll k=2,x=rand()%n,y=x,p=1;   
	    for (ll i=1;p==1;i++){   
	        x=(mul(x,x,n)+c)%n;   
	        p=y>x?y-x:x-y;   
	        p=__gcd(n,p);   
	        if (i==k) y=x,k+=k;   
	    }   
	    return p;   
	}  
	void solve(ll n){   
	    if (n==1) return;   
	    if (MR(n)){p[++tp]=par(n,n);return;}
	    ll t=n;   
	    while (t==n) t=pol_rho(n,rand()%(n-1));   
	    solve(t),solve(n/t);   
	}   
	void deal(){
		sort(p+1,p+tp+1);
		
		ll tp2=0;
		for(int i=1;i<=tp;++i)
			if(!tp2||p[i].first!=p[tp2].first)p[++tp2]=p[i];
			else p[tp2].second*=p[i].second;
		tp=tp2;
	}
}
ll exgcd(ll a,ll b,ll& x,ll &y){
	if(!b){
		x=1,y=0;
	} else exgcd(b,a%b,y,x),y-=a/b*x;
}
int T,ptr,vis[100100];
ll n,k,a[60][101000],mn[60],x,y;
map<ll,pair<vector<ll>,int> >st;
priority_queue<par,vector<par>,greater<par> >Q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		if(k==1){
			puts("NO");
			continue;
		}
		if(!st.count(k)){
			WXHAKIOI2019::tp=0;
			WXHAKIOI2019::solve(k);
			WXHAKIOI2019::deal();
			vector<ll>& v=st[k].first;
			for(int i=1;i<=WXHAKIOI2019::tp;++i)
				v.push_back(WXHAKIOI2019::p[i].first);//,printf("[%lld]",v.back());
			st[k].second=++ptr;
			if(v.size()>=3){
				mn[ptr]=*min_element(v.begin(),v.end());
				for(int i=0;i<mn[ptr];++i)a[ptr][i]=inf,vis[i]=0;
				a[ptr][0]=0,Q.push(par(0,0));
				while(Q.size()){
					par p=Q.top();Q.pop();
					if(vis[p.second])continue;
					vis[p.second]=1;
					for(auto x:v){
						int nxt=(p.second+x)%mn[ptr];
						if(a[ptr][nxt]<=a[ptr][p.second]+x)continue;
						Q.push(par(a[ptr][nxt]=a[ptr][p.second]+x,nxt));
					}
				}
			}
		}
		vector<ll>& v=st[k].first;
		int fff=st[k].second;
		if(v.size()==1){
			if(n%v[0]==0)puts("YES");
			else puts("NO");
		} else if(v.size()==2){
			ll x,y;
			if(n<0){
				puts("NO");
				continue;
			}
			ll t=WXHAKIOI2019::qpow(v[1],v[0]-2,v[0]);
			ll b=(ll)(n%v[0])*t%v[0];
			if(n>=b*v[1])puts("YES");
			else puts("NO");
		} else {
//			for(auto x:v)n-=x;
			if(n<0)puts("NO");
			else if(n>=a[fff][n%mn[fff]])puts("YES");
			else puts("NO");
		}
	}
}